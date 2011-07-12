/*********************************************
 * Interrupt-service-rutiner
 *
 * Max er helt ude
 * Min er helt inde
 *
 *********************************************/

#include "config.h"
#include "extern.h"
#include "prototyper.h"
#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// ADC
unsigned int ADCconv = 0;
unsigned int pos = 0;
unsigned int posOld = 0;
unsigned int current = 0;
unsigned int currentOld = 0;
char setChannel = 0;
char channel = 0;

// PWM
unsigned int pwmOut = DUTYMAX;

// Gear
unsigned short int gearBut = 0;
unsigned short int gearRetning = 0;
unsigned short int gearActive = 0;
unsigned short int maxTilNeutral = 0; 
unsigned short int minTilNeutral = 0;
unsigned int gearPosTargetMax = GEARPOSMAX;
unsigned int gearPosTargetMin = GEARPOSMIN;

// Gear protection
unsigned int overCurrentCounter = 0;

// Debugging
char tempchar[10];
unsigned short int i = 0;

// ADC convert complete
ISR(ADC_vect,ISR_NOBLOCK)
{
	unsigned int adlow = 0;
	unsigned int adhigh = 0;
		
	// Read ADC channel
	channel = ADMUX & 0x07;

	// Read ADC convertion
    adlow=ADCL;
    adhigh=ADCH;
	ADCconv = (unsigned int)((adhigh<<8)|(adlow & 0xFF));

	// Channel 0 = Current sense	
	if(channel == 0)
	{
		current = (int)((double)FILTERKONSTANTCURRENT*ADCconv+(double)(1-FILTERKONSTANTCURRENT)*currentOld);
		currentOld = current;
	}

	// Channel 1 = Pos ADC convert
	if(channel == 1)
	{
		// Giver 0 helt inde og 1024 helt ude
		ADCconv = (ADCconv-1023)*-1;

		// Pos lav pass filter (for at undga at stoj oedelaegger skiftet)
		pos = (int)((double)FILTERKONSTANTPOS*ADCconv+(double)(1-FILTERKONSTANTPOS)*posOld);
		posOld = pos;
	}
}

 // UART0 interrupt
ISR(USART1_RX_vect)
{
	char data;
	data = UDR0;

	if(data == 'w')
	{
		sendtekst("w");
	}

	if(data == 's')
	{
		sendtekst("s");
	}
}

// Timer0 (8-bit) overflow interrupt (168 Hz)
ISR(TIMER0_OVF_vect)
{	
	// ADC
	// Change ADC channel
	ADMUX &= 0xf8;
	ADMUX |= setChannel++;
	//ADMUX |= 1;
	// Start ADC-convert
	ADCSRA|=(1<<ADSC);

	if(setChannel>=ADCtotnum)
		setChannel = 0;

	// PWM
	PWM_duty_cycle_A16_set(pwmOut);

	// Knapper
	gearBut = getBut();

	if(((gearBut==GEARUPBUT) || (gearBut==GEARDOWNBUT)) && (gearActive == 0))
	{

	_delay_ms(50); // Software prell

		gearBut = getBut();

		if(((gearBut==GEARUPBUT) || (gearBut==GEARDOWNBUT)) && (gearActive == 0))
		{
			// Gear op
			if((gearBut==GEARUPBUT) && (maxTilNeutral==0) && (minTilNeutral==0))
			{
				gearActive = 1;
				motorControl(IND, pwmOut);

				gearPosTargetMax = GEARPOSMAX;
				gearPosTargetMin = GEARPOSMIN;
		
				if(!((PINE&0b00100000)==0b00100000))
				{
					gearPosTargetMax = GEARPOSNEUTRALMAX;
					gearPosTargetMin = GEARPOSNEUTRALMIN;
				}
			}

			// Gear ned
			if((gearBut==GEARDOWNBUT) && (maxTilNeutral==0) && (minTilNeutral==0))
			{
				gearActive = 1;
				motorControl(UD, pwmOut);

				gearPosTargetMax = GEARPOSMAX;
				gearPosTargetMin = GEARPOSMIN;
	
				if(!((PINE&0b00100000)==0b00100000))
				{
					gearPosTargetMax = GEARPOSNEUTRALMAX;
					gearPosTargetMin = GEARPOSNEUTRALMIN;
				}
			}
		}
	}

	// Ign_Cut
	if((pos>(GEARPOSMID+GearMiddleDeadZone+IGNCUT)) || (pos<(GEARPOSMID-GearMiddleDeadZone-IGNCUT)))
		IgnCutOn;
	else
		IgnCutOff;

	// Stop_hvis_over_min/max,_set_retur
	if((pos > gearPosTargetMax) && ((minTilNeutral+maxTilNeutral)==0))
	{
		motorControl(0,0);
		maxTilNeutral = 1;
		minTilNeutral = 0;
	}
	else if((pos < gearPosTargetMin) && ((minTilNeutral+maxTilNeutral)==0))
	{
		motorControl(0,0);
		minTilNeutral = 1;
		maxTilNeutral = 0;
	}

	// Overcurrent protection
	if(current>GEARFORCECRITICALMAX)
		overCurrentCounter++;

	if((current <= GEARFORCECRITICALMAX) && (overCurrentCounter>0))
		overCurrentCounter--;

	if((overCurrentCounter>GEARFORCEMAXTIMEOUT1) && (pos>(GEARPOSMID+GearMiddleDeadZone)))
	{	
		sendtekst("\n\r SimiCurrent ! \n\r");
		minTilNeutral = 0;
		maxTilNeutral = 1;
	}
	if((overCurrentCounter>GEARFORCEMAXTIMEOUT1) && (pos<(GEARPOSMID-GearMiddleDeadZone)))
	{		
		sendtekst("\n\r SimiCurrent ! \n\r");
		minTilNeutral = 1;
		maxTilNeutral = 0;
	}

	if(overCurrentCounter>GEARFORCEMAXTIMEOUT2)
	{
		pwmOut = 0;
		hbroEnable(0);
	}

	// Til Neutral fra max
	if((maxTilNeutral == 1) && (pos>(GEARPOSMID+GearMiddleDeadZone)))
	{
		motorControl(IND, pwmOut);
	}
	else if((maxTilNeutral == 1) && (pos<=(GEARPOSMID+GearMiddleDeadZone)))
	{
		motorControl(0,0);
		minTilNeutral = 0;
		maxTilNeutral = 0;
		gearActive = 0;
	}

	// Til Neutral fra min
	if((minTilNeutral == 1) && (pos<(GEARPOSMID-GearMiddleDeadZone)))
	{
		motorControl(UD, pwmOut);
	}
	else if((minTilNeutral == 1) && (pos>=(GEARPOSMID-GearMiddleDeadZone)))
	{
		motorControl(0,0);
		minTilNeutral = 0;
		maxTilNeutral = 0;
		gearActive = 0;
	}

	// Debugging
	if((i%15)==0)
	{
		sendtekst("PINE: ");
		itoa(((PINE&0b11100000)>>5),tempchar,2);
		sendtekst(tempchar);
		sendtekst("  ");
	
		sendtekst("PWM: ");
		itoa(pwmOut,tempchar,10);
		sendtekst(tempchar);
		sendtekst("  ");

		sendtekst("POS: ");
		itoa(pos,tempchar,10);
		sendtekst(tempchar);
		sendtekst("  ");

		sendtekst("CS: ");
		itoa(current,tempchar,10);
		sendtekst(tempchar);
		sendtekst("  ");

		sendtekst("OC: ");
		itoa(overCurrentCounter,tempchar,10);
		sendtekst(tempchar);
		sendtekst("  ");

		sendtekst("TAGMAX: ");
		itoa(gearPosTargetMax,tempchar,10);
		sendtekst(tempchar);
		sendtekst("  ");

		sendtekst("TAGMIN: ");
		itoa(gearPosTargetMin,tempchar,10);
		sendtekst(tempchar);
		sendtekst("\n\r");
		i = 0;
	}
	i++;
}
