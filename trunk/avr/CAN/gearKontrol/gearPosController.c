/*********************************************
 * Gear Pos controller
 *********************************************/

#include <config.h>
#include <prototyper.h>
#include <extern.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>

int gearPosRef = 25;
int Kp = 10;

void gearPosController(unsigned int adc)
{
	int posNorm = 0;
	int posErr = 0;
	int gearPosKp = 0;
	int retning = 2;

	posNorm = adc-GearPosMin;
	if(posNorm<0)
		posNorm = 0;

	posErr = gearPosRef - posNorm;

	if(abs(posErr)<4)
		posErr = 0;

	gearPosKp = posErr * Kp;

	if(gearPosKp>0)
		retning = 0;
	if(gearPosKp<0)
		retning = 1;

	gearPosKp = abs(gearPosKp);

	if(gearPosKp>255)
		gearPosKp = 255;

	if(retning==0)
	{
		motorControl(CC,gearPosKp);
	}
	else if(retning==1)
	{
		motorControl(CCW,gearPosKp);	
	}
	else 
	{
		motorControl(CC,0);
	} 

	char tempchar[5];

	itoa(gearPosRef, tempchar,10);
	sendtekst(tempchar);
	sendtekst(";");
	itoa(posNorm, tempchar,10);
	sendtekst(tempchar);
	sendtekst(";");
	itoa(gearPosKp, tempchar,10);
	sendtekst(tempchar);
	sendtekst(";");
	itoa(Kp, tempchar,10);
	sendtekst(tempchar);
	sendtekst("\n\r");
}

