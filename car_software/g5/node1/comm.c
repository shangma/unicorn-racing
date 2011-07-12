#include "config.h"
#include "uart.h"
#include "comm.h"
#include "ecu.h"
#include <util/delay.h>
#include "error.h"
#include "queue.h"

volatile uint8_t xbee_seq_index=0;

void xbee_send_trigger( void )
{
	/* TODO
	 * 
	 *
	 * -Trigger package send 
	 */
	/* Check if xbee is already sending and if true just return */
	if (xbee_sending) return;

	/* If number of bytes in send buffer is greater than X send data */
	if (QUEUE_GET_NUM_ELE(my_q)>=20){
		xbee_sending = 1;
		xbee_seq_index = 0;
	    	Usart1_tx_ei_en();	/* Remove when done testing */
		UDR1 = start_sequence[xbee_seq_index++];
	}
	return;
}

void send_status( void )
{
	USART1_Transmit((U8)123);	// Pakke start
	USART1_Transmit((U8)255);
	USART1_Transmit((U8)10);
	USART1_Transmit((U8)EcuCommError);	// Ecu error var
	USART1_Transmit((U8)EcuData[RPMSTART]);		// Send RPM
	USART1_Transmit((U8)EcuData[RPMSTART+RPMLENGTH-1]);
	USART1_Transmit((U8)EcuData[SPEEDSTART]);	// Send Hastighed
	USART1_Transmit((U8)EcuData[SPEEDSTART+SPEEDLENGTH-1]);
	USART1_Transmit((U8)EcuData[46]);	// Vand temp
	USART1_Transmit((U8)EcuData[47]);
	USART1_Transmit((U8)EcuData[48]);	// Luft temp
	USART1_Transmit((U8)EcuData[49]);
	USART1_Transmit((U8)EcuData[66]);	// Batt V
	USART1_Transmit((U8)EcuData[67]);		
	USART1_Transmit((U8)EcuData[POTSTART]);	// Pot 
	USART1_Transmit((U8)EcuData[POTSTART+POTLENGTH-1]);		
	USART1_Transmit((U8)EcuData[MAPSTART]);	// Map 
	USART1_Transmit((U8)EcuData[MAPSTART+MAPLENGTH-1]);	
	USART1_Transmit((U8)EcuData[96]);	// gX (acc)
	USART1_Transmit((U8)EcuData[97]);		
	USART1_Transmit((U8)EcuData[98]);	// gy (acc)
	USART1_Transmit((U8)EcuData[99]);		
	USART1_Transmit((U8)EcuData[100]);	// gz (acc)
	USART1_Transmit((U8)EcuData[101]);		
	USART1_Transmit((U8)EcuData[68]);	// lambda
	USART1_Transmit((U8)EcuData[69]);		
	USART1_Transmit((U8)EcuData[78]);	// injectorTime
	USART1_Transmit((U8)EcuData[79]);		
	USART1_Transmit((U8)EcuData[82]);	// ignitionTime
	USART1_Transmit((U8)EcuData[83]);		
	USART1_Transmit((U8)EcuData[74]);	// engine load
	USART1_Transmit((U8)EcuData[75]);		
	USART1_Transmit((U8)EcuData[56]);	// trigger error
	USART1_Transmit((U8)EcuData[57]);		
}
