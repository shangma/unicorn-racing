#include "timer.h"

void timerInit(void){
  TCCR2B=0x07; /*prescaler=1024*/
  TIMSK2|=_BV(TOIE2);
}

ISR(TIMER2_OVF_vect){

/*
F_CPU=4MHz, Timer1 prescaler=1024 -> 3906Hz
Crank wheel teeth=12 -> 200Hz @ 1000rpm
we want 100rpm/tick/interrupt -> interrupt @ 20Hz
3906Hz/20Hz=195 -> we add 64 to the counter to get 256-64=192
*/

  TCNT2|=0x40;
  
/*  newRPM=40;
  newSpeed=40;
  newWarnings=0;*/
  
  flags.refresh=true;
  timeDiv++;
  
  if (timeDiv==0||flags.reply){
    flags.reply=false;
    flags.reqInfo=true;
  }
}
