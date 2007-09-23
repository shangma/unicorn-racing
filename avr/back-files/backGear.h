#ifndef _BACK_GEAR_H_
#define _BACK_GEAR_H_

#include "backDefines.h"

#define pClutch _BV(2)
#define pNeutral _BV(1)

void gearInit(void);
uint8_t gearGet(uint8_t rpm, uint8_t speed);

#endif
