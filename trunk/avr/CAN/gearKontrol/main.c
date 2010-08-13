/*********************************************
 * Unicorn main
 *********************************************/

#include <config.h>
#include <extern.h>
#include <prototyper.h>
#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void)
{
	// Init
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
		if((PINB & 0x01) == 0x00) // Gear Kontakt trykket
		{
			_delay_ms(5);

			if((PINB & 0x01) == 0x00) // Stadig trykket ? (væk med støj)
			{
				gearRetning = GEAROP;
				softwareTrig;
				_delay_ms(400); // Vent til gearskift er ca done
			}			
		}	

		if((PINB & 0x02) == 0x00) // Gear Kontakt trykket
		{
			_delay_ms(5);

			if((PINB & 0x02) == 0x00) // Stadig trykket ? (væk med støj)
			{
				gearRetning = GEARNED;
				softwareTrig;
				_delay_ms(400); // Vent til gearskift er ca done
			}			
		}			
	}
    return 0;
}
