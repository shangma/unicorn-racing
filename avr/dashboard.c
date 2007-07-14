#include<avr/io.h>
#include <avr/interrupt.h>
//#include <avr/signal.h>
#include <util/delay.h>

#define F_CPU 8000000



int get_rpm_engine(void);
int get_velocity(void);
int set_adc(void);
int disp_rpm(int rpm);
void disp_gear(char gear);
int calc_gear(int ppr_engine, int ppr_wheel);
int calc_rpm(int ppr_engine);
int clutch(void);
int neutraul(void);
void init_ports(void);
void init_isr(void);
void shift_light(void);


volatile char gear;





SIGNAL(SIG_INTERRUPT0)     
/* signal handler for external interrupt int0 */
{	
	int c=0;
	c = clutch();
    if (c == 1) // undersøger om koblingen er aktiveret
		{
		gear=gear+1;
		} 
	

}


SIGNAL(SIG_INTERRUPT1)     
/* signal handler for external interrupt int1 */
{
    int c=0;
	c=clutch();
    if (c == 1) // undersøger om koblingen er aktiveret
		{
		gear=gear-1;
		}
	

}



int main (void) 
{	
  int velocity = 0, rpm=0, max_rpm = 512;
  gear=0;
 
  
  init_ports();
  init_isr();
  set_adc();            
                  
  	
  
  for (;;) {  
    
	rpm = get_rpm_engine();
	velocity = get_velocity();
	
	
	//gear=calc_gear(rpm, velocity);

	disp_gear(gear);
	if (rpm > max_rpm)
		{
		shift_light();
		}
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


void shift_light(void)
{
	int i=13;
	while (i)
	{
		PORTB=0xFF;
		_delay_ms(30);
		_delay_ms(30);
		_delay_ms(30);
		PORTB=0x00;
		_delay_ms(30);
		_delay_ms(30);
		_delay_ms(30);
		i=i-1;
	}

}



int clutch(void)
{
int c;
c=(~PIND & 0b00000001);
return c;

}


int neutral(void)
{
int n;
n=(~PIND & 0b00010000);
return n;

}







void disp_gear(char gear)
{
int n=0;
n=neutral();
	/*switch(gear)
	{
	case 1:
		{
		PORTB=0b00100000;
		PORTD=0b10000000;
		}
	case 2:
		{
		PORTB=0b00111010;
		PORTD=0b01000000;
		}
	case 3:
		{
		PORTB=0b00111010;
		PORTD=0b10000000;
		}
	case 4:
		{
		PORTB=0b00101100;
		PORTD=0b10000000;
		}
	case 5:
		{
		PORTB=0b00011110;
		PORTD=0b10000000;
		}
	case 6:
		{
		PORTB=0b00001110;
		PORTD=0b11000000;
		}		
	}
	
*/
if (n)
	{
	PORTB=0x00;
	}
else
	{
	PORTB=~(1<<(gear-1));
	}
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
    ADMUX = 0;

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
    ADMUX = 0b0001;

	//Start conversion
    ADCSRA |= _BV(ADSC);
    
    // wait until converstion completed
    while (ADCSRA & _BV(ADSC) ) {}
    
    // get converted value
    x = ADCW;
return x;
}

int calc_gear(int ppr_engine, int ppr_wheel)
{
	//extern char gear;
	float z;

	
	ppr_engine=ppr_engine*1024;
	z=ppr_engine/ppr_wheel;

	

	
	
	if (z<=520)
		{
		gear = 1;
		}
	else if (z>520 && z<= 663)
		{
		gear = 2;
		} 
	else if (z>663 && z<= 776)
		{
		gear = 3;
		}
	else if (z>776 && z<= 876)
		{
		gear = 4;
		} 
	else if (z>876 && z<= 962)
		{
		gear = 5;
		}
	else if (z>962)
		{
		gear = 6;
		}
	//PORTD =~gear;
	return gear;

}


