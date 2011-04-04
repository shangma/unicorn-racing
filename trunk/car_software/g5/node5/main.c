//_____ I N C L U D E S ________________________________________________________
#include "config.h"
#include "can_std/can_lib.h"
#include <util/delay.h>
#include "can_new.h"
#include "../lib/can_defs.h"
#include "can_logning.h"
#include "adc.h"
#include "test_vars.h"

//_____ D E F I N I T I O N S __________________________________________________
#define ID_BASE 0x80
//_____ D E C L A R A T I O N S ________________________________________________
void init(void);

int main (void)
{	
	U8 canData=0;
	CLKPR = 0x80;  CLKPR = 0x00;  // Clock prescaler Reset
	uint8_t data_buf[8];
	uint8_t j,i=0;

//  Init CAN, UART, I/O
	init();

	sei();		/* Interrupt enable */

	Can_sei();		/* Enable general can interrupt */
	Can_set_tx_int();	/* Enable can tx interrupt */

    	// --- Init variables

	data_buf[0] = 10;
	data_buf[1] = 30;
	data_buf[2] = 50;
	data_buf[3] = 70;
	data_buf[4] = 90;
	data_buf[5] = 110;
	data_buf[6] = 130;
	data_buf[7] = 211;
	

	//AdcReadStart();		/* Start ADC read process */
	_delay_ms(500);
	data_buf[0] = 111;
	data_buf[1] = 111;
	data_buf[2] = 111;
	data_buf[3] = 111;
/*	can_send_ny(rpm_msgid, data_buf, 4);*/
/*	_delay_ms(500);*/
	while (1) {
		data_buf[0] = i;
		i++;
		data_buf[1] = (tIntReg>>8) & 0xff;
		data_buf[2] = tIntReg & 0xff;
		can_send_non_blocking(rpm_msgid, data_buf, 4);
		data_buf[0] = i;
		i++;
		_delay_ms(10);
		can_send_non_blocking(rpm_msgid, data_buf, 4);
		data_buf[0] = i;
		i++;
		_delay_ms(10);
		can_send_non_blocking(rpm_msgid, data_buf, 4);		
		data_buf[0] = i;
		i++;
		_delay_ms(10);
		can_send_non_blocking(rpm_msgid, data_buf, 4);
		_delay_ms(1000);
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
