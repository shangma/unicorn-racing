/*********************************************
 * Gear Torque Controller
 *********************************************/

#include <config.h>
#include <prototyper.h>
#include <extern.h>
#include <avr/io.h>
#include <stdlib.h>

int torqueRef = GEARFORCEREF;
int Kp = 1;

unsigned int torqueController(unsigned int current)
{
	int torqueErr = 0;
	int pwm = 0;

	torqueErr = torqueRef-current;

	pwm = torqueErr * Kp;

	// Saturation
	if(pwm<0)
		pwm = 0;
	if(pwm>255)
		pwm = 255;

	return (unsigned short int)pwm;
}
