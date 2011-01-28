//_____ I N C L U D E S ________________________________________________________
#include "config.h"
#include "can_std/can_lib.h"
#include <util/delay.h>
#include "can_func.h"
#include "../lib/can_defs.h"
#include "can_logning.h"
#include "adc.h"

//_____ D E F I N I T I O N S __________________________________________________
#define ID_BASE 0x80
//_____ D E C L A R A T I O N S ________________________________________________
void init(void);

int main (void)
{	
	U8 canData=0;
	CLKPR = 0x80;  CLKPR = 0x00;  // Clock prescaler Reset
	uint8_t data_buf[8];
	int i;

//  Init CAN, UART, I/O
	init();

	sei();		/* Interrupt enable */

    	// --- Init variables
	tx_remote_msg.pt_data = &tx_remote_buffer[0];
	tx_remote_msg.status = 0;

	tx_std_msg.pt_data = &tx_buffer[0];
	tx_std_msg.status = 0;

	data_buf[0] = 10;
	data_buf[1] = 30;
	data_buf[2] = 50;
	data_buf[3] = 70;
	data_buf[4] = 90;
	data_buf[5] = 110;
	data_buf[6] = 130;
	data_buf[7] = 211;
	

	Can_sei();		/* Enable general can interrupt */
	Can_set_tx_int();	/* Enable can tx interrupt */

	AdcReadStart();		/* Start ADC read process */
	_delay_ms(500);
	data_buf[0] = 111;
	data_buf[1] = 111;
	data_buf[2] = 111;
	data_buf[3] = 111;
	can_send_ny(rpm_msgid, data_buf, 4);
	_delay_ms(500);
	while (1) {	
/*			CountDown();*/
/*			while (QH->timeout == 0){*/
/*				ReloadQueue();*/
/*			}*/
/*			data_buf[0] = QH->adc;*/
/*			data_buf[1] = QH->interval/20;*/
/*			data_buf[2] = QH->timeout/20;*/
/*			data_buf[3] = QH->next->timeout/20;*/
/*			//data_buf[4] = QH->next->next->timeout/20;		*/
/*			can_send_ny(rpm_msgid, data_buf, 4);*/
/*			_delay_ms(1000);*/
/*		can_send(rpm_msgid, 8, 1);*/
/*		_delay_ms(1000);*/
/*		can_send_test(rpm_msgid, data_buf, 8);*/
/*		_delay_ms(1000);*/
/*		can_send_standart_data(&watPack, data_buf);*/
/*		_delay_ms(1000);*/
	}
	return 0;
}

void init(void)
{
    // CAN Init
    can_init(0);

    // IO Init
    DDRA = 0xFF;
}
