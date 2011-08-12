/*********************************************
 * Unicorn main gear kontrol
 *********************************************/

#include "config.h"
#include "extern.h"
#include "prototyper.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include "can_std/can_lib.h"
#include "can_new.h"
#include "../lib/can_defs.h"

int main(void)
{
	_delay_ms(1000);
	ioinit();
	uartinit();
	can_init(0);
	pwm16Init();
	adcInit(1);
	U8 rpm_response_buffer[8];
	st_cmd_t rpm_msg;

	//counter0Init();
	//hbroEnable(1);
	sei();
	
	sendtekst("\n\rUnicorn Gearnode v1.0 \n\r");


	/*
	 *	Kode til hurtig test af can 
	 */
	rpm_msg.pt_data = rpm_response_buffer;
	rpm_msg.status = 0;

	can_update_rx_msg(&rpm_msg, rpm_msgid, 8);

	Can_sei();
	Can_set_tx_int();
	Can_set_rx_int();

	while (1)
	{
	}
    return 0;
}
