#include "gear.h"

void gearInit(void){
  EICRA=0x0a; //0b00001010 = falling edge
}

uint8_t calcGear(uint16_t speed, uint8_t rpm){

  uint8_t ratio;
  static uint8_t gear, gearTmp, tOffset, shiftUp, shiftDown;
  
/*  if(shift==1){
    shift=0;
    EIFR|=0x03;
  }*/
  
//  switch(EIFR){
  switch(PIND&(pUpD|pDownD)){
  case 0x00:
    shiftDown=0;
    shiftUp=0;
    if(((timeDiv-tOffset)&0x0f)==0){
    
      if(rpm>0){
        ratio=speed/rpm;
      }else{
        ratio=0;
      }
     
//    45 65 83 98 110 120
//    42 60 77 90 102 111
     
      if(ratio>48 && ratio<53){
        if(gearTmp==1){
          gear=1;
        }
        gearTmp=1;
      }else if(ratio>67 && ratio<72){
        if(gearTmp==2){
          gear=2;
        }
        gearTmp=2;
      }else if(ratio>82 && ratio<86){
        if(gearTmp==3){
          gear=3;
        }
        gearTmp=3;
      }else if(ratio>93 && ratio<97){
        if(gearTmp==4){
          gear=4;
        }
        gearTmp=4;
      }else if(ratio>100 && ratio<104){
        if(gearTmp==5){
          gear=5;
        }
        gearTmp=5;
      }else if(ratio>109 && ratio<113){
        if(gearTmp==6){
          gear=6;
        }
        gearTmp=6;
      }
    }
    break;
//  case 0x02:
  case pDownD:
//    EIFR|=0x02;
    
    shiftUp=0;
    if(shiftDown<11){
      shiftDown++;
    }
    if(shiftDown==10){
      tOffset=timeDiv;
      
      if(gear==7||gear==0){
        gear=1;
      }else if(gear>1){
        gear--;
      }
    }
    
    break;
//  case 0x01:
  case pUpD:
//    EIFR|=0x01;
    
    shiftDown=0;
    if(shiftUp<11){
      shiftUp++;
    }
    if(shiftUp==10){
      tOffset=timeDiv;
      
      if(gear==7||gear==0){
        gear=2;
      }else if(gear<6){
        gear++;
      }
    }
    
    break;
//  case 0x03:
  case pUpD|pDownD:
//    EIFR|=0x03;
    shiftUp=0;
    shiftDown=0;
    break;
  }
  
  if((PINC&pNeutralIN)==0){
    tOffset=timeDiv;
    gear=7;
  }else if(gear==7){
    gear=0;
  }
  
  return gear;
}
