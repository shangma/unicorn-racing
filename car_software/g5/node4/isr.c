/*********************************************
 * Interrupt-service-rutiner
 *********************************************/

#include "config.h"
#include "prototyper.h"
#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// Wheel speed
char speed1_ovf = 0;
char speed2_ovf = 0;
unsigned int speed1 = 0;
unsigned int speed2 = 0;

// debugging
char tmp[10];

 // UART0 interrupt
ISR(USART1_RX_vect)
{
	char data;
	data = UDR0;
}

// Timer0 (8-bit) overflow interrupt
ISR(TIMER0_OVF_vect)
{	
	sendtekst("Speed1: ");
	ltoa(speed1,tmp,10);
	sendtekst(tmp);	
	sendtekst("\t");
	sendtekst("Speed2: ");
	ltoa(speed2,tmp,10);
	sendtekst(tmp);	
	sendtekst("\r\n");
}

// If counter overflow, speed = 0 (counter>2^16)
ISR(TIMER1_OVF_vect)
{
	speed1_ovf = 1;
	speed1 = 0;
}
ISR(TIMER3_OVF_vect)
{
	speed2_ovf = 1;
	speed2 = 0;
}
ISR(INT6_vect)
{
	if(speed1_ovf == 0)
	{
		speed1 = TCNT1;
		TCNT1 = 0;
		speed1_ovf = 0;
	}
	else
	{
		speed1 = 0;
		TCNT1 = 0;
		speed1_ovf = 0;
	}
}
ISR(INT7_vect)
{	
	if(speed2_ovf == 0)
	{
		speed2 = TCNT1;
		TCNT3 = 0;
		speed2_ovf = 0;
	}
	else
	{
		speed2 = 0;
		TCNT3 = 0;
		speed2_ovf = 0;
	}	
}



