//_____ I N C L U D E S ________________________________________________________
#include "config.h"
#include "can_lib.h"
#include <util/delay.h>
#include "led.h"
#include "display.h"
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

//  Init CAN, UART, I/O
    init();

    init_led();
    sei();

    // --- Init variables
    rpm_msg.pt_data = &rpm_response_buffer[0];
    rpm_msg.status = 0;

    gear_status_msg.pt_data = &gear_status_response_buffer[0];
    gear_status_msg.status = 0;

    fade_in(1000, 50);
    SEG_0;
    
    can_update_rx_msg(&rpm_msg, rpm_msgid, 8);
    can_update_rx_msg(&gear_status_msg, gear_status_msgid, 1);   
    while (1)
    {
            if (can_get_status(&rpm_msg) == CAN_STATUS_COMPLETED) {  // check for rpm_msg
                    canData = rpm_response_buffer[0];                     
                    can_update_rx_msg(&rpm_msg, rpm_msgid, 8);      // update rpm_msg to accept a new msg
					disp_rpm(canData);
            }

            if (can_get_status(&gear_status_msg) == CAN_STATUS_COMPLETED) {  // check for gear_status_msg
                    canData = gear_status_response_buffer[0];                     
                    can_update_rx_msg(&gear_status_msg, gear_status_msgid, 1);      // update gear_status_msg to accept a new msg
 
                    switch (canData) {
                            case 0:
                                    SEG_0;
                                    break;
                            case 1:
                                    SEG_1;
                                    break;
                            case 2:
                                    SEG_2;
                                    break;
                            case 3:
                                    SEG_3;
                                    break;
                            case 4:
                                    SEG_4;
                                    break;
                            case 5:
                                    SEG_5;
                                    break;
                            case 6:
                                    SEG_6;
                                    break;
                            case 7:
                                    SEG_7;
                                    break;
                            case 8:
                                    SEG_8;
                                    break;
                            case 9:
                                    SEG_9;
                                    break;
                    }
            }
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
