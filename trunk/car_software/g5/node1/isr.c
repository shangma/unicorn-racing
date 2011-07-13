#include "config.h"
#include "can_std/can_lib.h"
#include "can_func.h"
#include <util/delay.h>
#include "../lib/can_defs.h"
#include "uart.h"
#include "ecu.h"
#include "error.h"
#include "comm.h"
#include "queue.h"

int RecIndex = 0;	// Bruges til at tælle hvor mange bytes der er modtaget fra ECU'en
int testvar = 0;	// Tmp var for at køre TIMER0_COMP_vect langsommere

volatile uint8_t xbee_sending = 0;
volatile uint8_t nextId = 0;

/* Funktion der sender data request til ECU */
ISR(TIMER0_COMP_vect)
{
	int i;
	testvar++;
	if (testvar == 4) {
		if (RecIndex != 114 && EcuErrorTmp < 5) { // Test for fejl
			EcuErrorTmp++;
			if (EcuErrorTmp == 5) {
				EcuCommError = 1;
			}
		} else if (EcuErrorTmp > 0 && RecIndex == 114) {
			EcuErrorTmp--;
			EcuCommError = 0;
		}
		testvar=0;
		RecIndex = 0;
		for (i=0;i<=9;i++) {		// Send data req streng
			USART0_Transmit(ecu_data[i]); 
		}
	}
}

/* Funktion til at læse data fra ECU */
ISR(USART0_RX_vect)
{
	if (RecIndex <= 114) {			// Der skal modtages 228 bytes fra ECU'en
		EcuData[RecIndex] = UDR0;	// Gem data fra ECU
		RecIndex++;
	}
}

/* ISR to take care of xbee data sending */
ISR(USART1_UDRE_vect)
{
	uint8_t tmp;

	/* if xbee_seq_index is less than 3 send package start sequence */
	if (xbee_seq_index<3) {
		UDR1 = start_sequence[xbee_seq_index++];
	}else{
		QUEUE_GET(my_q, tmp);
		if (nextId == 0) {
			nextId = valueObjects[tmp].length+8;
		}
		UDR1 = tmp;
		nextId = nextId - 8;
	    	if (nextId == 0) {
			if (QUEUE_GET_NUM_ELE(my_q) <= 4) {
				xbee_sending = 0;
				Usart1_tx_ei_dis();
			}
		}
	}
}
