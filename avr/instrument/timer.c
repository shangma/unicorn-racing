#include "timer.h"

void timerInit(void){
  TCCR1=0x0B; /*prescaler=1024*/
  TIMSK|=_BV(TOIE1);
}

ISR(TIMER1_OVF_vect){

/*
F_CPU=4MHz, Timer1 prescaler=1024 -> 3906Hz
Crank wheel teeth=12 -> 200Hz @ 1000rpm
we want 100rpm/tick/interrupt -> interrupt @ 20Hz
3906Hz/20Hz=195 -> we add 64 to the counter to get 256-64=192
*/

  TCNT1|=0x40;
  
  rpm=40;
/*  speed=speedGet();*/
  speed=40;
  
  flags.newMeasure=true;
  timeDiv++;
  
  PORTB^=_BV(0);
}
