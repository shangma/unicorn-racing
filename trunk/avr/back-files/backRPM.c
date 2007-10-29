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

uint8_t shift(uint8_t rpm,uint8_t gear){
  
  if(rpm>110){
    return 0x06*((timeDiv&0x01)!=0)+0x30*!((timeDiv&0x01)!=0);
  }else{
    return 0;
  }

}
