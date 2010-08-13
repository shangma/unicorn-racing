/*********************************************
 * Interrupt-service-rutiner
 *********************************************/

#include <config.h>
#include <extern.h>
#include <prototyper.h>
#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>

// ADC
unsigned int ADCconv = 0;
unsigned int pos = 0;
unsigned int current = 0;
unsigned int overCurrentCounter = 0;
char setChannel = 0;
unsigned short int maxTilNeutral = 0; 
unsigned short int minTilNeutral = 0;

// PWM
unsigned short int pwmValue = 140;

// Gear
volatile unsigned short int gearRetning = 0;

// Temp Var
char tempchar[5];

// ADC convert complete
ISR(ADC_vect)
{
	unsigned int adlow = 0;
	unsigned int adhigh = 0;
	char channel = 0;
		
	// Read ADC channel
	channel = ADMUX & 0x07;

	// Read ADC convertion
    adlow=ADCL;
    adhigh=ADCH;
	ADCconv = (unsigned int)((adhigh<<8)|(adlow & 0xFF));

	// Channel 0 = Pos ADC convert
	if(channel == 0)
	{
		pos = ADCconv;
/*
		itoa(pos-GearPosMiddle, tempchar,10);
		sendtekst(tempchar);
		sendtekst(";");
		itoa(pos, tempchar,10);
		sendtekst(tempchar);
		sendtekst(";");
*/
	}

	if(channel == 1)
	{
		current = ADCconv;
/*
		itoa(current, tempchar,10);
		sendtekst(tempchar);
		sendtekst(";");
		itoa(maxTilNeutral, tempchar,10);
		sendtekst(tempchar);
		sendtekst(";");
		itoa(minTilNeutral, tempchar,10);
		sendtekst(tempchar);
		sendtekst(";");
		itoa(overCurrentCounter, tempchar,10);
		sendtekst(tempchar);
		sendtekst("\n\r");
*/
		// OverCurrent sensor
		if(current>100)
		{
			overCurrentCounter++;
			if(overCurrentCounter>70)
				overCurrentCounter = 70;
		}
		else if(current>150)
		{
			overCurrentCounter = 70;
		}
		if((current <= 100) && (overCurrentCounter>0))
			overCurrentCounter--;

		if(overCurrentCounter>=70) // 70 = ~ 0.5 sec
		{
			hbroEnable(0);
		}
		if(overCurrentCounter<20)
			hbroEnable(1);
	}
}

 // UART interrupt
ISR(USART0_RX_vect)
{
	char data;
	data = UDR0;	// Lægger data fra seriel bufffer i variabel 

	if(data == 'a')
		softwareTrig;
}

// Timer0 (8-bit) overflow interrupt, ADC convert trigger
ISR(TIMER0_OVF_vect)
{	
	// Change ADC channel
	ADMUX &= 0xf8;
	ADMUX |= setChannel++;
	// Start ADC-convert
	ADCSRA|=(1<<ADSC);
	
	if(setChannel>=ADCtotnum)
		setChannel = 0;

	// Til Neutral fra max
	if((maxTilNeutral == 1) && (pos>(GearPosMiddle+GearMiddleDeadZone)	))
	{
		motorControl(CCW, pwmValue, pos);
	}
	else if((maxTilNeutral == 1) && (pos<=(GearPosMiddle+GearMiddleDeadZone)))
	{
		motorControl(0,0,0);
		minTilNeutral = 0;
		maxTilNeutral = 0;
	}

	// Til Neutral fra min
	if((minTilNeutral == 1) && (pos<(GearPosMiddle-GearMiddleDeadZone)))
	{
		motorControl(CW, pwmValue, pos);
	}
	else if((minTilNeutral == 1) && (pos>=(GearPosMiddle-GearMiddleDeadZone)))
	{
		motorControl(0,0,0);
		minTilNeutral = 0;
		maxTilNeutral = 0;
	}

	// Gear Pos max/min stop
	if(pos > GearPosMax)
	{
		AOFF;
		maxTilNeutral = 1;
		minTilNeutral = 0;
	}
	else if(pos < GearPosMin)
	{
		BOFF;
		minTilNeutral = 1;
		maxTilNeutral = 0;
	}
}

ISR(PCINT2_vect)
{

	itoa(gearRetning, tempchar,10);
	sendtekst(tempchar);

	if((gearRetning == GEAROP) && ((minTilNeutral+maxTilNeutral)==0))
	{
		gearRetning = 0;
		motorControl(CW, pwmValue, pos);
	}

	if((gearRetning == GEARNED) && ((minTilNeutral+maxTilNeutral)==0))
	{
		gearRetning = 0;
		motorControl(CCW, pwmValue, pos);
	}

}
