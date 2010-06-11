#include "config.h"
#include "uart.h"
#include "comm.h"
#include "ecu.h"
#include "error.h"

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

}
