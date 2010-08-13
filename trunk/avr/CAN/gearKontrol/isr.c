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
	}
	// Channel 1 = Current ADC convert
	if(channel == 1)
	{
		current = ADCconv;
	}
}

 // UART0 interrupt
ISR(USART0_RX_vect)
{
	char data;
	data = UDR0;

	if(data == 'a')
		softwareTrig;
}

// Timer0 (8-bit) overflow interrupt
ISR(TIMER0_OVF_vect)
{	
	//______________________ADC_______________________________________________
	// Change ADC channel
	ADMUX &= 0xf8;
	ADMUX |= setChannel++;
	// Start ADC-convert
	ADCSRA|=(1<<ADSC);
	
	if(setChannel>=ADCtotnum)
		setChannel = 0;

	//______________________OverCurrent sensor (force)________________________
	
	/*
	Dette laves om sa PWM styres af controller for at holde konstant moment
	Dog skal det stadig tjekkes om den sidder helt fast
	Ved en graense skifter den retning, for at se om den kan komme fri der.
	Hvis dette ikke hjaelper kommer den over en anden graense, som stopper den
	helt. Dette kunne fx vaere ved 1 og 2 sek.
	*/
	if(current>GEARFORCE)
	{
		overCurrentCounter++;
		if(overCurrentCounter>70)
			overCurrentCounter = 70;
	}
	else if(current>150)
	{
		overCurrentCounter = 70;
	}
	if((current <= GEARFORCE) && (overCurrentCounter>0))
		overCurrentCounter--;

	if(overCurrentCounter>=70) // 70 = ~ 0.5 sec
	{
		hbroEnable(0);
	}
	if(overCurrentCounter<20)
		hbroEnable(1);

	//______________________Aktuator_Moment_Regulering________________________
	/*
	Regulator til regulering af motor pwm, sadan at en konstant kraft pa
	gearet opretholdes.
	*/

	// Constant torque controller
	//pwmValue = torqueController(current);

	//______________________Retur_fra_min/max_________________________________
	// Til Neutral fra max
	if((maxTilNeutral == 1) && (pos>(GearPosMiddle+GearMiddleDeadZone)))
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

	//______________________Stop_hvis_over_min/max,_set_retur_________________
	if((pos > GearPosMax) && ((minTilNeutral+maxTilNeutral)==0))
	{
		AOFF;
		maxTilNeutral = 1;
		minTilNeutral = 0;
	}
	else if((pos < GearPosMin) && ((minTilNeutral+maxTilNeutral)==0))
	{
		BOFF;
		minTilNeutral = 1;
		maxTilNeutral = 0;
	}
}

ISR(PCINT2_vect)
{
	// Gear op kontakt (tjekker at armen ikke er pa vej tilbage)
	if((gearRetning == GEAROP) && ((minTilNeutral+maxTilNeutral)==0))
	{
		gearRetning = 0;
		motorControl(CW, pwmValue, pos);
	}
	// Gear ned kontakt
	if((gearRetning == GEARNED) && ((minTilNeutral+maxTilNeutral)==0))
	{
		gearRetning = 0;
		motorControl(CCW, pwmValue, pos);
	}
}
