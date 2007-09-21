#include "backRPM.h"

void rpmInit(void){
  TCCR1B=0x06;  /*count from PORTD.5*/
}

uint8_t rpmGet(void){
  uint8_t rpmRaw;
  
  rpmRaw=TCNT1L;
  TCNT1L=0;
  
  return rpmRaw;
}
