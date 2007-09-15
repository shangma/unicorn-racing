#ifndef _BACK_DEF_H_
#define _BACK_DEF_H_

#define F_CPU 8000000

#define true 1
#define false 0

#define new 1
#define last 0

#include <avr/io.h>
#include <stdint.h>

volatile struct{
  uint8_t newMeasure: 1;
} flags;

#endif
