#include "timer.h"

void timerInit(void){
  TCCR2B=0x07; /*prescaler=1024*/
  TIMSK2|=_BV(TOIE2);
  timeDiv=0;
  timeOut=0x0f;
  preScaler=0;
}

ISR(TIMER2_OVF_vect){

/*
F_CPU=4MHz, Timer2 prescaler=1024 -> 3906Hz
*/

  TCNT2|=0x40;
  
  if (preScaler==2){
  
  preScaler=0;
  
/*  newRPM=40;
  newSpeed=40;
  newWarnings=0;*/
  
  flags.refresh=true;
  timeDiv++;
  
  if (timeOut>0){
    timeOut--;
  }
  
  if (timeOut==0||flags.reply==true){
    flags.reply=false;
    flags.reqInfo=true;
    timeOut=0x0f;
  }
  }else{
    preScaler++;
  }
}
