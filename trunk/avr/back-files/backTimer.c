#include "backTimer.h"

void timerInit(void){
  TCCR2=0x07; /*prescaler=1024*/
  TIMSK|=_BV(TOIE2);
}

ISR(TIMER2_OVF_vect){

/*
F_CPU=4MHz, Timer2 prescaler=1024 -> 3906Hz
Crank wheel teeth=12 -> 200Hz @ 1000rpm
we want 100rpm/tick/interrupt -> interrupt @ 20Hz
3906Hz/20Hz=195 -> we add 64 to the counter to get 256-64=192
*/

  TCNT2|=0x40;
  
  rpm=rpmGet();
/*  speed=speedGet();*/
  speed=40;
  
  flags.newMeasure=true;
  timeDiv++;
}
