/*----------------------------------------------------------------------*/
/* FAT file system sample project for FatFs            (C)ChaN, 2009    */
/*----------------------------------------------------------------------*/

#include "config.h"
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <string.h>
#include <stdlib.h>
#include <util/delay.h>
#include <util/twi.h>
#include "uart.h"
#include "xitoa.h"
#include "sdcard_fs_driver/ff.h"
#include "sdcard_fs_driver/diskio.h"
#include "sdcard_fs_driver/rtc.h"
#include "twi/twi.h"
#include "can_std/can_lib.h"
#include "can_func.h"
#include "../lib/can_defs.h"
#include "ecu.h"
#include "comm.h"
#include "error.h"
#include "log.h"

#define NB_TARGET 1
#define ID_TAG_BASE 128

void can(FIL *file_to_log);

DWORD acc_size;				/* Work register for fs command */
WORD acc_files, acc_dirs;
FILINFO Finfo;
#if _USE_LFN
char Lfname[_MAX_LFN+1];
#endif


FATFS Fatfs[1];				/* File system object for each logical drive */
BYTE Buff[1024];			/* Working buffer */

volatile WORD Timer;		/* 100Hz increment timer */

#if _MULTI_PARTITION != 0
const PARTITION Drives[] = { {0,0}, {0,1} };
#endif

/*---------------------------------------------------------*/
/* 100Hz timer interrupt generated by OC2                  */
/*---------------------------------------------------------*/

ISR(TIMER2_COMP_vect)
{
	Timer++;			/* Performance counter for this module */
	disk_timerproc();	/* Drive timer procedure of low level disk I/O module */
}

/*---------------------------------------------------------*/
/* User Provided Timer Function for FatFs module           */
/*---------------------------------------------------------*/
/* This is a real time clock service to be called from     */
/* FatFs module. Any valid time must be returned even if   */
/* the system does not support a real time clock.          */
/* This is not required in read-only configuration.        */

DWORD get_fattime ()
{
	RTC rtc;

	/* Get local time */
	rtc_gettime(&rtc);

	/* Pack date and time into a DWORD variable */
	return	  ((DWORD)(rtc.year - 1980) << 25)
			| ((DWORD)rtc.month << 21)
			| ((DWORD)rtc.mday << 16)
			| ((DWORD)rtc.hour << 11)
			| ((DWORD)rtc.min << 5)
			| ((DWORD)rtc.sec >> 1);
}

static
void IoInit ()
{
	/* Timer2 used for filesystem functions */
	OCR2A = 90-1;      // Timer2: 100Hz interval (OC2)
	TCCR2A = 0b00001101;
	TIMSK2 = 0b00000010;   // Enable TC2.oc interrupt

	/* Timer0 bruges til at sende data req til ECU */
	OCR0A = 100;			// Sæt start værdi
	TCCR0A |= 1<<CS02 | 1<<CS00;    // prescaler til 1024
	TIMSK0 |= 1<<OCIE0A; 		// Slår timer compare match interrupt til

	rtc_init();         // Initialize RTC
	can_init(0);		/* Initialize can controllor */
	uart_init();		/* Initialize uart 0 and 1 for ecu and xbee */
}

/*-----------------------------------------------------------------------*/
/* Main                                                                  */
int main (void)
{
	FATFS *fs;
	FIL file1;			/* File object */
	DIR dir;			/* Dir object */
	int freelognumber;		/* Free log number */
	char filename[10]; 		/* Free log number as a string */

	/* vars to test rtc code */
	uint8_t buffer[10];
	BOOL res;
	RTC rtc;

	/* Can test vars */
	U8 canData[8];
	int i;
	// Recieve buffer
	U8 rpm_response_buffer[8];
	st_cmd_t rpm_msg;
	
	TWI_init();	/* Init TWI interface */
	IoInit();

	/* Join xitoa module to uart module */
	xfunc_out = (void (*)(char))uart_put;		/* xprintf writes to uart connected to the xbee */

	_delay_ms(500);
	xprintf(PSTR("System startet\n"));
	xprintf(PSTR("Initialize disk 0\n"));
	xprintf(PSTR("rc=%d\n"), (WORD)disk_initialize(0));		/* initialize filesystem */
	xprintf(PSTR("Initialize logical drice 0\n"));	
	xprintf(PSTR("rc=%d\n"), (WORD)f_mount(0, &Fatfs[0]));		/* mount filesystem */
	xprintf(PSTR("open dir \n")); 
	xprintf(PSTR("rc=%d\n"), f_opendir(&dir, "0:"));	/* open root dir on fs */
	freelognumber = get_free_log_number(&dir);		/* Get lowest free log number */
	xprintf(PSTR("Free log nr %d\n"), freelognumber);
	itoa(freelognumber, filename, 10);			/* Convert to string for use in f_open() */
	xprintf(PSTR("Opening file %s\n"), filename);
	xprintf(PSTR("rc=%d\n"), (WORD)f_open(&file1, filename, FA_CREATE_NEW | FA_WRITE));	/* Create new logfile for writing */
	f_sync(&file1);			/* Sync filesystem to write changes to disk */
	_delay_ms(1000);

	/*
	 *	Kode til hurtig test af can 
	 */
	rpm_msg.pt_data = rpm_response_buffer;
	rpm_msg.status = 0;

	can_update_rx_msg(&rpm_msg, rpm_msgid, 8);

	sei();				/* Enable interrupt */

	while(1) {
		// check for rpm_msg
		if (can_get_status(&rpm_msg) == CAN_STATUS_COMPLETED) {  
                    
			xprintf(PSTR("1 = %d, 2 = %d, 3 = %d, 4 = %d, 5=%d\n"), rpm_response_buffer[0], rpm_response_buffer[1], rpm_response_buffer[2], rpm_response_buffer[3], rpm_response_buffer[4]);
			can_update_rx_msg(&rpm_msg, rpm_msgid, 8);      // update rpm_msg to accept a new msg
			for (i=0;i<8;i++) {
				rpm_response_buffer[i] = 0;
			}		
		}
		_delay_ms(5);
/*		res = rtc_gettime(&rtc);*/
/*		xprintf(PSTR("%d-%d-%dT%d:%d:%d\n"), rtc.year, rtc.month, rtc.mday, rtc.hour, rtc.min, rtc.sec);*/
/*		_delay_ms(3000);*/
	}
}


/* eksempel kode til at vise hvordan end besked modtaget fra can skrives til sdcard */
void can(FIL *file)
{
    U8 i,j;
    int *e;

    for (j=0; j<num_of_response_mobs; j++){
        if (can_get_status(&response_msg[j]) == CAN_STATUS_COMPLETED){
            if (bufferindex >= data_buffer_num){
                xprintf(PSTR("Buffer full error\n"));
            } else {
                for (i=0; i<9; i++) {
                        databuffer[bufferindex][i] = response_buffer[j][i];
                        response_buffer[j][i] = 0;
                }
                bufferindex++;
            }
            can_data_mob_setup(i);
        }
    }

    for (i=0; i<bufferindex; i++) {         
        xprintf(PSTR("B %d"), i); 
        /*xprintf(PSTR(", Data1: %03d"), databuffer[i][0]);
	    xprintf(PSTR(", Data2: %03d"), databuffer[i][1]);
        xprintf(PSTR(", Data3: %03d"), databuffer[i][2]);
    	xprintf(PSTR(", Data4: %03d"), databuffer[i][3]);
        xprintf(PSTR(", Data5: %03d"), databuffer[i][4]);
        xprintf(PSTR(", Data6: %03d"), databuffer[i][5]);
	    xprintf(PSTR(", Data7: %03d"), databuffer[i][6]);                
    	xprintf(PSTR(", Data8: %03d"), databuffer[i][7]);
	    xprintf(PSTR("\r\n"));*/
    }
    if (f_write(file, databuffer, 9*bufferindex, e) != 0)
            xprintf(PSTR("Write error\r\n"));
    _delay_us(1700);
    bufferindex = 0;
}
