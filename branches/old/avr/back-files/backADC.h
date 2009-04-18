#ifndef _BACK_ADC_H_
#define _BACK_ADC_H_

#include "backDefines.h"

#define adcWaterT 0
#define adcOilP 1
#define adcMAP 2

void adcInit(void);

uint8_t doADC(uint8_t source);
uint8_t waterT(void);

#endif
