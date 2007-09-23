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
  
  if(adcValue>145){
    /*kill engine*/
  }
  
  if(adcValue>115){
    /*fan on*/
  }else if(adcValue<105){
    /*fan off*/
  }
  
  if(adcValue>140){
    return 0x01*((timeDiv&0x02)!=0);
  }else if(adcValue>130){
    return 0x01*((timeDiv&0x04)!=0);
  }else if(adcValue>120){
    return 0x01;
  }else if(adcValue>70){
    return 0;
  }else{
    return 0x01*((timeDiv&0x14)==0);
  }

}
