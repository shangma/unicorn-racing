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

extern int p;
extern float i;
extern int ref;

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

    if(data == 'i')
    {
    i = i+0.01;
    }

    if(data == 'j')
    {
    i = i-0.01;
    }

    if(data == 'p')
    {
    p++;
    }

    if(data == 'l')
    {
    p--;
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
	
	itoa(count, tempchar,10); 
	sendtekst(tempchar);
    sendtekst(";");
	itoa(speed, tempchar,10); 
	sendtekst(tempchar);
    sendtekst("\n\r");
}
