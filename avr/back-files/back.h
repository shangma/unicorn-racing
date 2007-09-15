#ifndef _BACK_H_
#define _BACK_H_

#include "backDefines.h"

#include "backTimer.h"
#include "backRPM.h"
#include "backSPEED.h"
#include "backADC.h"

#define ioD ((ioD_t*)(&PORTD))

typedef struct{
  uint8_t fan:  1;
  uint8_t kill:  1;
  uint8_t clutch:  1;
} ioD_t;



#endif
