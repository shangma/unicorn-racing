#include "back.h"

void init(void){
  DDRB=0xFF;  /*1=output; 0=input*/
  DDRC=0xFC;
  DDRD=0x03;
  
  PORTB=0xFF;
  PORTC=0xFC;
  PORTD=0xFF;
  
  OSCCAL=0xb4;
  
  timerInit();
  rpmInit();
  gearInit();
/*  speedInit();*/
  adcInit();
  
  timeDiv=0;
  
  sei();
}

int main(void){
  uint8_t warnings;
  uint8_t dispGear;
  
  init();
  
  
  while(timeDiv<50){
    if(flags.newMeasure){
      flags.newMeasure=false;
      display(timeDiv*3,timeDiv/8,0x3F);
    }
  }
  warnings=0;
  
  while(1){
    if(flags.newMeasure){
      flags.newMeasure=false;
      
      warnings&=~0x01;
      warnings|=waterT();
      
      dispGear=gearGet(rpm,speed);
      display(rpm,dispGear,warnings);
    }
  
  }
}
