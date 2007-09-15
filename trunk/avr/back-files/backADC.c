#include "backADC.h"

void adcInit(void){
  ADCSRA = _BV(ADEN) | _BV(ADPS2);
}

int doADC(uint8_t source){
  admux->source=source;
  ADCSRA |= _BV(ADSC);
  while (ADCSRA & _BV(ADSC)) {}
  return ADCW;
}

uint8_t adcCT(uint8_t adc){ /*Coolant Temperature*/
  static uint8_t temp;
  
  if (adc){
    temp=doADC(0);
    /*Convert ADC value to temperature*/
  }
  return temp;
}

uint8_t adcOP(uint8_t adc){ /*Oil Pressure*/
  static uint8_t temp;
  
  if (adc){
    temp=doADC(1);
    /*Convert ADC value to pressure*/
  }
  return temp;
}

uint8_t adcIAT(uint8_t adc){  /*Intake Air Temperature*/
  static uint8_t temp;
  
  if (adc){
    temp=doADC(2);
    /*Convert ADC value to temperature*/
  }
  return temp;
}

uint8_t adcMAP(uint8_t adc){  /*Mainfold Absolute Pressure*/
  static uint8_t temp;
  
  if (adc){
    temp=doADC(3);
    /*Convert ADC value to pressure*/
  }
  return temp;
}
