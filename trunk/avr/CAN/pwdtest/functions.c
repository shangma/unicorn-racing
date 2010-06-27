#include <config.h>
#include <prototyper.h>
#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>

void presscontroller(unsigned int adc)
{
	    char tempchar[5];
		int press = 0;
		int out = 0;
		int outP = 0;
		float outI = 0;    

		extern float pressOld; 
		extern int p;
		extern float i ;
		extern int ref;
	
		press = 0.17*adc-18.0;

		if(press<=0)
		    press = 0;

		outP = (ref-press)*p;

		outI = (((ref-press)*0.01+pressOld)*i);

		pressOld = pressOld + (ref-press)*(0.0036);

		out = (int)(outP + outI);

		if(pressOld>5000)
		   pressOld = 5000;

		if(pressOld<-5000)
		    pressOld = -5000;

		if(out>1023)
		    out = 1023;

		if(out<=0)
		    out = 0;

		PWM_duty_cycle_A16_set(out);

		itoa(ref, tempchar,10); 
		sendtekst(tempchar);
		sendtekst(";");
		itoa(press, tempchar,10); 
		sendtekst(tempchar);
		sendtekst(";");
		itoa(out, tempchar,10); 
		sendtekst(tempchar);
		sendtekst(";");
		itoa(p, tempchar,10); 
		sendtekst(tempchar);
		sendtekst(";");
		itoa((int)(i*100), tempchar,10); 
		sendtekst(tempchar);
		sendtekst("\n\r");
}
