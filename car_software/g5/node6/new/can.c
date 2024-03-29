#include <stdlib.h>
#include <avr/io.h>
#include "can.h"
#include "../../lib/can_defs.h"

st_cmd_t tx_remote_msg;

/* Interrupt routine to take care of can interrupts */
ISR(CANIT_vect)
{
	uint8_t i,interrupt;
	uint16_t tmp,tmp2,mask=1;
	uint8_t DataBuf[8];

	uint8_t rpm_response_buffer[8];
	st_cmd_t rpm_msg;

	rpm_msg.pt_data = rpm_response_buffer;
	rpm_msg.status = 0;
	/*
	 * Function to clear only the mob that generated the interrupt 
	 * ------------- Code flow --------------------
	 * Read CANSIT1 and CANSIT2 to figure out what mob(s) that generated
	 * the interrupt.
	 * Read CANSTMOB for each mob that generated a interrupt to determin
	 * the interrupt type.
	 * Make a switch case over the types and do meaning full handling for
	 * the types.
	 * TXOK just need to call Can_mob_abort() and Can_clear_status_mob()
	 * Proper action for all other types is TODO
	*/

	/* Test mob's for pending interrupt */
	tmp = CANSIT2+(CANSIT1<<8);
	for(i=0;i<=14;i++){
		if(tmp & mask){	/* True if mob have pending interrupt */
			Can_set_mob(i); /* Switch to mob */
			interrupt = (CANSTMOB & INT_MOB_MSK);
			switch (interrupt){
				case MOB_RX_COMPLETED:
					/* Can specific code */
					can_get_data(&DataBuf[0]);	// Copy data to canDataTest
					Can_mob_abort();        // Freed the MOB
					Can_clear_status_mob(); // and reset MOb status
					can_update_rx_msg(&rpm_msg, rpm_msgid, 8);	/* TODO Lav det her på en anden måde */
					/* Take care of the data code */
					PORTB ^= (1<<PB5);
/*					if (canDataTest[0] == 20) {*/
/*						*/
/*						if (canDataTest[1] == 20) {  */
/*							SEG_0(LED_BLINK1);*/
/*						} else if (canDataTest[1] == 21) {*/
/*							SEG_1(LED_BLINK1);*/
/*						} else if (canDataTest[1] == 22) {*/
/*							SEG_2(LED_BLINK1);*/
/*						} else if (canDataTest[1] == 23) {*/
/*							SEG_3(LED_BLINK1);*/
/*						} else if (canDataTest[1] == 24) {*/
/*							SEG_4(LED_BLINK1);*/
/*						} else if (canDataTest[1] == 25) {*/
/*							SEG_5(LED_BLINK1);*/
/*						} else if (canDataTest[1] == 26) {*/
/*							SEG_6(LED_BLINK1);*/
/*						} else if (canDataTest[1] == 27) {*/
/*							SEG_7(LED_BLINK1);*/
/*						} else if (canDataTest[1] == 28) {*/
/*							SEG_8(LED_BLINK1);*/
/*						} else if (canDataTest[1] == 29) {*/
/*							SEG_8(LED_BLINK1);*/
/*						}*/
/*					}*/
					break;
				case MOB_TX_COMPLETED:
					Can_mob_abort();        // Freed the MOB
					Can_clear_status_mob(); // and reset MOb status	
//					Can_unset_mob_int(i);		/* TODO Måske virker funktionen ikke */
					break;				
				case MOB_ACK_ERROR:
					/* TODO */
					break;
				case MOB_FORM_ERROR:
					/* TODO */
					break;
				case MOB_CRC_ERROR:
					/* TODO */
					break;
				case MOB_STUFF_ERROR:
					/* TODO */
					break;
				case MOB_BIT_ERROR:
					/* TODO */
					break;
				default:
					Can_mob_abort();        // Freed the MOB
					Can_clear_status_mob(); // and reset MOb status
					break;
			}
		}
		mask = mask<<1;
	}
}

/* TODO 
 * Make a can_read function that is non blocking
*/

/* funktion til at sende en besked der er dlc byte lang og er ikke blocking 
 * return values:
 * 0 = Besked ikke kommet i udbakke
 * 1 = Besked kommet i udbakke
*/
uint8_t can_send_non_blocking(uint8_t msg_id, void* buf, uint8_t dlc)
{
	tx_remote_msg.pt_data = buf; 
	tx_remote_msg.id.std = msg_id;
	tx_remote_msg.ctrl.ide = 0;
	tx_remote_msg.ctrl.rtr = 1;
	tx_remote_msg.dlc = dlc;
	tx_remote_msg.cmd = CMD_TX_DATA;
	tx_remote_msg.blocking = 0;	/* For non blocking */

	/* can_cmd function extended with a feature to enable interrupt for
	 * the message mob picked for the message
	*/
	if (can_cmd(&tx_remote_msg) != CAN_CMD_ACCEPTED){
		return 0;	// No free mob could not put message in mail box
	}else{
		return 1;
	}
}

uint8_t can_update_rx_msg(st_cmd_t* msg, uint8_t msg_id, uint8_t dlc)
{
        uint8_t i;
        
        msg->id.std = msg_id;
        msg->ctrl.ide = 0;
        msg->ctrl.rtr = 0;
        msg->dlc = dlc;
        msg->cmd = CMD_RX_DATA_MASKED;

        while(can_cmd(msg) != CAN_CMD_ACCEPTED);
}
