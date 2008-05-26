#include "si.h"

const uint8_t reqCmd[10]={0x12,0x34,0x56,0x78,23,8,0,0,0,0};

ISR(USART_RX_vect){
  flags.newByte=true;
}

void siInit(void){
  UBRR0=12; /*19200baud at 4MHz*/
  UCSR0B|=_BV(TXEN0)|_BV(RXEN0)|_BV(RXCIE0);
}

void reqInfo(void){
  uint8_t c;
  
  siCount=0;
  
  for(c=0;c<10;c++){
    while(!(UCSR0A&_BV(UDRE0))){
    }
    UDR0=reqCmd[c];
  }
}

void getInfo(void){
  uint8_t tmp;
  uint8_t* dirtyPointer;
  
  if(!(UCSR0A&_BV(RXC0))){
    return;
  }
  siCount++;
  switch(siCount){
    case 54:
      dirtyPointer=(uint8_t*)&newRPM;
      dirtyPointer[0]=UDR0;
      break;
    case 55:
      dirtyPointer=(uint8_t*)&newRPM;
      dirtyPointer[1]=UDR0;
      break;
    case 62:
      dirtyPointer=(uint8_t*)&newSpeed;
      dirtyPointer[0]=UDR0;
      break;
    case 63:
      dirtyPointer=(uint8_t*)&newSpeed;
      dirtyPointer[1]=UDR0;
      break;
    case 100:
      newWarnings=UDR0;
      flags.newMeasure=true;
      flags.reply=true;
    default:
      tmp=UDR0;
      break;
  }
  
}
