#include "instrument.h"

void init(void){
  DDRB=0xFF;  /*1=output; 0=input*/
  
  PORTB=0x00;

/*  OSCCAL=0xb4;*/
  
  siInit();
  timerInit();
  
  CLKPR=_BV(CLKPCE);  /*Prescale by two (CLK=4MHz)*/
  CLKPR=0x01;
  
  sei();
}

int main(void){
  uint8_t gear, rpm, warnings;
  
  init();
  
  while(timeDiv<50){
    if(flags.refresh){
      flags.refresh=false;
      display(timeDiv*3,timeDiv/8,0x3F);
    }
  }
  
  gear=7;
  rpm=0;
  warnings=0;
  
  while(1){
    if(flags.newMeasure){
      flags.newMeasure=false;
      rpm=newRPM;
/*      gear=calcGear();*/
      gear=newSpeed;
      warnings=newWarnings;
    }
  
    if(flags.refresh){
      flags.refresh=false;
      
      /*make blinking effect on warnings*/
      
      display(rpm,gear,warnings);
    }
    
    if(flags.reqInfo){
      flags.reqInfo=false;
      reqInfo();
    }
    
    if(flags.newByte){
      flags.newByte=false;
      getInfo();
    }
  
  }
  
}
