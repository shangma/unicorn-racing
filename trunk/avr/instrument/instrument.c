#include "instrument.h"

void init(void){
  DDRB=0xFF;  /*1=output; 0=input*/
  
  PORTB=0x00;

/*  OSCCAL=0xb4;*/
  
  timerInit();
  
  CLKPR=_BV(CLKPCE);  /*Prescale by two (CLK=4MHz)*/
  CLKPR=0x01;
  
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
/*      warnings|=waterT();*/
      
/*      dispGear=gearGet(rpm,speed);*/
      dispGear=3;
      
      warnings&=~0x36;
/*      warnings|=shift(rpm,gear);*/
      
      display(rpm,dispGear,warnings);
    }
  
  }
  
}
