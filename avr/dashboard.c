#include<avr/io.h>
#include <avr/interrupt.h>
//#include <avr/signal.h>
#include <util/delay.h>

#define F_CPU 8000000



int get_rpm_engine(void);
int get_velocity(void);
int set_adc(void);
int disp_rpm(int rpm);
void disp_gear(void);
void calc_gear(int ppr_engine, int ppr_wheel);
int calc_rpm(int ppr_engine);
int clutch(void);
int neutraul(void);
void init_ports(void);
void init_isr(void);
void shift_light(int rpm, int max_rpm);


volatile int gear;





SIGNAL(SIG_INTERRUPT0)     
/* signal handler for external interrupt int0 */
{	
	int c=0;
	c = clutch();
	shift_light(2,1);
    if (c != 0) // undersøger om koblingen er aktiveret
		{
		gear=gear+1;
		} 
	

}


SIGNAL(SIG_INTERRUPT1)     
/* signal handler for external interrupt int1 */
{
    int c=0;
	c=clutch();
	shift_light(2,1);
    if (c != 0) // undersøger om koblingen er aktiveret
		{
		gear=gear-1;
		}
	

}



int main (void) 
{	
  int velocity = 0, rpm=42, max_rpm = 700;
  gear=2;
 
  
  init_ports();
  init_isr();
  set_adc();            
                  
  	
  
  while(1) {  
    
	rpm = get_rpm_engine();
	velocity = get_velocity();
	
	
	calc_gear(rpm, velocity);
	/*gear=gear+1;
	if (gear > 7)
		{ 
		gear=1;
		}*/
	disp_gear();
	if (rpm > max_rpm)
		{
		shift_light(rpm,max_rpm);
		}
	//PORTB = ~rpm;

	_delay_ms(30);
	_delay_ms(30);
	_delay_ms(30);
	_delay_ms(30);
	_delay_ms(30);
	
	
  }

}


void init_ports(void)
{
  DDRB = 0b01111111;
  DDRD = 0b11100000;
  DDRC = 0b00000;
  PORTC= 0xFF;
  PORTD = 0b00011111;	// activate internal pull-up
}

void init_isr(void)
{
  GIMSK = 0b11000000;	//_BV(INT0 && INT1);           // enable external int0
  MCUCR = 0b00001010;  //_BV(ISC11 && ISC01);          // falling egde: int0
    
  sei();                       // enable interrupts 

}


void shift_light(int rpm, int max_rpm)
{
	
	if (rpm > max_rpm)
	{
		PORTD |= 0b00100000;
		_delay_ms(30);
		_delay_ms(30);
		_delay_ms(30);
		PORTD &= 0b11000000;
		_delay_ms(30);
		_delay_ms(30);
		_delay_ms(30);
		PORTD |= 0b00100000;
		_delay_ms(30);
		_delay_ms(30);
		_delay_ms(30);
		PORTD &= 0b11000000;
		_delay_ms(30);
		_delay_ms(30);
		_delay_ms(30);
	
	}

}



int clutch(void)
{
int c;
c=(~PINB & 0b10000000);
return c;

}


int neutral(void)
{
int n;
n=(~PIND & 0b00010000);
return n;

}







void disp_gear()
{

int n=0, c=0;

c=clutch();
n=neutral();

if (c != 0)
	{
	PORTB &= 0b11111110;
	}

else
	{
	PORTB |= 0b00000001;
	}



PORTB |= 0b00111110;	//sluk alle segmenter (untagen P)
PORTD |= 0b11000000;

if (n != 0)
	{
	PORTB &= 0b11110111;
	PORTD &= 0b00111111;
	}
else
	{
	
	if(gear==1)
		{		
		PORTB &= 0b11011111;
		PORTD &= 0b01111111;
		}
	else if (gear==2)
		{
		PORTB &= 0b11100101;
		PORTD &= 0b10111111;
		}
	else if (gear==3)
		{
		PORTB &= 0b11000101;
		PORTD &= 0b01111111;
		}
	else if (gear==4)
		{
		PORTB &= 0b11010011;
		PORTD &= 0b01111111;
		}
	else if (gear==5)
		{
		PORTB &= 0b11100001;
		PORTD &= 0b01111111;
		}
	else if (gear==6)
		{
		PORTB &= 0b11100001;
		PORTD &= 0b00111111;
		}		
	}

	
	//PORTB=~(1<<(gear-1));
}









int set_adc(void)
{
// Activate ADC with Prescaler 16 --> 1Mhz/16 = 62.5kHz
  ADCSRA = _BV(ADEN) | _BV(ADPS2);
	return 0;
}




int get_rpm_engine(void)
{
	int x;

	// Select pin ADC0 using MUX
    ADMUX = 0b0001;

	//Start conversion
    ADCSRA |= _BV(ADSC);
    
    // wait until converstion completed
    while (ADCSRA & _BV(ADSC) ) {}
    
    // get converted value
    x = ADCW;

return x;
}






int get_velocity(void)
{
	int x;

	// Select pin ADC1 using MUX
    ADMUX = 0;

	//Start conversion
    ADCSRA |= _BV(ADSC);
    
    // wait until converstion completed
    while (ADCSRA & _BV(ADSC) ) {}
    
    // get converted value
    x = ADCW;
return x;
}

void calc_gear(int ppr_engine, int ppr_wheel)
{
	
	unsigned int z;
	

	
	z=ppr_wheel*64;
	z=z/ppr_engine;
	//PORTB = ~z/16;

	

	
	
	if (z<=33)
		{
		gear = 1;
		}
	else if (z<= 42)
		{
		gear = 2;
		} 
	else if (z<= 49)
		{
		gear = 3;
		}
	else if (z<= 56)
		{
		gear = 4;
		} 
	else if (z<= 61)
		{
		gear = 5;
		}
	else  
		{
		gear = 6;
		}
	//PORTB =~gear;
	
}



