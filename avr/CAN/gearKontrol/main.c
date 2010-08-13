/*********************************************
 * Unicorn main gear kontrol
 *********************************************/

#include <config.h>
#include <extern.h>
#include <prototyper.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void)
{
	ioinit();
	uartinit();
	pwm8Init();
	//pwm16Init();
	adcInit(0);
	counter0Init();
	pcintInit();
	hbroEnable(1);
	sei();	
	
	while (1)
	{
		if((PINB & 0x01) == 0x00) // Gear Kontakt GEAROP
		{
			_delay_ms(5);

			if((PINB & 0x01) == 0x00) // Stadig trykket ? (væk med støj)
			{
				gearRetning = GEAROP;
				softwareTrig;
				_delay_ms(400); // Vent til gearskift er ca done
			}			
		}	

		if((PINB & 0x02) == 0x00) // Gear Kontakt GEARNED
		{
			_delay_ms(5);

			if((PINB & 0x02) == 0x00) 
			{
				gearRetning = GEARNED;
				softwareTrig;
				_delay_ms(400);
			}			
		}			
	}
    return 0;
}
