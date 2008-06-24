#include "radio.h"

volatile char connectCMD[14]="\r\nAT^SETUP 1\r\n";
volatile char onlineCMD[7]="\r\nATO\r\n";

void radioInit(void){
  uint8_t c;

  PORTC&=~pConfig1;
  PORTC|=pConfig2;
  
  _delay_ms(1000);
  
  for(c=0;c<14;c++){
    while(!(UCSR0A&_BV(UDRE0))){
    }
    UDR0=connectCMD[c];
  }
  
  _delay_ms(1000);
  
  for(c=0;c<7;c++){
    while(!(UCSR0A&_BV(UDRE0))){
    }
    UDR0=onlineCMD[c];
  }
  
  _delay_ms(1000);
  
  PORTC&=~pConfig2;
  PORTC|=pConfig1;

}
