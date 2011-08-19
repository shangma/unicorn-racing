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

char gearbut = 0;

int main (void)
{	
	int tmp,i;
	CLKPR = 0x80;  CLKPR = 0x00;  // Clock prescaler Reset

	// GearKontakter
	DDRC&=~(1<<PC7); // Neutral
	PORTC |= (1<<PC7); // Neutral pull-up
	DDRE&=~(1<<PE6); // Knap1 
	DDRE&=~(1<<PE7); // Knap2

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

	set_blink_rate(LED_BUTTONS_ADDR, LED_BLINK1, 20, 100);
	set_blink_rate(LED_BUTTONS_ADDR, LED_BLINK2, 0, SEG_DUTYCYCLE*2.56);


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
	rpm_msg.status = 0;
	can_update_rx_msg(&rpm_msg, rpm_msgid, 8);

    	// --- Init variables

	/* Init user led 0 & 1 */
	DDRB |= (1<<PB6 | 1<<PB5);
	PORTB |= (1<<PB6 | 1<<PB5);

	sendtekst("Beep\n");
	display_test();

	char dataout[] = {38,0};

	while (1) {
		/* TODO 
		 * Change LED_BLINK2 to LED_ON when regulator problem is fixed 
		 */

		_delay_ms(20);

		/* Display rpm */
		set_rpm(params.rpm, LED_BLINK2);

		// Geat buttons to CAN
		gearbut = getBut();
		dataout[1] = gearbut;
//		can_send_non_blocking(rpm_msgid, dataout, 2);


		/* Display bottons code */
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

		/* Indicator for water temp */
		if (params.waterTemp <= 100) {
			indi_leds_state |= (LED_BLINK2<<LED_INDI1);
			indi_leds_state &= ~(LED_BLINK2<<LED_INDI4);
		} else if (params.waterTemp > 100) {
			indi_leds_state |= (LED_BLINK2<<LED_INDI4);
			indi_leds_state &= ~(LED_BLINK2<<LED_INDI1);
		}

		/* Indicator for batt ok */
		if (params.batteryV <= 135) {
			indi_leds_state |= (LED_BLINK2<<LED_INDI2);
			indi_leds_state &= ~(LED_BLINK2<<LED_INDI5);
		} else if (params.batteryV > 135) {
			indi_leds_state |= (LED_BLINK2<<LED_INDI5);
			indi_leds_state &= ~(LED_BLINK2<<LED_INDI2);
		}
		
		/* Set indicator leds */
		set_leds(LED_BUTTONS_ADDR, indi_leds_state);
			
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
