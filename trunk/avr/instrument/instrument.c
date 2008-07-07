#include "instrument.h"

void init(void){
  DDRB=0xFF;  /*1=output; 0=input*/
  PORTB=0x00;
  
  DDRC=0xFF&(~pNeutralIN);
  PORTC=0x00|pNeutralIN;
  
  DDRD=0xFE;  /*set RX as input*/
  PORTD=0x01; /*to enable pullup*/

  timeDiv=2;

  display(180,4,3);

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
  
  gear=7;
  rpm=0;
  warnings=0;
  
  while(1){
    gear=0;
    if(flags.newMeasure){
      flags.newMeasure=false;
      rpm=(newRPM>>6);
      gear=newSpeed/rpm;
      if(gear<45){
        gear=0;
      }else if(gear<65){
        gear=1;
      }else if(gear<83){
        gear=2;
      }else if(gear<98){
        gear=3;
      }else if(gear<110){
        gear=4;
      }else if(gear<120){
        gear=5;
      }else{
        gear=6;
      }
      warnings=0;
      if(newCLT>cltCold){
        warnings|=0x01*((timeDiv&0x20)!=0);
      }else if(newCLT<cltStop){
        warnings|=0x01*((timeDiv&0x02)!=0);
      }else if(newCLT<cltWarn){
        warnings|=0x01;
      }else{
        warnings&=(~0x01);
      }
      if(newOilP<40){
        warnings|=0x02;
      }else{
        warnings&=(~0x02);
      }
    }
  
    if((PINC&pNeutralIN)==0){
      gear=7;
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
