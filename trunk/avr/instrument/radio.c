#include "radio.h"

volatile char connectCMD[10]="\nAT^SETUP\n";
volatile char onlineCMD[5]="\nATO\n";

void radioInit(void){
  uint8_t c;

  PORTC&=~pConfig1;
  PORTC|=pConfig2;
  
  _delay_ms(1000);
  
  for(c=0;c<10;c++){
    while(!(UCSR0A&_BV(UDRE0))){
    }
    UDR0=connectCMD[c];
  }
  
  _delay_ms(1000);
  
  for(c=0;c<5;c++){
    while(!(UCSR0A&_BV(UDRE0))){
    }
    UDR0=onlineCMD[c];
  }
  
  _delay_ms(1000);
  
  PORTC&=~pConfig2;
  PORTC|=pConfig1;

}
