//_____ I N C L U D E S ________________________________________________________
#include "config.h"
#include "can_std/can_lib.h"
#include "can_std/can_drv.h"
#include <util/delay.h>
#include <util/atomic.h>
#include "twi/twi.h"
#include "can.h"
#include "../../lib/can_defs.h"
#include "display/display.h"
#include "prototyper.h"
#include "data.h"

//_____ D E F I N I T I O N S __________________________________________________
#define ID_BASE 0x80
//_____ D E C L A R A T I O N S ________________________________________________
void init(void);

int main (void)
{	
	int tmp,i;
	CLKPR = 0x80;  CLKPR = 0x00;  // Clock prescaler Reset

	uint8_t test_rx[8];

	uint8_t data;
	char streng[10];

//  Init CAN, UART, I/O
	init();
	TWI_init();
	uartinit();

	sei();		/* Interrupt enable */

	set_blink_rate(LED8_15_ADDR, LED_BLINK1, 20, 100);
	set_blink_rate(LED8_15_ADDR, LED_BLINK2, 0, 5);
	set_blink_rate(LED0_7_ADDR, LED_BLINK2, 0, 5);
	set_blink_rate(LED0_7_ADDR, LED_BLINK1, 20, 100);

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
	sendtekst("Beep\n");
	while (1) {
//		_delay_ms(1000);
//		can_send_non_blocking(rpm_msgid, test_rx, 8);
		_delay_ms(20);
		set_rpm(params.rpm, LED_ON);

//		itoa(data, streng, 10);
//		sendtekst(streng);
//		sendtekst("\n");		

/*		_delay_ms(100);*/
/*		ATOMIC_BLOCK(ATOMIC_FORCEON)*/
/*		{*/
/*			SEG_1(LED_ON);*/
/*		}*/
/*		_delay_ms(100);*/
/*		ATOMIC_BLOCK(ATOMIC_FORCEON)*/
/*		{*/
/*			SEG_2(LED_ON);*/
/*		}*/
/*		_delay_ms(100);*/
/*		ATOMIC_BLOCK(ATOMIC_FORCEON)*/
/*		{*/
/*			SEG_3(LED_ON);*/
/*		}*/
/*		_delay_ms(100);*/
/*		ATOMIC_BLOCK(ATOMIC_FORCEON)*/
/*		{*/
/*			SEG_4(LED_ON);*/
/*		}*/
/*		_delay_ms(100);*/
/*		ATOMIC_BLOCK(ATOMIC_FORCEON)*/
/*		{*/
/*			SEG_5(LED_ON);*/
/*		}*/
/*		_delay_ms(100);*/
/*		ATOMIC_BLOCK(ATOMIC_FORCEON)*/
/*		{*/
/*			SEG_6(LED_ON);*/
/*		}*/
/*		_delay_ms(100);*/
/*		ATOMIC_BLOCK(ATOMIC_FORCEON)*/
/*		{*/
/*			SEG_7(LED_ON);*/
/*		}*/
/*		_delay_ms(100);*/
/*		ATOMIC_BLOCK(ATOMIC_FORCEON)*/
/*		{*/
/*			SEG_8(LED_ON);*/
/*		}*/
/*		_delay_ms(100);*/
/*		ATOMIC_BLOCK(ATOMIC_FORCEON)*/
/*		{*/
/*			SEG_9(LED_ON);*/
/*		}*/

		PORTB ^= (1<<PB6);
	}
	return 0;
}

void init(void)
{
    // CAN Init
    can_init(0);
}
