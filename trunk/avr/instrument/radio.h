#ifndef _RADIO_H_
#define _RADIO_H_

#include "instrumentDefines.h"
#include <util/delay.h>

#define pConfigB _BV(0)
#define pConfigD _BV(7)

void radioInit(void);

#endif
