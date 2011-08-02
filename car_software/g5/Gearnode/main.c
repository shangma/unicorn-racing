/*********************************************
 * Unicorn main gear kontrol
 *********************************************/

#include "config.h"
#include "extern.h"
#include "prototyper.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>

// Debugging
char tempchar[10];

int main(void)
{
	_delay_ms(1000);
	ioinit();
	uartinit();
	pwm16Init();
	adcInit(1);
	counter0Init();
	hbroEnable(1);
	sei();
	
	sendtekst("\n\rUnicorn Gearnode v1.0 \n\r");

	while (1)
	{
	}
    return 0;
}
