#include <avr/io.h>           //Required to use assembler commands
#define F_CPU 8000000  // set the internal clock speed of 1 MHz
#include <util/delay.h>
 
int main(void){
 
   DDRA = 0xFF;            //Make Port C output values
   PORTA = 0x00;           //Turn all output pins on port c off

   DDRE = 0x00;
   PORTE= 0xFF;
 
    while(1){
	
	if(~PINE&_BV(7)){
		PORTA = 0x02;
//		_delay_ms(1000);
	}
	else{
	PORTA=0x00;
	}
   }

}
