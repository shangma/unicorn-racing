/*********************************************
 * Interrupt-service-rutiner
 *********************************************/

#include "config.h"
#include "extern.h"
#include "prototyper.h"
#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// ADC
unsigned int ADCconv = 0;
unsigned int pos = 0;
unsigned int posOld = 0;
unsigned int current = 0;
unsigned int currentOld = 0;
char setChannel = 0;
char channel = 0;

// PWM
unsigned int pwm = 0;
unsigned int pwmOut = 0;
unsigned int pwmOld = 0;

// Gear
unsigned short int gearRetning = 0;

// Debugging
char tempchar[10];

// ADC convert complete
ISR(ADC_vect,ISR_NOBLOCK)
{
	unsigned int adlow = 0;
	unsigned int adhigh = 0;
		
	// Read ADC channel
	channel = ADMUX & 0x07;

	// Read ADC convertion
    adlow=ADCL;
    adhigh=ADCH;
	ADCconv = (unsigned int)((adhigh<<8)|(adlow & 0xFF));

	// Current sense
	
	if(channel == 0)
	{
		current = (int)((double)FILTERKONSTANTCURRENT*ADCconv+(double)(1-FILTERKONSTANTCURRENT)*currentOld);
		currentOld = current;
	}

	// Channel 1 = Pos ADC convert
	if(channel == 1)
	{
		// Pos lav pass filter (for at undga at stoj oedelaegger skiftet)
		pos = (int)((double)FILTERKONSTANTPOS*ADCconv+(double)(1-FILTERKONSTANTPOS)*posOld);
		posOld = pos;
	}
}

 // UART0 interrupt
ISR(USART1_RX_vect)
{
	char data;
	data = UDR0;

	if(data == 'w')
	{
		sendtekst("w");
	}

	if(data == 's')
	{
		sendtekst("s");
	}
}

// Timer0 (8-bit) overflow interrupt
ISR(TIMER0_OVF_vect)
{	
	// ADC
	// Change ADC channel
	ADMUX &= 0xf8;
	ADMUX |= setChannel++;
	//ADMUX |= 1;
	// Start ADC-convert
	ADCSRA|=(1<<ADSC);

	if(setChannel>=ADCtotnum)
		setChannel = 0;

	// Force Control
	//pwm = torqueController(current);
	pwm = DUTYMAX;

	// PWM lav pass filter
	pwmOut = (unsigned int)((double)FILTERKONSTANTPWM*pwm+(double)(1-FILTERKONSTANTPWM)*pwmOld);
	pwmOld = pwmOut;

	sendtekst("PWM: ");
	itoa(pwmOut,tempchar,10);
	sendtekst(tempchar);
	sendtekst("  ");

	sendtekst("POS: ");
	itoa(pos,tempchar,10);
	sendtekst(tempchar);
	sendtekst("\n\r");


	// POS
	if(pos>900)
	{
		motorControl(IND, (unsigned int) pwmOut);

		// Hvis retningen lige er skiftet
		if(gearRetning == UD)
			pwmOld = 0; // Soft start

		gearRetning = IND;
	}

	if(pos<300)
	{
		motorControl(UD, (unsigned int) pwmOut);

		// HVis retningen lige er skiftet
		if(gearRetning == IND)
			pwmOld = 0; // Soft start

		gearRetning = UD;
	}
}
