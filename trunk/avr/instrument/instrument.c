#include "instrument.h"

void init(void){
  DDRB=0xFF;  /*1=output; 0=input*/
  PORTB=0x00;
  
  DDRC=0xFF;
  PORTC=0x00;
  
  DDRD=0xFE;  /*set RX as input*/
  PORTD=0x01; /*to enable pullup*/

/*  OSCCAL=0xb4;*/
  
  siInit();
  timerInit();
/*  dectInit();*/
  
  CLKPR=_BV(CLKPCE);  /*Allow prescaler change*/
  CLKPR=0x01;         /*Prescale by two (CLK=4MHz)*/
  
  radioInit();
  
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
      rpm=(newRPM>>6);
/*      gear=calcGear();*/
      gear=(newSpeed>>6);
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
  
  }
  
}
