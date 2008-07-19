#include "radio.h"

volatile char connectCMD[14]="\r\nAT^SETUP 1\r\n";
volatile char onlineCMD[7]="\r\nATO\r\n";

void radioInit(void){
  uint8_t c;

	flags.online=false;
//	flags.online=true;
	
	PCMSK2=0x20;

  PORTD|=pConfigD;    /*Disable ECU->Radio forward*/
  PORTB|=pConfigB;    /*Disable ECU TX, Enable Radio RX/TX*/
  
//  _delay_ms(50);
  
  for(c=0;c<14;c++){
    while(!(UCSR0A&_BV(UDRE0))){
    }
    UDR0=connectCMD[c];
  }
  
//  _delay_ms(50);
	
	radioInit2();
	
	PORTB&=~pConfigB;   /*Enable ECU TX, Disable Radio RX/TX*/
	
}

void radioInit2(void){
  uint8_t c;
	
	PORTD|=pConfigD;    /*Disable ECU->Radio forward*/
  PORTB|=pConfigB;    /*Disable ECU TX, Enable Radio RX/TX*/
	
//	_delay_ms(50);
	
  for(c=0;c<7;c++){
    while(!(UCSR0A&_BV(UDRE0))){
    }
    UDR0=onlineCMD[c];
  }
	
//  _delay_ms(50);
	
  PORTB&=~pConfigB;   /*Enable ECU TX, Disable Radio RX/TX*/
	
}
