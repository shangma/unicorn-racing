/*********************************************
 * Functions
 *********************************************/

#include <config.h>
#include <prototyper.h>
#include <extern.h>
#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>

void PWM_duty_cycle_A_set(unsigned int x)
{
	OCR2A = x; 
}

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
		while ((UCSR0A & (1 << UDRE0)) == 0) {};
		UDR0 = tekstarray[i];
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

void motorControl(unsigned short int ret, unsigned short int speed, unsigned int pos)
{
	if((ret==CW) && (pos<GearPosMax) && (speed>0))
	{
		BOFF;
		AON;		
	}
	else if((ret==CCW) && (pos>GearPosMin) && (speed>0))
	{
		AOFF;
		BON;
	}
	else
	{
		AON;
		BON;
	}

	PWM_duty_cycle_A_set(speed);
}