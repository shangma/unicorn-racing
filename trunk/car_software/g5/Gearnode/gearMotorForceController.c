/*********************************************
 * Gear Torque Controller
 *********************************************/

#include "config.h"
#include "extern.h"
#include "prototyper.h"
#include <avr/io.h>
#include <stdlib.h>

int Kp = 100;
// Debugging
char tempchar[10];

unsigned int torqueController(unsigned int current)
{
	int torqueErr = 0;
	int pwm = 0;

	// Eksperimentielt (for at undga at PWM gAr helt i 0 ved start og bremsestrom)
	//if(current>GEARFORCEREF/2)
	//	current = GEARFORCEREF/2;

	torqueErr = FREF - current;

	pwm = torqueErr * Kp;

	// Saturation
	if(pwm<0)
		pwm = 0;
	if(pwm>DUTYMAX)
		pwm = DUTYMAX;

	return (unsigned short int)pwm;
}

