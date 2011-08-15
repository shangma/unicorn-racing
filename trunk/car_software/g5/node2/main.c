//_____ I N C L U D E S ________________________________________________________
#include "config.h"
#include "can_std/can_lib.h"
#include "can_std/can_drv.h"
#include <util/delay.h>
#include "can.h"
#include "../lib/can_defs.h"
#include "display/display.h"
#include "prototyper.h"

//_____ D E F I N I T I O N S __________________________________________________
#define ID_BASE 0x80
//_____ D E C L A R A T I O N S ________________________________________________
void init(void);

int main (void)
{	
	int tmp,i;
	CLKPR = 0x80;  CLKPR = 0x00;  // Clock prescaler Reset

	uint8_t test_rx[8];

//  Init CAN, UART, I/O
	init();
	TWI_init();
	uartinit();

	sei();		/* Interrupt enable */

	Can_sei();		/* Enable general can interrupt */
	Can_set_tx_int();	/* Enable can tx interrupt */
	Can_set_rx_int();	/* Enable can rx interrupt */

	// Recieve buffer
	U8 rpm_response_buffer[8];
	st_cmd_t rpm_msg;
	/*
	 *	Kode til hurtig test af can 
	 */
	rpm_msg.pt_data = rpm_response_buffer;
	rpm_msg.status = 0;

	can_update_rx_msg(&rpm_msg, rpm_msgid, 8);
//	rpm_msg.status = 0;
//	can_update_rx_msg(&rpm_msg, rpm_msgid, 8);

    	// --- Init variables

	/* Init user led 0 & 1 */
	DDRB |= (1<<PB6 | 1<<PB5);
	PORTB |= (1<<PB6 | 1<<PB5);

	i = 1;

	test_rx[0] = 38;
	test_rx[1] = 1;
//	test_rx[2] = 124;
//	sendtekst("Beep\n");
	while (1) {
//		_delay_ms(4000);
		can_send_non_blocking(rpm_msgid, test_rx, 8);

		for (i=0;i<=6;i+=2){
			test_display(LED0_7_ADDR, LED_ON<<i,0);
			_delay_ms(100);
		}
		for (i=0;i<=6;i+=2){
			test_display(LED0_7_ADDR, 0,LED_ON<<i);
			_delay_ms(100);
		}
		test_display(LED0_7_ADDR, 0,0);
		for (i=0;i<=6;i+=2){
			test_display(LED8_15_ADDR, LED_ON<<i,0);
			_delay_ms(100);
		}
		for (i=0;i<=6;i+=2){
			test_display(LED8_15_ADDR, 0,LED_ON<<i);
			_delay_ms(100);
		}
		test_display(LED8_15_ADDR, 0,0);

		PORTB ^= (1<<PB6);
	}
	return 0;
}

void init(void)
{
    // CAN Init
    can_init(0);
}
