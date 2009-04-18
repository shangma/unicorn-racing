#include "backGear.h"

void gearInit(void){
  MCUCR|=0x0A;                //external interrupt on falling edge
  GICR|=_BV(INT0)|_BV(INT1);  //enable external interrupt
  gearDir=0;
}

uint8_t gearGet(uint8_t rpm, uint8_t speed){
  uint16_t ratio;

  if(!(PIND&pNeutral)){
    gear=7;
    return gear;
  }
  
  if(!(PIND&pClutch) || rpm<18 || speed<10){
    if(gear==7){          //only show n when in neutral
      gear=1+gearDir;
    }
    return gear*((timeDiv&0x04)!=0);
  }
  
  ratio=(speed*256)/rpm;
  
  if(ratio>256){
    gear=6;
  }else if(ratio>200){
    gear=5;
  }else if(ratio>150){
    gear=4;
  }else if(ratio>100){
    gear=3;
  }else if(ratio>50){
    gear=2;
  }else{
    gear=1;
  }
  return gear;
}


ISR(SIG_INTERRUPT0){    //up-shift
/*  if(PINB&pClutch){
    return;
  }*/
  gearDir=1;
  if(gear==0){
    return;
  }
  if(gear==7){
    gear=2;
  }else if(gear<6){
    gear++;
  }
}

ISR(SIG_INTERRUPT1){    //down-shift
/*  if(PINB&pClutch){
    return;
  }*/
  gearDir=0;
  if(gear==0){
    return;
  }
  if(gear==7){
    gear=1;
  }else if(gear>1){
    gear--;
  }
}
