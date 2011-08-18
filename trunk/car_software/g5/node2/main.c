//_____ I N C L U D E S ________________________________________________________
#include "config.h"
#include "can_std/can_lib.h"
#include "can_std/can_drv.h"
#include <util/delay.h>
#include <util/atomic.h>
#include "twi/twi.h"
#include "can.h"
#include "../lib/can_defs.h"
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

	int8_t data;
	char streng[10];

//  Init CAN, UART, I/O
	init();
	TWI_init();
	uartinit();

	sei();		/* Interrupt enable */

/*-----------------------------------------------------------------*
 *----------------------------Display setup -----------------------*
 *-----------------------------------------------------------------*/

	/* Set blink rates */
	set_blink_rate(LED0_7_ADDR, LED_BLINK1, 20, 100);
	set_blink_rate(LED0_7_ADDR, LED_BLINK2, 0, RPM_LED_DUTYCYCLE*2.56);

	set_blink_rate(LED8_15_ADDR, LED_BLINK1, (1.0/RPM16_RATE)*252, RPM16_DUTYCYCLE*2.56);
	set_blink_rate(LED8_15_ADDR, LED_BLINK2, 0, RPM_LED_DUTYCYCLE*2.56);

	set_blink_rate(SEG_ADDR, LED_BLINK1, 20, 100);
	set_blink_rate(SEG_ADDR, LED_BLINK2, 0, SEG_DUTYCYCLE*2.56);


/*-----------------------------------------------------------------*
 *----------------------------CAN interrupt setup -----------------*
 *-----------------------------------------------------------------*/
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

	sendtekst("Beep\n");
	display_test();
	while (1) {
		_delay_ms(20);

		set_rpm(params.rpm, LED_BLINK2);

		buttons_state = get_buttons(LED_BUTTONS_ADDR) & (BUTTON1 | BUTTON2);
		if (buttons_state == 2) {
			set_leds(LED_BUTTONS_ADDR, LED_ON<<LED_BUTTON_1);
		} else if (buttons_state == 1) {
			set_leds(LED_BUTTONS_ADDR, LED_ON<<LED_BUTTON_2);
		} else if (buttons_state == 0) {
			set_leds(LED_BUTTONS_ADDR, LED_ON<<LED_BUTTON_1 | LED_ON<<LED_BUTTON_2);
		} else {
			set_leds(LED_BUTTONS_ADDR, 0);
		}

/*		if (params.waterTemp <= 70) {*/
/*			set_leds(LED_BUTTONS_ADDR, LED_ON<<LED_INDI1);*/
/*		} else if (params.waterTemp > 70) {*/
/*			set_leds(LED_BUTTONS_ADDR, LED_ON<<LED_INDI4);*/
/*		}*/
	
		if (params.batteryV <= 135) {
			set_leds(LED_BUTTONS_ADDR, LED_ON<<LED_INDI2);
		} else if (params.batteryV > 135) {
			set_leds(LED_BUTTONS_ADDR, LED_ON<<LED_INDI5);
		}
			
			
		itoa(params.batteryV, streng, 10);
		sendtekst(streng);
		sendtekst("\n");		
		PORTB ^= (1<<PB6);
	}
	return 0;
}

void init(void)
{
    // CAN Init
    can_init(0);
}
