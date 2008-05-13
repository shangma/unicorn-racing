#include "si.h"

ISR(USART_RX_vect){
  flags.newByte=true;
}

void siInit(void){
  UBRR0=12; /*19200baud at 4MHz*/
  UCSR0B|=_BV(TXEN0)|_BV(RXEN0)|_BV(RXCIE0);
}

void reqInfo(void){
  siCount=0;
  UDR0=0x55;
}

void getInfo(void){
  uint8_t tmp;
  
  if(!(UCSR0A&_BV(RXC0))){
    return;
  }
  siCount++;
  switch(siCount){
    case 1:
      newRPM=UDR0;
      break;
    case 2:
      newSpeed=UDR0;
      break;
    case 3:
      newWarnings=UDR0;
      flags.newMeasure=true;
      flags.reply=true;
    default:
      tmp=UDR0;
      break;
  }
  
}
