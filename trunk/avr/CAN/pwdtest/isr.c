#include <config.h>
#include <prototyper.h>
#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>

/*********************************************
 * AVR atMega644P Interrupt-service-rutiner
 *********************************************/

void sendtekst(char *);
void PWM_duty_cycle_A_set(unsigned int);
void PWM_duty_cycle_B_set(unsigned int);
void PWM_duty_cycle_A16_set(unsigned int);

// Variable
char count = 0;
char retning = 0;
unsigned int speed = 0;

extern int kp;
extern float ki;
extern int ref;
extern unsigned int ADCconv;

unsigned int adlow = 0;
unsigned int adhigh = 0;

char channel = 0;

// Timer0 (8-bit) overflow interrupt
ISR(TIMER0_OVF_vect)
{	
	ADMUX &= 0xf8;
	ADMUX |= channel++;
	ADCSRA|=(1<<ADSC);

	if(channel>=ADCtotnum)
		channel = 0;
}

// ADC convert complete
ISR(ADC_vect)
{
	char tempchar[5];
	char channel = 0;

	channel = ADMUX & 0x07;

    adlow=ADCL;
    adhigh=ADCH;
	ADCconv = (unsigned int)((adhigh<<8)|(adlow & 0xFF));	
/*	
	sendtekst("  ADC ");
	itoa(channel, tempchar,10); 
	sendtekst(tempchar);
	sendtekst(":");
	itoa(ADCconv, tempchar,10); 
	sendtekst(tempchar);
*/
	if(channel == 0)
		presscontroller(ADCconv);

	//if(channel>=ADCtotnum-1)
	//	sendtekst("\n\r");
}

 //----- UART Interrupt --------------------------------------------------------
ISR(USART0_RX_vect)
{
	char data;
	char tempchar[5];	
	data = UDR0;	// Lægger data fra seriel bufffer i variabel

    if(data == 'x')
    {
    ref++;
    }

    if(data == 'z')
    {
    ref--;
    }

    if(data == '<')
    {
    ref = 110;
    }

    if(data == 'i')
    {
    ki = ki+0.1;
    }

    if(data == 'j')
    {
    ki = ki-0.1;
    }

    if(data == 'p')
    {
    kp++;
    }

    if(data == 'l')
    {
    kp--;
    }

    if(data == 'c')
    {
    PWM_duty_cycle_A16_set(0);
    }

    if(data == 'v')
    {
    PWM_duty_cycle_A16_set(1023);
    }

    if(data == 'o')
    {
        speed = speed + 16;

        if(speed>=1023)
            speed = 1023;
    PWM_duty_cycle_A16_set(speed);
    }

    if(data == 'n')
    {
        if(speed<16)
            speed = 16;

    speed = speed - 16;
    PWM_duty_cycle_A16_set(speed);
    }

    if(data == 'a')
    {
        count = 0;
        retning = 0;
        PWM_duty_cycle_A_set(0);
	    PWM_duty_cycle_B_set(0);
    }

    if(data == 'd')
    {
        count = 0;
        retning = 1;
        PWM_duty_cycle_A_set(0);
	    PWM_duty_cycle_B_set(0);
    }
	
	if(data == 'w')
	{
        if(count>=254)
            count = 254;

        count++;

        if(retning)
		    PWM_duty_cycle_A_set(count);
        else
            PWM_duty_cycle_B_set(count);
	}	
	if(data == 's')
	{
        if(count<=1)
            count = 1;            

        count--;
        
        if(retning)        
		    PWM_duty_cycle_A_set(count);
        else
            PWM_duty_cycle_B_set(count);
	}
	if(data == 'q')
	{
        if(count>=254)
            count = 254;

        count = 255;

        if(retning)
		    PWM_duty_cycle_A_set(count);
        else
            PWM_duty_cycle_B_set(count);
	}
	if(data == 'e')
	{
        if(count>=254)
            count = 254;

        count = 0;

        if(retning)
		    PWM_duty_cycle_A_set(count);
        else
            PWM_duty_cycle_B_set(count);
	}	
/*	
	itoa(count, tempchar,10); 
	sendtekst(tempchar);
    sendtekst(";");
	itoa(speed, tempchar,10); 
	sendtekst(tempchar);
    sendtekst("\n\r");
*/
}
