#define F_CPU 4000000

#include "front.h"

/*volatile uint32_t display;*/

volatile struct{
  uint16_t  rpm:  10;
  uint8_t  flags:  6;
  uint8_t  gear:  8;
}display;

volatile struct{
  uint8_t newMeas:  1;
  uint8_t blink:  1;
}flags;

void init(void){
  DDRB=0xFF;  /*1=output; 0=input*/
  DDRC=0xFF;
  DDRD=0xcF;
  
  PORTB=0xFF;
  PORTC=0xFF;
  PORTD=0xFF;
  
  TCCR2=0x07; /*prescaler=1024*/
  TIMSK=_BV(TOIE2);
  
  sei();
  
  TCCR0=0x06;
  TCCR1B=0x06;
  
  OSCCAL=0xb4;
  
  display.rpm=0x3ff;
  display.flags=0xf;
  display.gear=0;
  
/*  _PORTB->p7=0;
  _PORTB->p0=0;*/
}

ISR(TIMER2_OVF_vect){
  uint8_t val;
  uint8_t speed;
  int16_t tmp;
  static uint8_t count;
  
  TCNT2=TCNT2&~0x40;
  val=TCNT1L;
  TCNT1L=0;
  flags.newMeas=1;

  display.rpm=0x3ff;
  
  if(val>=130){
    display.rpm&=~_BV(9);
  }else if(val>=120){
    display.rpm&=~_BV(8);
  }else if(val>=110){
    display.rpm&=~_BV(7);
  }else if(val>=100){
    display.rpm&=~_BV(6);
  }else if(val>=90){
    display.rpm&=~_BV(5);
  }else if(val>=80){
    display.rpm&=~_BV(4);
  }else if(val>=70){
    display.rpm&=~_BV(3);
  }else if(val>=60){
    display.rpm&=~_BV(2);
  }else if(val>=40){
    display.rpm&=~_BV(1);
  }else if(val>=20){
    display.rpm&=~_BV(0);;
  }

  speed=40;
  
  tmp=(speed*256)/val;
  if(tmp>256){
    display.gear=disp6;
  }else if(tmp>200){
    display.gear=disp5;
  }else if(tmp>150){
    display.gear=disp4;
  }else if(tmp>100){
    display.gear=disp3;
  }else if(tmp>50){
    display.gear=disp2;
  }else{
    display.gear=disp1;
  }
  
  if(val>90 && tmp<200){
    flags.blink=1;
  }else{
    flags.blink=0;
  }
  
  if(flags.blink){
    if(count>2){
      display.rpm=~display.rpm;
    }
    count++;
  }
  if(!flags.blink || count>4){
    count=0;
  }
  
}

int main(void) {
  int8_t c;
  init();
  PORTB=0;  
  while(1){
  
  if(flags.newMeas){
    flags.newMeas=0;
    PORTB&=~_BV(0);
    
    for(c=7;c>=0;c--){
      if(display.gear&_BV(c)){
        PORTB|=_BV(6);
      }else{
        PORTB&=~_BV(6);
      }
      _delay_us(100);
      PORTB|=_BV(7);
      _delay_us(100);
      PORTB&=~_BV(7);
    }
    
    for(c=5;c>=0;c--){
      if(display.flags&_BV(c)){
        PORTB|=_BV(6);
      }else{
        PORTB&=~_BV(6);
      }
      _delay_us(100);
      PORTB|=_BV(7);
      _delay_us(100);
      PORTB&=~_BV(7);
    }
    
    for(c=9;c>=0;c--){
      if(display.rpm&_BV(c)){
        PORTB|=_BV(6);
      }else{
        PORTB&=~_BV(6);
      }
      _delay_us(100);
      PORTB|=_BV(7);
      _delay_us(100);
      PORTB&=~_BV(7);
    }


    PORTB|=_BV(0);
  }
  }
}
