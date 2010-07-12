#include "config.h"

unsigned int convertanalog(unsigned channel)
{
	unsigned int adlow = 0;
	unsigned int adhigh = 0; 
	
	ADMUX=(channel & 0x0f);
	ADCSRA=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS0)|(1<<ADPS1);
	ADCSRA|= (1<<ADSC);

	while(bit_is_set(ADCSRA,ADSC)); 
	adlow=ADCL; 
	adhigh=ADCH;

	return((unsigned int)((adhigh<<8)|(adlow & 0xFF)));
}
