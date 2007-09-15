#include "back.h"

void init(void){
  timerInit();
  rpmInit();
  speedInit();
  adcInit();
  ioD->kill=false;
}

int main(void){
  init();
  
  while(1){
    if (flags.newMeasure==true){
    
      flags.newMeasure=false;
      
      /*Check Temperature*/
      if (adcCT(last)>150){
        ioD->kill=true;
      }else if (adcCT(last)>100){
        ioD->fan=true;
      }else{
        ioD->fan=false;
      }
    
      /*Calculate gear ratio and estimate gear*/
      if (!ioD->clutch){
      
      }
      
    }
  }
}
