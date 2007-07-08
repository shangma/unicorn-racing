#include<avr/io.h>
#include <util/delay.h>



int get_adc1(void);
int get_adc2(void);
void set_adc(void);
void disp_rpm(int rpm);
void disp_gear(int gear);
int calc_gear(int ppr_engine, int ppr_wheel);
int calc_rpm(int ppr_engine);


#define F_CPU = 8000000

int main (void) 
{
  DDRD = 0xFF;      
 
  int x = 0;
  int y = 0, z=0, gear=0, rpm=0;
  
  set_adc();
  
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
