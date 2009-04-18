#include "backSPEED.h"

void speedInit(void){
  /*Init. counter2*/
  speedSpeed=0;
}

int speedCalc(void){
  speedSpeed=TCNT2;
  TCNT2=0;
  /*Convert speed to sensible scale*/
  return speedSpeed;
}

int speedGet(void){
  return speedSpeed;
}
