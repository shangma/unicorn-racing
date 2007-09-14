#include "backTimer.h"

extern rpm;
extern speed;

void timerInit(void){
}

ISR(TIMER1_OVF_vect){

  rpm=rpmGet();
  speed=speedGet();

/*Send data*/
}
