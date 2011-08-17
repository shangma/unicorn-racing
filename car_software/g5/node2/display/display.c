#include <stdint.h>
#include "../config.h"
#include <util/twi.h>
#include <util/delay.h>
#include "display.h"
#include "../twi/twi.h"

uint8_t buttons_state = BUTTON1 | BUTTON2;

display_test(void)
{
	uint8_t mode;

	mode = LED_ON;

	
	set_leds(LED0_7_ADDR, mode<<LED_RPM0 | mode<<LED_RPM1 | mode<<LED_RPM2 | mode<<LED_RPM3 | mode<<LED_RPM4 | mode<<LED_RPM5 | mode<<LED_RPM6 | mode<<LED_RPM7);
	set_leds(LED8_15_ADDR, mode<<0 | mode<<2 | mode<<4 | mode<<6 | mode<<8 | mode<<10 | mode<<12 | mode<<14);
	set_leds(SEG_ADDR, mode<<0 | mode<<2 | mode<<4 | mode<<6 | mode<<8 | mode<<10 | mode<<12 | mode<<14);
	set_leds(LED_BUTTONS_ADDR, mode<<LED_INDI1 | mode<<LED_INDI2 | mode<<LED_INDI3 | mode<<LED_INDI4 | mode<<LED_INDI5 | mode<<LED_INDI6 | mode<<LED_BUTTON_1 | mode<<LED_BUTTON_2);

	_delay_ms(3000);

	set_leds(LED0_7_ADDR, 0);
	set_leds(LED8_15_ADDR, 0);
	set_leds(SEG_ADDR, 0);
	set_leds(LED_BUTTONS_ADDR, 0);
}

set_rpm(uint16_t rpm, uint8_t mode)
{	
	/* Set leds based on rpm value */
	if (rpm<=RPM0 ) {
		set_leds(LED0_7_ADDR, 0);
		set_leds(LED8_15_ADDR, 0);

	} else if( rpm > RPM0 && rpm <= RPM1 ){
		set_leds(LED0_7_ADDR, mode<<0);
		set_leds(LED8_15_ADDR, 0);

	} else if( rpm > RPM1 && rpm <= RPM2 ){
		set_leds(LED0_7_ADDR, mode<<0 | mode<<2);
		set_leds(LED8_15_ADDR, 0);

	} else if( rpm > RPM2 && rpm <= RPM3 ){
		set_leds(LED0_7_ADDR, mode<<0 | mode<<2 | mode<<4);
		set_leds(LED8_15_ADDR, 0);

	} else if( rpm > RPM3 && rpm <= RPM4 ){
		set_leds(LED0_7_ADDR, mode<<0 | mode<<2 | mode<<4 | mode<<6);
		set_leds(LED8_15_ADDR, 0);

	} else if( rpm > RPM4 && rpm <= RPM5 ){
		set_leds(LED0_7_ADDR, mode<<0 | mode<<2 | mode<<4 | mode<<6 | mode<<8);
		set_leds(LED8_15_ADDR, 0);

	} else if( rpm > RPM5 && rpm <= RPM6 ){
		set_leds(LED0_7_ADDR,  mode<<0 | mode<<2 | mode<<4 | mode<<6 | mode<<8 | mode<<10);
		set_leds(LED8_15_ADDR, 0);

	} else if( rpm > RPM6 && rpm <= RPM7 ){
		set_leds(LED0_7_ADDR, mode<<0 | mode<<2 | mode<<4 | mode<<6 | mode<<8 | mode<<10 | mode<<12);
		set_leds(LED8_15_ADDR, 0);
	
	} else if( rpm > RPM7 && rpm <= RPM8 ){
		set_leds(LED0_7_ADDR, mode<<0 | mode<<2 | mode<<4 | mode<<6 | mode<<8 | mode<<10 | mode<<12 | mode<<14);
		set_leds(LED8_15_ADDR, 0);

	} else if( rpm > RPM8 && rpm <= RPM9 ){
		set_leds(LED8_15_ADDR, mode<<0);
		set_leds(LED0_7_ADDR, mode<<0 | mode<<2 | mode<<4 | mode<<6 | mode<<8 | mode<<10 | mode<<12 | mode<<14);

	} else if( rpm > RPM9 && rpm <= RPM10 ){
		set_leds(LED8_15_ADDR, mode<<0 | mode<<2);
		set_leds(LED0_7_ADDR, mode<<0 | mode<<2 | mode<<4 | mode<<6 | mode<<8 | mode<<10 | mode<<12 | mode<<14);

	} else if( rpm > RPM10 && rpm <= RPM11 ){
		set_leds(LED8_15_ADDR, mode<<0 | mode<<2 | mode<<4);
		set_leds(LED0_7_ADDR, mode<<0 | mode<<2 | mode<<4 | mode<<6 | mode<<8 | mode<<10 | mode<<12 | mode<<14);

	} else if( rpm > RPM11 && rpm <= RPM12 ){
		set_leds(LED8_15_ADDR, mode<<0 | mode<<2 | mode<<4 | mode<<6);
		set_leds(LED0_7_ADDR, mode<<0 | mode<<2 | mode<<4 | mode<<6 | mode<<8 | mode<<10 | mode<<12 | mode<<14);

	} else if( rpm > RPM12 && rpm <= RPM13 ){
		set_leds(LED8_15_ADDR, mode<<0 | mode<<2 | mode<<4 | mode<<6 | mode<<8);
		set_leds(LED0_7_ADDR, mode<<0 | mode<<2 | mode<<4 | mode<<6 | mode<<8 | mode<<10 | mode<<12 | mode<<14);

	} else if( rpm > RPM13 && rpm <= RPM14 ){
		set_leds(LED8_15_ADDR, mode<<0 | mode<<2 | mode<<4 | mode<<6 | mode<<8 | mode<<10);
		set_leds(LED0_7_ADDR, mode<<0 | mode<<2 | mode<<4 | mode<<6 | mode<<8 | mode<<10 | mode<<12 | mode<<14);

	} else if( rpm > RPM14 && rpm <= RPM15 ){
		set_leds(LED8_15_ADDR, mode<<0 | mode<<2 | mode<<4 | mode<<6 | mode<<8 | mode<<10 | mode<<12);
		set_leds(LED0_7_ADDR, mode<<0 | mode<<2 | mode<<4 | mode<<6 | mode<<8 | mode<<10 | mode<<12 | mode<<14);

	} else if( rpm > RPM15 && rpm <= RPM16 ){
		set_leds(LED8_15_ADDR, mode<<0 | mode<<2 | mode<<4 | mode<<6 | mode<<8 | mode<<10 | mode<<12 | mode<<14);
		set_leds(LED0_7_ADDR, mode<<0 | mode<<2 | mode<<4 | mode<<6 | mode<<8 | mode<<10 | mode<<12 | mode<<14);

	} else if( rpm > RPM16 ){
		set_leds(LED8_15_ADDR, LED_BLINK1<<8 | LED_BLINK1<<10 | LED_BLINK1<<12 | LED_BLINK1<<14);
		set_leds(LED0_7_ADDR, 0); 
	}
}

int8_t set_leds(int addr, uint16_t leds)
{
	if (!(TWI_start())) return -1;
	
	TWI_send(addr);
	if (!(TW_STATUS == TW_MT_SLA_ACK)) return -2;		/* No ACK from device return */

	TWI_send(AI|LS0);					/* Auto-increment and start from first led reg */
        if (!(TW_STATUS == TW_MT_DATA_ACK)) return -2;		/* No ACK from device return */

	TWI_send(leds & 0xff);
        if (!(TW_STATUS == TW_MT_DATA_ACK)) return -2;          /* No ACK from device return */

	TWI_send( (leds>>8) & 0xff);
        if (!(TW_STATUS == TW_MT_DATA_ACK)) return -2;          /* No ACK from device return */

	/* send stop */
	TWI_stop();
	return 1;
}


int8_t set_blink_rate(int addr, uint8_t blink_nr, uint8_t blink_rate, uint8_t blink_duty_cycle)
{
	if (!(TWI_start())) return -1;
	
	TWI_send(addr);
	if (!(TW_STATUS == TW_MT_SLA_ACK)) return -2;		/* No ACK from device return */
	if (blink_nr == LED_BLINK1) {
		TWI_send(AI|PSC0);					/* Auto-increment and start from PSC0 */
		if (!(TW_STATUS == TW_MT_DATA_ACK)) return -3;
	} else if (blink_nr == LED_BLINK2) {
		TWI_send(AI|PSC1);					/* Auto-increment and start from PSC0 */
		if (!(TW_STATUS == TW_MT_DATA_ACK)) return -4;
	}
		
	TWI_send(blink_rate);
	if (!(TW_STATUS == TW_MT_DATA_ACK)) return -5;		/* No ACK from device return */

	TWI_send(blink_duty_cycle);
	if (!(TW_STATUS == TW_MT_DATA_ACK)) return -6;		/* No ACK from device return */

	/* send stop */
	TWI_stop();
	return 1;
}

uint8_t get_buttons(int addr)
{
	uint8_t data;

	if (!(TWI_start())) return 8;

	TWI_send(addr);
	if (!(TW_STATUS == TW_MT_SLA_ACK)) return 9;		/* No ACK from device return */

	TWI_send(INPUT1);
	if (!(TW_STATUS == TW_MT_DATA_ACK)) return 10;		/* No ACK from device return */

	if (!(TWI_start())) return 11;

	TWI_send(addr | 1);
	if (!(TW_STATUS == TW_MR_SLA_ACK)) return 12;		/* No ACK from device return */

	data = 0;
	data = TWI_rcvr(0);

	/* send stop */
	TWI_stop();
	return data;
}

int8_t set_seg(int addr, uint8_t i, uint8_t j)
{
	if (!(TWI_start())) return -1;

	TWI_send(addr);
	if (!(TW_STATUS == TW_MT_SLA_ACK)) return -2;		/* No ACK from device return */

	TWI_send(AI|LS0);					/* Auto-increment and start from first led reg */
        if (!(TW_STATUS == TW_MT_DATA_ACK)) return -2;		/* No ACK from device return */

        TWI_send(i);
        if (!(TW_STATUS == TW_MT_DATA_ACK)) return -2;          /* No ACK from device return */

        TWI_send(j);
        if (!(TW_STATUS == TW_MT_DATA_ACK)) return -2;          /* No ACK from device return */


	/* send stop */
	TWI_stop();
	return 1;
}

int test_display(int addr, int i, int j )
{
	if (!(TWI_start())) return -1;
	
	TWI_send(0xc0);
	if (!(TW_STATUS == TW_MT_SLA_ACK)) return -2;		/* No ACK from device return */

	TWI_send(0x12);
        if (!(TW_STATUS == TW_MT_DATA_ACK)) return -2;		/* No ACK from device return */

        TWI_send(0x00);
        if (!(TW_STATUS == TW_MT_DATA_ACK)) return -2;          /* No ACK from device return */

        TWI_send(0x10);
        if (!(TW_STATUS == TW_MT_DATA_ACK)) return -2;          /* No ACK from device return */

        TWI_send(0x00);
        if (!(TW_STATUS == TW_MT_DATA_ACK)) return -2;          /* No ACK from device return */

        TWI_send(0x10);
        if (!(TW_STATUS == TW_MT_DATA_ACK)) return -2;          /* No ACK from device return */

        TWI_send(i);
        if (!(TW_STATUS == TW_MT_DATA_ACK)) return -2;          /* No ACK from device return */

        TWI_send(j);
        if (!(TW_STATUS == TW_MT_DATA_ACK)) return -2;          /* No ACK from device return */

        TWI_send(0xFF);
        if (!(TW_STATUS == TW_MT_DATA_ACK)) return -2;          /* No ACK from device return */

        TWI_send(0x00);
        if (!(TW_STATUS == TW_MT_DATA_ACK)) return -2;          /* No ACK from device return */

	/* send stop */
	TWI_stop();

	return 1;
}
