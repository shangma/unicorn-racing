#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>


#define F_CPU 18432000
#include <util/delay.h>
#define USART_BAUDRATE 230400
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1) 

int p = 0;
float i = 0.0;
int ref = 60;

void uartinit(void)
{
	//"Tænder" for TXen og RXen (send og modtag portene)
	UCSR0B = (1<<RXEN0)|(1<<TXEN0); 
	
	// Opsætning af format: 8data, 1 stop bit
	UCSR0C = (3<<UCSZ00);

	// Opsætning af baud rate
	UBRR0L = BAUD_PRESCALE;
	UBRR0H = (BAUD_PRESCALE >> 8);
	
	// Opsætning af Rx Uart interrupt (Receive Complete Interrupt) til indkommen seriel data
	UCSR0B|=(1<<RXCIE0);
}

void PWM_duty_cycle_A_set(unsigned int x)
{
	OCR0A = x; 
}

void PWM_duty_cycle_B_set(unsigned int x)
{
	OCR0B = x; 
}

void PWM_duty_cycle_A16_set(unsigned int x)
{
	OCR1AH = (0xFF) & (x>>8);
	OCR1AL = (0xFF) & (x); 
}

void pwm8Init(void)
{
	//PWM, 8 bit counter (counter0)
	// (OC0A) Output
    DDRB|= (1<<PB3);  
	// (OC0B) Output
	DDRB|= (1<<PB4);      

	// Opsætning af compare match.
	TCCR0A |=(1<<COM0A1);
	TCCR0A &=~(1<<COM0A0);

	TCCR0A |=(1<<COM0B1);
	TCCR0A &=~(1<<COM0B0);

	// FAST-PWM
	TCCR0A |=(1<<WGM00);
	TCCR0A |=(1<<WGM01);

	// Prescaler, 1
    TCCR0B |=(1<<CS00);

	PWM_duty_cycle_A_set(0);
	PWM_duty_cycle_B_set(0);
}

void pwm16Init(void)
{
	//PWM, 16 bit counter (counter1)
	// (OC1A) Output
    DDRD|= (1<<PD4);  
    DDRD|= (1<<PD5);  
     
	// Opsætning af compare match.
	TCCR1A |=(1<<COM1A1);
	TCCR1A |=(1<<COM1A0);

	// FAST-PWM TOP = ICRn
	TCCR1A &=~(1<<WGM10);
	TCCR1A |=(1<<WGM11);
	TCCR1B |=(1<<WGM12);
	TCCR1B |=(1<<WGM13);

	//Top (10-bit)
	ICR1H = 0x00;
	ICR1L = 0xFF;

	// Prescaler, 64
    TCCR1B &=~(1<<CS10);
	TCCR1B |=(1<<CS11); 
	TCCR1B &=~(1<<CS12); 

	// Compare match værdi
	PWM_duty_cycle_A16_set(0);
}

void sendtekst(char *tekstarray)
{
	// Tæller
	short int i;

	// Sender en byte af gangen
	for (i = 0; tekstarray[i] != '\0'; i++)
	{	
		while ((UCSR0A & (1 << UDRE0)) == 0) {};	// Venter indtil UDR0 er klar til ny data
		UDR0 = tekstarray[i]; 						// Data lægges i buffer (UDR0) og sendes via TXen
	}
}

unsigned int convertanalog(unsigned channel)
{
	unsigned int adlow = 0;
	unsigned int adhigh = 0; 
	
    ADMUX=(1<<REFS0)|(channel & 0x0f);
    ADCSRA=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
    ADCSRA|= (1<<ADSC);
    while(bit_is_set(ADCSRA,ADSC)); 
    adlow=ADCL; 
    adhigh=ADCH;
    return((unsigned int)((adhigh<<8)|(adlow & 0xFF)));
}



int main(void)
{
    uartinit();
    pwm8Init();
    pwm16Init();
    sei();
    char tempchar[5];
    int press = 0;

    int out = 0;
    int outP = 0;
    float outI = 0;    

    float pressOld = 0; 

    while (1){

    _delay_ms(10);

    press = 0.17*convertanalog(0)-18.0;

    if(press<=0)
        press = 0;

    outP = (ref-press)*p;

    outI = (((ref-press)*0.01+pressOld)*i);

    pressOld = pressOld + (ref-press)*(0.01);

    out = (int)(outP + outI);

    if(pressOld>5000)
       pressOld = 5000;

    if(pressOld<-5000)
        pressOld = -5000;

    if(out>1023)
        out = 1023;

    if(out<=0)
        out = 0;

    PWM_duty_cycle_A16_set(out);

	itoa(ref, tempchar,10); 
	sendtekst(tempchar);
    sendtekst(";");
	itoa(press, tempchar,10); 
	sendtekst(tempchar);
    sendtekst(";");
	itoa(out, tempchar,10); 
	sendtekst(tempchar);
    sendtekst(";");
	itoa(p, tempchar,10); 
	sendtekst(tempchar);
    sendtekst(";");
	itoa((int)(i*100), tempchar,10); 
	sendtekst(tempchar);
    sendtekst("\n\r");

    }

    return 0;
}
