#include "back.h"

void init(void){
  DDRB=0xF9;  /*1=output; 0=input*/
  DDRC=0xFF;
  DDRD=0xcF;
  
  PORTB=0xFF;
  PORTC=0xFF;
  PORTD=0xFF;
  
  OSCCAL=0xb4;
  
  timerInit();
  rpmInit();
  gearInit();
/*  speedInit();
  adcInit();*/
  
  sei();
}

int main(void){
  init();
  
  while(1){
    if(flags.newMeasure){
      flags.newMeasure=false;
      
      gear=gearGet(rpm,speed);
      display(rpm,gear,0);
    }
  
  }
}
