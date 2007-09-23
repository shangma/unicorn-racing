#include "backGear.h"

void gearInit(void){
  /*enable external interrupt*/
}

uint8_t gearGet(uint8_t rpm, uint8_t speed){
  uint16_t ratio;

  ratio=(speed*256)/rpm;
  
  if(!(PINB&pNeutral)){
    gear=0;
    return gear;
  }
  
  if(!(PINB&pClutch)){
    return gear;
  }
  
  if(ratio>256){
    gear=6;
  }else if(ratio>200){
    gear=5;
  }else if(ratio>150){
    gear=4;
  }else if(ratio>100){
    gear=3;
  }else if(ratio>50){
    gear=2;
  }else{
    gear=1;
  }
  return gear;
}
