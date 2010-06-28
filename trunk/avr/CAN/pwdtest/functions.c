#include <config.h>
#include <prototyper.h>
#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>

extern float pressOld; 
extern int kp;
extern float ki ;
extern int ref;

float intpressOld = 0;

void presscontroller(unsigned int adc)
{
	    char tempchar[5];
		int press = 0;
		int out = 0;
		int outP = 0;
		float outI = 0;   
        int err = 0; 
        float intpress = 0;
        	
		press = 0.17*adc-18.0;

        

		if(press<=0)
		    press = 0;
        
        err = (ref-press);
        intpress = intpressOld + err * 0.011;

        /* Save int */
		intpressOld = intpress;

		out = (int)(err*kp + intpress * ki);

        

		if(intpressOld>1000)
		   intpressOld = 1000;

		if(intpressOld<-1000)
		    intpressOld = -1000;

		if(out>dutymax)
		    out = dutymax;

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
		itoa(kp, tempchar,10); 
		sendtekst(tempchar);
		sendtekst(";");
		itoa((int)(ki*100), tempchar,10); 
		sendtekst(tempchar);
		sendtekst(";");
		itoa((int)(intpress), tempchar,10); 
		sendtekst(tempchar);
		sendtekst("\n\r");
}
