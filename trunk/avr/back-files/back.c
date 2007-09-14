#include "back.h"

void init(void){
  timerInit();
  rpmInit();
  speedInit();
  adcInit();
}

int main(void){
  init();
  
  while(1){
  }
}
