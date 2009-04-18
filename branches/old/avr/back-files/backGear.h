#ifndef _BACK_GEAR_H_
#define _BACK_GEAR_H_

#include "backDefines.h"
#include <avr/interrupt.h>
#define pClutch _BV(6)
#define pNeutral _BV(7)

volatile uint8_t gearDir;

void gearInit(void);
uint8_t gearGet(uint8_t rpm, uint8_t speed);

#endif
