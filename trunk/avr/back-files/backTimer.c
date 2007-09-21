#include "backTimer.h"

void timerInit(void){
  TCCR2=0x07; /*prescaler=1024*/
  TIMSK|=_BV(TOIE2);
}

ISR(TIMER2_OVF_vect){

  TCNT2=TCNT2&~0x40;
  
  rpm=rpmGet();
/*  speed=speedGet();*/
  speed=40;
  
  flags.newMeasure=true;
  timeDiv++;
}
