#define F_CPU 8000000UL  // 8 MHz
#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <util/delay.h>
#include "dvk90.h"

int main(void){

	 // set the clock speed to 8MHz
        // set the clock prescaler. First write CLKPCE to enable setting of clock the
        // next four instructions.
        CLKPR=(1<<CLKPCE);
        CLKPR=0; // 8 MHZ
        _delay_ms(10);

	//Enable port A.1 as output
	DDRA|= (1<<DDA0);

	while(1){
	//Set port a.1 high
	PORTA|= (1<<PA0);

	_delay_ms(1000);

	//Set port a.1 low
   PORTA &= ~(1<<PA0);
	}

}


