#include "config.h"
#include "hydrogear.h"
#include "can_lib.h"
#include <util/delay.h>


#define MY_ID_TAG 0x80       //- 128 decimal

int main(void){

	U8  sensor_buffer[8];
	st_cmd_t sensor_message;

	can_init(0);

	// --- Init Reply data
    sensor_message.pt_data = &sensor_buffer[0];
 
   	DDRA = 0xFF;            //Make Port A output values
   	PORTA = 0x00;           //Turn all output pins on port c off

   	DDRE = 0x00;
   	PORTE= 0xFF;
 
    while(1){
	
	if(~PINE&GEARUP){
		PORTA = LED1;
		sensor_buffer[0] = 0x20;
//		_delay_ms(1000);
	}
	else if(~PINE&GEARDOWN){
		PORTA = LED0;
		sensor_buffer[1] = 0x20;
//		_delay_ms(1000);
	}
	else{
	PORTA=0x00;
	sensor_buffer[0] = 0x00;
	sensor_buffer[1] = 0x00;
	}

	sensor_buffer[2] = 0x00;
	sensor_buffer[3] = 0x00;

	// --- Auto-reply Command
    sensor_message.ctrl.ide = 0;            //- CAN 2.0A
    sensor_message.dlc = 4;                 //- Message with 4-byte data
    sensor_message.id.std = MY_ID_TAG;
    sensor_message.cmd = CMD_REPLY_MASKED;

    // --- Enable reply
    while(can_cmd(&sensor_message) != CAN_CMD_ACCEPTED);
    // --- Wait for Reply completed
    while(can_get_status(&sensor_message) == CAN_STATUS_NOT_COMPLETED);
	
}
}
