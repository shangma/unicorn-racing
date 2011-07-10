/*********************************************
 * Hardware init
 *********************************************/

#include "config.h"
#include "extern.h"
#include "prototyper.h"
#include <avr/io.h>
#include <avr/interrupt.h>

/*************************************************
* Timer
*
* Counter0  (8-bit): Timer til ADC konvertering
* Counter1 (16-bit): -
* Counter2  (8-bit): Timer til gear motor PWM
*************************************************/

void ioinit(void)
{
	DDRA|= (1<<PA0);	// Retning A set
	DDRA|= (1<<PA1);	// Retning B set
	DDRA|= (1<<PA2);	// Retning A Enable
	DDRA|= (1<<PA3);	// Retning B Enalbe
		
	DDRB|= (1<<PB5);	// PWM til gearMotor

	DDRF &=~(1<<PF1);	// Position sense
	DDRF &=~(1<<PF0);	// CS (Current Sense !)

	// Hbro Disable (h-bro slukkes ved start)
	PORTA &=~ (1<<PA0);	
	PORTA &=~ (1<<PA1);	
	PORTA &=~ (1<<PA2);	
	PORTA &=~ (1<<PA3);	

	// PCINT (og led)
	//DDRC|= (1<<PC7);
/*
	//LED
	DDRC|= (1<<PC0);
	DDRC|= (1<<PC1);
	DDRC|= (1<<PC2);

	// Ign cut
	DDRC|= (1<<PC3);

	// GearKontakter
	DDRB&=~(1<<PB0);
	DDRB&=~(1<<PB1);
	DDRB&=~(1<<PB2);
	PORTB |= (1<<PB0); // Pull-up
	PORTB |= (1<<PB1); // Pull-up
	PORTB |= (1<<PB2); // Pull-up
*/
}

void uartinit(void)
{
	//Enable TXen og RXen
	UCSR1B = (1<<RXEN1)|(1<<TXEN1); 
	
	// Format: 8data, 1 stop bit
	UCSR1C = (3<<UCSZ10);

	// Baud rate
	UBRR1L = BAUD_PRESCALE;
	UBRR1H = (BAUD_PRESCALE >> 8);
	
	// Rx Uart interrupt (Receive Complete Interrupt)
	UCSR1B|=(1<<RXCIE1);

	// Tx Uart interrupt (Transmit Complete Interrupt)
	//UCSR0B|=(1<<TXCIE0);
}
/*
void pwm8Init(void)
{
	// (OC2A) Output
	DDRD|= (1<<PD7);      

	// Opsætning af compare match.
	TCCR2A |=(1<<COM2A1);
	TCCR2A &=~(1<<COM2A0);

	// FAST-PWM
	TCCR2A |=(1<<WGM20);
	TCCR2A |=(1<<WGM21);

	// Prescaler
    TCCR2B |=(1<<CS20); // 2.2 kHz
	TCCR2B |=(1<<CS21);

	PWM_duty_cycle_A_set(0);
}
*/
void pwm16Init(void)
{
	//PWM, 16 bit counter (counter1)
	// (OC1A) Output
    DDRB|= (1<<PB5);  
     
	// Opsætning af compare match.
	TCCR1A |=(1<<COM1A1);
	TCCR1A &=~(1<<COM1A0);

	// FAST-PWM TOP = ICRn
	TCCR1A &=~(1<<WGM10);
	TCCR1A |=(1<<WGM11);
	TCCR1B |=(1<<WGM12);
	TCCR1B |=(1<<WGM13);

	//Top (11-bit)
	ICR1H = 0x07;
	ICR1L = 0xFF;

	// Prescaler, 64
    TCCR1B &=~(1<<CS10);
	TCCR1B |=(1<<CS11); 
	TCCR1B &=~(1<<CS12); 
/*
	// Compare match værdi
	PWM_duty_cycle_A16_set(0);
*/	
}

void counter0Init(void)
{
	TCCR0A |= counter0prescale1024;
	TIMSK0 |=(1<<TOIE0);
}

void adcInit(unsigned int channel)
{
	// ADC channel
	ADMUX=(channel & 0x0f);

	// Vref config
	ADMUX |=(1<<REFS0); 
	ADMUX &=~(1<<REFS1);

	// ADC ENABLE
	ADCSRA |=(1<<ADEN); 

	// ADC frequency prescaler
	ADCSRA |=(1<<ADPS0);
	ADCSRA |=(1<<ADPS1);
	ADCSRA |=(1<<ADPS2);

	/* ADC Tigger mode
	ADCSRA |=(1<<ADATE); 

	// ADC trigger source
	ADCSRB &=~(1<<ADTS0); 
	ADCSRB &=~(1<<ADTS1);
	ADCSRB |=(1<<ADTS2);
	*/	

	// ADC interrupt enable
	ADCSRA |=(1<<ADIE);
}
/*
void pcintInit(void)
{
	// PCINT2 Enable
	PCICR |=(1<<PCIE2);

	// PCMSK2 pin trigger
	PCMSK2 = 0b10000000;
}
*/
