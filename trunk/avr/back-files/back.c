#include "back.h"

void init(void){
  initTimer();
  initRPM();
  initSPEED();
  initADC();
}

int main(void){
  init();
  
  while(1){
  }
}
