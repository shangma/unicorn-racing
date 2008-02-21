#include "pshack.h"

void init(void){
  DDRB=0xFC;  /*1=output; 0=input*/
  
  PORTB=0xE7;

/*  OSCCAL=0xb4;*/
  
/*  sei();*/
}

int main(void){
  unsigned int c;
  uint8_t a;

  init();
  c=0;
  a=0;
  
  while(1){
    if((PINB&pUpIN) && (PINB&pDownIN)){ /*no buttons pressed*/
      a++;
      if(a>100){                        /*for 100 cycles (debounce)*/
        c=0;
        PORTB&=~pUpOUT;                 /*halt actuator*/
        PORTB&=~pDownOUT;
      }
    }else if(c<=10000){
      c++;                              /*count cycles of button pressed*/
      a=0;                              /*stop at 10000*/
    }
    
    if(c>10000){                        /*if button pressed for 10000 cycles*/
      PORTB&=~pUpOUT;                   /*halt actuator*/
      PORTB&=~pDownOUT;
      continue;
    }
  
    if(!(PINB&pUpIN) && (PINB&pDownIN)){
      PORTB&=~pDownOUT;
      PORTB|=pUpOUT;
    }else if(!(PINB&pDownIN) && (PINB&pUpIN)){
      PORTB&=~pUpOUT;
      PORTB|=pDownOUT;
    }
  }
  
}
