#include "config.h"
#include <avr/interrupt.h>
#include "can_std/can_lib.h"
#include "can_func.h"
#include "../lib/can_defs.h"
#include "uart.h"
#include "ecu.h"

int RecIndex = 0;
int testvar = 0;

ISR(TIMER0_COMP_vect)
{
	int i;
	testvar++;
	if (testvar == 3) {
		testvar=0;
		RecIndex = 0;
		for (i=0;i<=9;i++) {
			USART0_Transmit(ecu_data[i]); 
		}
	}	
}

ISR(USART0_RX_vect)
{
	if (RecIndex < 228) {
		EcuData[RecIndex] = UDR0;
		RecIndex++;
	}
}
