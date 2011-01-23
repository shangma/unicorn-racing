#include "integer.h"

typedef struct ADCReadObject_{
	uint8_t adc;		/* ADC input pin (0-7) */
	uint16_t interval;	/* Sampling rate = 1/(interval*10^-3) */
	uint16_t timeout;
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

/* Function to set timer value based on wanted time to next timer interrupt */ 
void SetTimer(uint16_t TimeToInt);
