#include "display.h"

void display(uint8_t rpm, uint8_t gear, uint8_t flags){
  display_t dispData;
  int8_t c;
  uint8_t gearData[8]={0,disp1,disp2,disp3,disp4,disp5,disp6,dispN};
  uint8_t rpmScale[5]={92,108,124,139,155};
  /*6000 7000 8000 9000 10000*/
  
  dispData.rpm=0x3ff;
  
  for(c=0;c<5;c++){
    if(rpm>rpmScale[c]){
      dispData.rpm&=~_BV(c)&~_BV(9-c);
/*      if(c){
        dispData.rpm|=_BV(c-1);   //dot-style
      }*/
    }else{
      break;
    }
  }
  
  if(rpm>172){
    dispData.rpm=0x3ff*((timeDiv&0x04)!=0);
  }
  
  dispData.gear=gearData[gear];
  dispData.flags=(uint8_t)~flags;
  
  PORTB&=~pStr;               //disable strobe
  _delay_us(displayDelay);

  for(c=7;c>=0;c--){
    if(dispData.gear&_BV(c)){
      PORTB|=pData;
    }else{
      PORTB&=~pData;
    }
    _delay_us(displayDelay);
    PORTB|=pClock;
    _delay_us(displayDelay);
    PORTB&=~pClock;
  }

  for(c=5;c>=0;c--){
    if(dispData.flags&_BV(c)){
      PORTB|=pData;
    }else{
      PORTB&=~pData;
    }
    _delay_us(displayDelay);
    PORTB|=pClock;
    _delay_us(displayDelay);
    PORTB&=~pClock;
  }
  
  for(c=9;c>=0;c--){
    if(dispData.rpm&_BV(c)){
      PORTB|=pData;
    }else{
      PORTB&=~pData;
    }
    _delay_us(displayDelay);
    PORTB|=pClock;
    _delay_us(displayDelay);
    PORTB&=~pClock;
  }

  _delay_us(displayDelay);
  PORTB|=pStr;                //enable strobe
  
}
