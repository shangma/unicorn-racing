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
#include "uart.h"
#include "xitoa.h"
#include "sdcard_fs_driver/ff.h"
#include "sdcard_fs_driver/diskio.h"
#include "sdcard_fs_driver/rtc.h"
#include "can_std/can_lib.h"
#include "can_func.h"
#include "../lib/can_defs.h"
#include "ecu.h"
#include "comm.h"
#include "error.h"

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
//	OCR2A = 90-1;      // Timer2: 100Hz interval (OC2)
//	TCCR2A = 0b00001101;
//	TIMSK2 = 0b00000010;   // Enable TC2.oc interrupt

	/* Timer 0 bruges til at sende data req til ECU */
	OCR0A = 100;			// Sæt start værdi
	TCCR0A |= 1<<CS02 | 1<<CS00;    // prescaler til 1024
	TIMSK0 |= 1<<OCIE0A; 		// Slår timer compare match interrupt til

	rtc_init();         // Initialize RTC
	can_init(0);
	uart_init();
}

/*-----------------------------------------------------------------------*/
/* Main                                                                  */
int main (void)
{
	FATFS *fs;
	FIL file1;			/* File object */
	IoInit();

	/* Join xitoa module to uart module */
	xfunc_out = (void (*)(char))uart_put;


	xprintf(PSTR("System startet\n"));
	xprintf(PSTR("Initialize disk 0\n"));    
	xprintf(PSTR("rc=%d\n"), (WORD)disk_initialize(0));
	xprintf(PSTR("Initialize logical drice 0\n"));
	xprintf(PSTR("rc=%d\n"), (WORD)f_mount(0, &Fatfs[0]));	
	xprintf(PSTR("Opening file hej\n"));
	xprintf(PSTR("rc=%d\n"), (WORD)f_open(&file1, "hej",FA_WRITE)); 

    	_delay_ms(1000);
	sei();

	while(1) {	
		_delay_ms(50);
	}
}


/* eksempel kode til at vise hvordan end besked modtaget fra can skrives til sdcard */
void can(FIL *file)
{
    U8 i,j;
    char e;

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
