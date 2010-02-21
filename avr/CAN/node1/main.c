/*----------------------------------------------------------------------*/
/* FAT file system sample project for FatFs            (C)ChaN, 2009    */
/*----------------------------------------------------------------------*/

#include "config.h"
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <string.h>
#include <util/delay.h>
#include "uart.h"
#include "xitoa.h"
#include "ff.h"
#include "diskio.h"
#include "rtc.h"
#include "can_lib.h"

DWORD acc_size;				/* Work register for fs command */
WORD acc_files, acc_dirs;
FILINFO Finfo;
#if _USE_LFN
char Lfname[_MAX_LFN+1];
#endif


BYTE Line[120];				/* Console input buffer */

FATFS Fatfs[2];				/* File system object for each logical drive */
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

   rtc_init();         // Initialize RTC
   can_init(0);
   uart_init();
}


/*-----------------------------------------------------------------------*/
/* Main                                                                  */


int main (void)
{
	char *ptr, *ptr2;
	DWORD p1, p2, p3;
	BYTE res, b1;
	WORD w1;
	UINT s1, s2, cnt;
	DWORD ofs, sect = 0;
	RTC rtc;
	FATFS *fs;
	DIR dir;				/* Directory object */
	FIL file1, file2;			/* File object */
	int i=0;
    char d = 'A';
    char e;
    char data[] = "ddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd";

	IoInit();

    	uart_put(84);
	/* Join xitoa module to uart module */
	xfunc_out = (void (*)(char))uart1_put;
    _delay_ms(2000);
	xprintf(PSTR("System startet\n"));
        xprintf(PSTR("Initialize disk 0\n"));    
	    xprintf(PSTR("rc=%d\n"), (WORD)disk_initialize(0));
        xprintf(PSTR("Initialize logical drice 0\n"));
        xprintf(PSTR("rc=%d\n"), (WORD)f_mount(0, &Fatfs[0]));
        xprintf(PSTR("Opening file hej\n"));
        xprintf(PSTR("rc=%d\n"), (WORD)f_open(&file1, "hej",FA_WRITE)); 
    while(1) {
        while ((UCSR1A & (1 << RXC1)) == 0) {};
        d = UDR1;
        if (d == 'c') {
            xprintf(PSTR("\nCloseing file\n"));
            xprintf(PSTR("rc=%d\n"), (WORD)f_close(&file1));
        } else {
                if (f_write(&file1, data, 90, e) != 0) {
                    xprintf(PSTR("Error\n"));
                }
                xprintf(PSTR("a\n"));
        } 
        //uart1_put(d);
	}
}