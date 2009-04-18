#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <util/delay.h>

#define segE _BV(0)
#define segD _BV(1)
#define segC _BV(2)
#define segP _BV(3)
#define segG _BV(4)
#define segF _BV(5)
#define segA _BV(6)
#define segB _BV(7)

#define disp1 (segB | segC)
#define disp2 (segA | segB | segG | segE | segD)
#define disp3 (segA | segB | segG | segC | segD)
#define disp4 (segF | segB | segG | segC)
#define disp5 (segA | segF | segG | segC | segD)
#define disp6 (segA | segF | segG | segE | segC | segD)
#define disp7 (segA | segB | segC)
#define disp8 (segA | segB | segC | segG | segE | segD | segF)
#define disp9 (segA | segB | segC | segG | segD | segF)
#define disp0 (segA | segB | segC | segE | segD | segF)
