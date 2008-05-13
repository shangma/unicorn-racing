#include "display.h"

void display(uint8_t rpm, uint8_t gear, uint8_t flags){
  display_t dispData;
  int8_t c;
  uint8_t gearData[8]={0,disp1,disp2,disp3,disp4,disp5,disp6,dispN};
  uint8_t rpmScale[10]={20,40,60,70,80,90,100,110,120,130};
  
  dispData.rpm=0x3ff;
  
  for(c=0;c<10;c++){
    if(rpm>rpmScale[c]){
      dispData.rpm&=~_BV(c);
/*      if(c){
        dispData.rpm|=_BV(c-1);   //dot-style
      }*/
    }else{
      break;
    }
  }
  
  dispData.gear=gearData[gear];
  dispData.flags=(uint8_t)~flags;
  
  PORTB&=~pStr;               //disable strobe

  for(c=7;c>=0;c--){
    if(dispData.gear&_BV(c)){
      PORTB|=pData;
    }else{
      PORTB&=~pData;
    }
    _delay_us(100);
    PORTB|=pClock;
    _delay_us(100);
    PORTB&=~pClock;
  }

  for(c=5;c>=0;c--){
    if(dispData.flags&_BV(c)){
      PORTB|=pData;
    }else{
      PORTB&=~pData;
    }
    _delay_us(100);
    PORTB|=pClock;
    _delay_us(100);
    PORTB&=~pClock;
  }
  
  for(c=9;c>=0;c--){
    if(dispData.rpm&_BV(c)){
      PORTB|=pData;
    }else{
      PORTB&=~pData;
    }
    _delay_us(100);
    PORTB|=pClock;
    _delay_us(100);
    PORTB&=~pClock;
  }

  PORTB|=pStr;                //enable strobe
  
}
