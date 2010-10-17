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
#include "sdcard/ff.h"
#include "sdcard/diskio.h"
#include "sdcard/rtc.h"
#include "can_std/can_lib.h"
#include "can_func.h"
#include "../lib/can_defs.h"
#include "ecu.h"
#include "comm.h"
#include "error.h"
#include "adc.h"

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
	OCR2A = 90-1;      // Timer2: 100Hz interval (OC2)
	TCCR2A = 0b00001101;
	TIMSK2 = 0b00000010;   // Enable TC2.oc interrupt

	/* Timer 0 bruges til at sende data req til ECU */
	OCR0A = 100;			// Sæt start værdi
	TCCR0A |= 1<<CS02 | 1<<CS00;    // prescaler til 1024
	TIMSK0 |= 1<<OCIE0A; 		// Slår timer compare match interrupt til

	rtc_init();         // Initialize RTC
	can_init(0);
	uart_init();
	
	// ADC
	DDRF = 0x00;

	// ADC 3,7 pull-up
	PORTF|= (1<<PF3);
	PORTF|= (1<<PF7);
}

void list_files_test( DIR *dir )
{
	BYTE res;
	DWORD p1, p2;
	UINT s1, s2;
	UINT maxname=0;
#if _USE_LFN
	Finfo.lfname = Lfname;
	Finfo.lfsize = sizeof(Lfname);
#endif
	for(;;) {
		res = f_readdir(dir, &Finfo);
		if ((res != FR_OK) || !Finfo.fname[0]) break;
		if (Finfo.fattrib & AM_DIR) {
			s2++;
		} else {
			s1++; p1 += Finfo.fsize;
		}
		xprintf(PSTR("%s\n"), &(Finfo.fname[0]));
		if ( atoi(&(Finfo.fname[0])) > maxname )
			maxname = atoi(&(Finfo.fname[0]));
/*			xprintf(PSTR("%c%c%c%c%c %u/%02u/%02u %02u:%02u %9lu  %s"), */
/*			(Finfo.fattrib & AM_DIR) ? 'D' : '-',*/
/*			(Finfo.fattrib & AM_RDO) ? 'R' : '-',*/
/*			(Finfo.fattrib & AM_HID) ? 'H' : '-',*/
/*			(Finfo.fattrib & AM_SYS) ? 'S' : '-',*/
/*			(Finfo.fattrib & AM_ARC) ? 'A' : '-',*/
/*			(Finfo.fdate >> 9) + 1980, (Finfo.fdate >> 5) & 15, Finfo.fdate & 31,*/
/*			(Finfo.ftime >> 11), (Finfo.ftime >> 5) & 63,*/
/*			Finfo.fsize, &(Finfo.fname[0]));*/
/*#if _USE_LFN*/
/*			for (p2 = strlen(Finfo.fname); p2 < 14; p2++)*/
/*				xputc(' ');*/
/*			xprintf(PSTR("%s\n"), Lfname);*/
/*#else*/
/*			xputc('\n');*/
/*#endif*/
	}
	xprintf(PSTR("%d\n"), maxname);
}

int get_free_log_number( DIR *dir )
{
	BYTE res;
	DWORD p1, p2;
	UINT s1, s2;
	UINT maxname=0;
#if _USE_LFN
	Finfo.lfname = Lfname;
	Finfo.lfsize = sizeof(Lfname);
#endif
	for(;;) {
		res = f_readdir(dir, &Finfo);
		if ((res != FR_OK) || !Finfo.fname[0]) break;
		if (Finfo.fattrib & AM_DIR) {
			s2++;
		} else {
			s1++; p1 += Finfo.fsize;
		}
		xprintf(PSTR("%s\n"), &(Finfo.fname[0]));
		if ( atoi(&(Finfo.fname[0])) > maxname )
			maxname = atoi(&(Finfo.fname[0]));
/*			xprintf(PSTR("%c%c%c%c%c %u/%02u/%02u %02u:%02u %9lu  %s"), */
/*			(Finfo.fattrib & AM_DIR) ? 'D' : '-',*/
/*			(Finfo.fattrib & AM_RDO) ? 'R' : '-',*/
/*			(Finfo.fattrib & AM_HID) ? 'H' : '-',*/
/*			(Finfo.fattrib & AM_SYS) ? 'S' : '-',*/
/*			(Finfo.fattrib & AM_ARC) ? 'A' : '-',*/
/*			(Finfo.fdate >> 9) + 1980, (Finfo.fdate >> 5) & 15, Finfo.fdate & 31,*/
/*			(Finfo.ftime >> 11), (Finfo.ftime >> 5) & 63,*/
/*			Finfo.fsize, &(Finfo.fname[0]));*/
/*#if _USE_LFN*/
/*			for (p2 = strlen(Finfo.fname); p2 < 14; p2++)*/
/*				xputc(' ');*/
/*			xprintf(PSTR("%s\n"), Lfname);*/
/*#else*/
/*			xputc('\n');*/
/*#endif*/
	}
	xprintf(PSTR("%d\n"), maxname);
	return maxname + 1;
}

/*-----------------------------------------------------------------------*/
/* Main                                                                  */


int main (void)
{
	FATFS *fs;
	FIL file1;			/* File object */
	DIR dir;
	U8 i;
	int tmp=0;
	int tmp2=0;
	int rpm=0;
	int speed=0;
	int ratio = 0;
	int water_temp = 0;
	int water2_temp = 0;
	char e;
	char test[] = "test1234test";
	int freelognumber;
	char filename[10]; 

	IoInit();

	/* Join xitoa module to uart module */
	xfunc_out = (void (*)(char))uart_put;

	_delay_ms(1000);

	xprintf(PSTR("System startet\n"));
	xprintf(PSTR("Initialize disk 0\n"));    
	xprintf(PSTR("rc=%d\n"), (WORD)disk_initialize(0));
	xprintf(PSTR("Initialize logical drice 0\n"));
	xprintf(PSTR("rc=%d\n"), (WORD)f_mount(0, &Fatfs[0]));
	xprintf(PSTR("Opening file hej\n"));
	xprintf(PSTR("rc=%d\n"), (WORD)f_open(&file1, "hej",FA_WRITE));
	_delay_ms(1000);
	init_can_data_mobs();

	for (i=0; i<num_of_response_mobs; i++) {
		can_data_mob_setup(i);
	}
	tx_remote_msg.pt_data = &tx_remote_buffer[0];
	tx_remote_msg.status = 0;

	can_send(rpm_msgid, 8, 1);
	sei();

	while(1) {
		xprintf(PSTR("open dir \n")); 
		xprintf(PSTR("rc=%d\n"), f_opendir(&dir, "0:"));
		freelognumber = get_free_log_number(&dir);
		xprintf(PSTR("Free log nr %d\n"), freelognumber);
		itoa(freelognumber, filename, 10);
		xprintf(PSTR("Opening file %s\n"), filename);
		xprintf(PSTR("rc=%d\n"), (WORD)f_open(&file1, filename, FA_CREATE_NEW));
		_delay_ms(3000);
		f_close(&file1);
		xprintf(PSTR("hehe"));
/*		for (i=0; i<30; i++) {*/
/*			f_write(&file1, test, 12, e);*/
/*			xprintf(PSTR("a"));*/
/*			_delay_ms(50);*/
/*		}*/
/*		f_close(&file1);*/
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
