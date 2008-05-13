#ifndef _SI_H_
#define _SI_H_

#include "instrumentDefines.h"

#include <avr/interrupt.h>

volatile uint8_t siCount;

void siInit(void);
void reqInfo(void);
void getInfo(void);

#endif
