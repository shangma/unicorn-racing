#include "config.h"
#include "adc.h"

ADCReadObject ADCReadObjects[] = {	{Temp1, 100, 100, 0}, 
					{Temp2,500, 500, 0}, 
					{Temp3, 700, 700, 0}};	

/* Timer1 overflow interrupt used for adc read function */
ISR (TIMER1_OVF_vect)
{
	/* TODO Disable timer interrupt */
	
	/* TODO count all timeout down */

	/* TODO start conversion for items with timeout at zero or less */

	/* TODO remove items with timeout at zero or less and put them back into
	 *	queue at the correct place 
	*/

	/* TODO Load timer with value of timeout for the first item in the queue 
	*/

	/* TODO Enable timer interrupt */
}

/* ADC conversion done interrupt */
ISR (ADC_vect)
{
	/* TODO
	 * Figure out some way to to arrange data from the conversion in
	 * accordans with the can data packaged definitions. 
	 * Need some way to describe the relation between ADCReadObjects
	 * and can data packeges  
	*/  
}


void AdcReadStart(void)
{
	int i;
	ADCReadObject *P1;

	SET_ADC_TIMER_PRESCALER;	/* Start timer 1 but no interrup yet */

	/* Search for ADCReadObject with lowest interval
	 * to make it first in list */
	QH = &ADCReadObjects[0];
	P1 = QH;
	for (i=1; i<NumOfSensors; i++){
		P1->next = &ADCReadObjects[i];
		P1 = P1->next;
	}
	/* Load timer with interval for object first in list */ 
	SetTimer(100);	/* timer interrupt funktion starter efter 100 ms */
	ADC_TIMER_TOIE;	/* Enable interrupt for timer */
}


void SetTimer(uint16_t val)
{
	int ticks;
	
	ticks = val*TICKS_PER_MS;	/* Calculate number of ticks
					 * before timer interrupt */
	ticks = ADC_TIMER_MAX_VAL-ticks;	/* Calculate value for timer */
	TCNT1 = ticks;				/* Load timer with value */	
}
