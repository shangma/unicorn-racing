#include "integer.h"

#ifndef _ADC
#define _ADC 1

/* Used for timer */
#define ADC_TIMER_RES 		16		/* Timer is 16 bit resolution */
#define ADC_TIMER_MAX_VAL	65536		/* 2^16 */
#define ADC_TIMER_PRESCALER 	5		/* 1024 */
#define TICKS_PER_MS 		10.8		/* (F_CPU/prescaler)*10^-3 */
#define PRESCALER_MASK 		0xF8

#define SET_ADC_TIMER_PRESCALER		TCCR1B |= ADC_TIMER_PRESCALER
#define ADC_TIMER_TOIE			TIMSK1 |= 1<<TOIE1			
#define ADC_TIMER_TOID			TIMSK1 &= ~(1<<TOIE1)

typedef struct ADCReadObject_{
	uint8_t adc;		/* ADC input pin (0-7) */
	int interval;	/* Sampling rate = 1/(interval*10^-3) */
	int timeout;
	struct ADCReadObject_* next;
}ADCReadObject;

ADCReadObject *QH, *QT;		/* Pointers to queue head and tail */

enum Sensor {
	Temp1,
	Temp2,
	Temp3,
	NumOfSensors
};

/* Function to init list and start reading values from adc */
void AdcReadStart(void);


/* This function take the first item in the queue and reload it's timeout with
 * interval and put it into the queue again at the right place */
int ReloadQueue(void);

/* Function to set timer value based on wanted time (in ms) to next timer interrupt */ 
void SetTimer(uint16_t TimeToInt);

/* Function to count down timeout for all items in queue by QH->timeout */
void CountDown(void);

#endif // _ADC
