#include "backADC.h"

void adcInit(void){
  ADCSRA=_BV(ADEN) | _BV(ADPS2);  //enable adc, prescale=16 (use 32 for 10bit)
  ADMUX=_BV(REFS0)|_BV(ADLAR);  //ref=AVcc, left adjusted result
}

uint8_t doADC(uint8_t source){
  source&=0x0F;
  ADMUX&=0xF0;
  ADMUX|=source;
  ADCSRA&=~_BV(ADIF);
  ADCSRA|=_BV(ADSC);
  while(!(ADCSRA&_BV(ADIF))){
  }
  return ADCH;
}

uint8_t waterT(void){
  uint8_t adcValue;
  
  adcValue=doADC(adcWaterT);
  
  if(adcValue<60){                    //cold
    return 0x01 && !(timeDiv&0x14);
    /*fan off*/
  }else if(adcValue<100){             //ok, fan off
    return 0;
    /*fan off*/
  }else if(adcValue<110){             //ok
    return 0;
  }else if(adcValue<120){             //ok, fan on
    return 0;
    /*fan on*/
  }else if(adcValue<130){             //hot
    return 0x01;
    /*fan on*/
  }else if(adcValue<140){             //very hot
    return 0x01 && (timeDiv&0x04);
    /*fan on*/
  }else{                              //stop
    return 0x01 && (timeDiv&0x02);
    /*fan on*/
    /*kill engine*/
  }
}
