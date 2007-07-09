#include<avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/signal.h>



int get_adc1(void);
int get_adc2(void);
void set_adc(void);
void disp_rpm(int rpm);
void disp_gear(int gear);
int calc_gear(int ppr_engine, int ppr_wheel);
int calc_rpm(int ppr_engine);





SIGNAL(SIG_INTERRUPT0)     
/* signal handler for external interrupt int0 */
{
     
	int i=0, a=0;
    while (a<1000)
		{
		if (1<=5)
			{
			PORTB=~(1<<i);
			}
		
		
		if (i>5)
			{
			PORTB=~(1<<(10-i));
			}
		i=i+1;
		a=a+1;
		_delay_ms(10000000);
		if (i>10)
			{
			i=0;
			}
		}

}


SIGNAL(SIG_INTERRUPT1)     
/* signal handler for external interrupt int1 */
{
     
	int i=255;
    while (i>=0)
		{
		PORTB=i;
		i=i-1;
		_delay_ms(1000);
		}

}



int main (void) 
{
  DDRB = 0xFF;      
 
  int x = 0;
  int y = 0, z=0, gear=0, rpm=0;
  
  set_adc();
    DDRD  = 0x00;                // use all pins on port D for input
    PORTD = 0xff;                // activate internal pull-up
    
    GIMSK = 0b11000000;	//_BV(INT0 && INT1);           // enable external int0
    MCUCR = 0b00001010;  //_BV(ISC11 && ISC01);          // falling egde: int0
    
    sei();                       // enable interrupts 


	
  
  for (;;) {  
    
	x = get_adc1();
	y = get_adc2();
	
	//PORTD=~y/4;
	gear=calc_gear(x, y);

	disp_gear(gear);
	_delay_ms(1000);
  }

}





















void set_adc(void)
{
// Activate ADC with Prescaler 16 --> 1Mhz/16 = 62.5kHz
  ADCSRA = _BV(ADEN) | _BV(ADPS2);
}

int get_adc1(void)
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

int get_adc2(void)
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

int calc_gear(int ppr_engine, int ppr_wheel)
{
	int  gear;
	float z, tmp;
	ppr_engine=ppr_engine*1000;
	z=ppr_engine/ppr_wheel;

	tmp = z*255;
	tmp = tmp/1000;
	
		

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

void disp_gear(int gear)
{
	PORTD=~(1<<gear);

}
