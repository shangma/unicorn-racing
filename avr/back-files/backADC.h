#ifndef _BACK_ADC_H_
#define _BACK_ADC_H_

#include "backDefines.h"

#define admux ((admux_t*)(&ADMUX))

void adcInit(void);
int doADC(uint8_t source);
uint8_t adcCT(uint8_t);
uint8_t adcOP(uint8_t);
uint8_t adcIAT(uint8_t);
uint8_t adcMAP(uint8_t);


typedef struct {
  uint8_t refs: 2;
  uint8_t adlar: 1;
  uint8_t res: 1;
  uint8_t source: 4;
} admux_t;

#endif
