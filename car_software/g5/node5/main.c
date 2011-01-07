//_____ I N C L U D E S ________________________________________________________
#include "config.h"
#include "can_std/can_lib.h"
#include <util/delay.h>
#include "can_func.h"
#include "../lib/can_defs.h"

//_____ D E F I N I T I O N S __________________________________________________
#define ID_BASE 0x80
//_____ D E C L A R A T I O N S ________________________________________________
void init(void);


int main (void)
{	
	U8 canData=0;
	int j=0;
	int k=12;
	CLKPR = 0x80;  CLKPR = 0x00;  // Clock prescaler Reset
	int EcuError = 0;
	int ratio,gearTmp;

//  Init CAN, UART, I/O
	init();

	sei();		/* Interrupt enable */

    // --- Init variables
/*    error_msg.pt_data = &error_response_buffer[0];*/
/*    error_msg.status = 0;*/

/*    rpm_msg.pt_data = &rpm_response_buffer[0];*/
/*    rpm_msg.status = 0;*/

/*    water_temp_msg.pt_data = &water_temp_response_buffer[0];*/
/*    water_temp_msg.status = 0;*/

/*    gear_status_msg.pt_data = &gear_status_response_buffer[0];*/
/*    gear_status_msg.status = 0;*/

/*    gear_neutral_msg.pt_data = &gear_neutral_response_buffer[0];*/
/*    gear_neutral_msg.status = 0;*/

/*    oil_press_msg.pt_data = &oil_press_response_buffer[0];*/
/*    oil_press_msg.status = 0;*/


/*    can_update_rx_msg(&error_msg, error_msgid, 8);*/
/*    can_update_rx_msg(&rpm_msg, rpm_msgid, 8);*/
/*    can_update_rx_msg(&water_temp_msg, water_temp_msgid, 8);*/
/*    can_update_rx_msg(&gear_status_msg, gear_status_msgid, 1);   */
/*    can_update_rx_msg(&gear_neutral_msg, gear_neutral_msgid, 8); */
/*    can_update_rx_msg(&oil_press_msg, oil_press_msgid, 8); */

	tx_remote_msg.pt_data = &tx_remote_buffer[0];
	tx_remote_msg.status = 0;



	while (1) {		
		can_send(rpm_msgid, 8, 1);
		_delay_ms(4000);
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
