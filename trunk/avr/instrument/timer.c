#include "timer.h"

void timerInit(void){
  TCCR2B=0x07; /*prescaler=1024*/
  TIMSK2|=_BV(TOIE2);
  timeDiv=0;
  timeOut=0x0f;
  preScaler=0;
	radioTimeout=0x0f;
}

ISR(TIMER2_OVF_vect){

/*
F_CPU=4MHz, Timer2 prescaler=1024 -> 3906Hz
*/

  TCNT2|=0x40;
  
  flags.refresh=true;
  timeDiv++;
  
  if(timeOut>0){
    timeOut--;
  }
  
	if(timeOut==0){
		flags.timeOut=true;
		flags.reqInfo=true;
    timeOut=0x0f;
	}
	
	if(flags.reply==true){
		flags.reply=false;
		flags.reqInfo=true;
    timeOut=0x0f;
		if(flags.forward && flags.online){
      PORTD&=~pConfigD;
      flags.forward=false;
    }else{
      PORTD|=pConfigD;
      flags.forward=true;
    }
		
		if(flags.online==false){
			radioTimeout++;
			switch(radioTimeout){
				case 1:
					PORTC|=pResetC;
					break;
				case 2:
					PORTC&=~pResetC;
					break;
				case 3:
					radioInit();
					break;
				case 4:
					radioInit2();
					break;
				case 5:
					if(PCIFR&_BV(PCIF2)){
						PCIFR|=_BV(PCIF2);
					}
					break;
				case 0x10:
					radioTimeout=0;
					break;
				default:
					if(PCIFR&_BV(PCIF2)){
						PCIFR|=_BV(PCIF2);
						flags.online=true;
					}
					break;
			}
		}else if(PCIFR&_BV(PCIF2)){
			flags.online=false;
			PCIFR|=_BV(PCIF2);
			radioTimeout=0x0f;
		}
	}
}
