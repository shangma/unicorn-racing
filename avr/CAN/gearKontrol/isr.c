/*********************************************
 * Interrupt-service-rutiner
 *********************************************/

#include <config.h>
#include <extern.h>
#include <prototyper.h>
#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include <math.h>

// ADC
unsigned int ADCconv = 0;
char setChannel = 0;

// Temp Var
char count = 200;
char retning = 0;
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
		gearPosController(ADCconv);
		//itoa(ADCconv, tempchar,10);
		//sendtekst(tempchar);
		//sendtekst("\n\r");
	}
}

 // UART interrupt
ISR(USART0_RX_vect)
{
	char data;
	char tempchar[5];	
	data = UDR0;	// Lægger data fra seriel bufffer i variabel 

    if(data == '8')
    {
		gearPosRef = (GearPosMax-GearPosMin);
	}

    if(data == '5')
    {
		gearPosRef = (GearPosMiddle-GearPosMin);
	}

    if(data == '2')
    {
		gearPosRef = 0;
	}

    if(data == 'w')
    {
		gearPosRef++;
	}

    if(data == 's')
    {
		gearPosRef--;
	}

    if(data == 'p')
    {
		Kp++;
	}
    if(data == 'l')
    {
		Kp--;
	}

/*
	itoa(gearPosRef, tempchar,10);
	sendtekst(tempchar);
	sendtekst(" ; ");
	itoa(ADCconv, tempchar,10);
	sendtekst(tempchar);
	sendtekst(" ; ");
	itoa(PORTA, tempchar,2);
	sendtekst(tempchar);
	sendtekst("\n\r");

*/
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
}
