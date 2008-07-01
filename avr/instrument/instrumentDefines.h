#ifndef _INSTRUMENT_DEF_H_
#define _INSTRUMENT_DEF_H_

#define F_CPU 4000000

#define true 1
#define false 0

#include <avr/io.h>
#include <stdint.h>

volatile uint8_t timeDiv, newWarnings, timeOut, preScaler;

volatile uint16_t newRPM, newSpeed;

volatile struct{
  uint8_t refresh: 1;
  uint8_t newMeasure: 1;
  uint8_t reqInfo: 1;
  uint8_t newByte: 1;
  uint8_t reply: 1;
  uint8_t forward: 1;
} flags;

#endif
