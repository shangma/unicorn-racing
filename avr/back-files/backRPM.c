#include "backRPM.h"

void rpmInit(void){
  /*Init. counter0*/
  rpmRpm=0;
}

int rpmCalc(void){
  rpmRpm=TCNT0;
  TCNT0=0;
  /*Convert rpm to sensible scale*/
  return rpmRpm;
}

int rpmGet(void){
  return rpmRpm;
}
