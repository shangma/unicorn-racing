#include "pshack.h"

void init(void){
  DDRB=0xF8;  /*1=output; 0=input*/
  
  PORTB=0xE3;

/*  OSCCAL=0xb4;*/
  
/*  sei();*/
}

int main(void){
  unsigned int b, c;
  uint8_t a;

  init();
  c=0;
  a=0;
  b=0;
  
  while(1){
  
    if(PINB&pLoadIN){
      a++;
      if(a>100){
        a=0;
        c=0;
        PORTB&=~pHaltOUT;
      }
    }else if(c<=10000){
      c++;
      a=0;
      if(!(PINB&pEndIN)){
        c+=2;
      }
    }
  
    if(c>10000){
      PORTB|=pHaltOUT;
      PORTB&=~pKillOUT;
      continue;
    }
  
    if(b>0){
      b--;
      PORTB|=pKillOUT;
    }else{
      PORTB&=~pKillOUT;
    }

    if((PINB&pUpIN)&&!(PINB&pLoadIN)&&c<2){
      PORTB|=pKillOUT;
      b=3000;
    }
  }
  
}
