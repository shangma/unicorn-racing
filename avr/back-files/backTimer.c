#include "backTimer.h"

void timerInit(void){
  /*Init. timer2*/
  
}

ISR(TIMER2_OVF_vect){
  int rpm;
  int speed;

  rpm=rpmCalc();
  speed=speedCalc();
  adcOP(new);
  adcCT(new);
  
  flags.newMeasure=true;

/*Send data*/
}
