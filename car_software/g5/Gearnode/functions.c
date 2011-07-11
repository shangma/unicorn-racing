/*********************************************
 * Functions
 *********************************************/

#include "config.h"
#include "extern.h"
#include "prototyper.h"
#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>


void PWM_duty_cycle_A16_set(unsigned int x)
{
	OCR1AH = (0xFF) & (x>>8);
	OCR1AL = (0xFF) & (x); 
}

void adcStop(void)
{
	ADCSRA &=~(1<<ADEN); // ADC prescaler disable
}

void sendtekst(char *tekstarray)
{
	short int i;
	for (i = 0; tekstarray[i] != '\0'; i++)
	{	
		while ((UCSR1A & (1 << UDRE1)) == 0) {};
		UDR1 = tekstarray[i];
	}
}

void hbroEnable(unsigned short int enable)
{
	if(enable == 1)
	{
		AENA; // Retning A Enable
		BENA; // Retning B Enable
	}
	else
	{
		ADIS; // Retning A Disable
		BDIS; // Retning B Disable
	}
}

void motorControl(unsigned short int ret, unsigned int speed)
{

	PWM_duty_cycle_A16_set(speed);

	if((ret==CW) && (speed>0))
	{
		BOF;
		AON;		
	}
	else if((ret==CCW) && (speed>0))
	{
		AOF;
		BON;
	}
	else if((ret!=0) && (speed<=0))
	{
		AOF;
		BOF;
	}
	else
	{
		AOF;
		BOF;
	}
	
}
