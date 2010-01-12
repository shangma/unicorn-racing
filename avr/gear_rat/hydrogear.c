#include "config.h"
#include "hydrogear.h"
#include "can_lib.h"

#include <avr/io.h>


int main(void){
 
   DDRA = 0xFF;            //Make Port A output values
   PORTA = 0x00;           //Turn all output pins on port c off

   DDRE = 0x00;
   PORTE= 0xFF;
 
    while(1){
	
	if(~PINE&GEARUP){
		PORTA = LED1;
//		_delay_ms(1000);
	}
	else if(~PINE&GEARDOWN){
		PORTA = LED0;
//		_delay_ms(1000);
	}
	else{
	PORTA=0x00;
	}
   }

}
