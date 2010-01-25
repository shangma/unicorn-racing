#include "config.h"
#include "hydrogear.h"
#include "can_lib.h"
#include <util/delay.h>
#include <avr/interrupt.h>

#define MY_ID_TAG 0x80       //- 128 decimal


//void INT7_vect(void) __attribute__((interrupt));
void send_msg(U8 msg_buffer[8]);
U8  sensor_buffer[8];

int main(void){
//Atmel stuff

	//Enable interrupts
	EICRA |= (1<<ISC31) | (1<<ISC30 );
	EICRB |= (1<<ISC71) | (1<<ISC70 ) | (1<<ISC61) | (1<<ISC60 ) | (1<<ISC51) | (1<<ISC50 ) | (1<<ISC41) | (1<<ISC40 );
	/* Mask External Interrupt INT6 */ 
    	EIMSK |= (1<<INT7) |  (1<<INT6) | (1<<INT5) | (1<<INT4) | (1<<INT3); 

   	/* Set the timer1 output compare A interrupt mask */ 
    	TIMSK1 |= (1<<OCIE1A);  

	sei();
//	U8  sensor_buffer[8];
	st_cmd_t sensor_message;

	can_init(0);

	// --- Init Reply data
    sensor_message.pt_data = &sensor_buffer[0];
 
   	DDRA = 0xFF;            //Make Port A output values
   	PORTA = 0x00;           //Turn all output pins on port c off

   	DDRE = 0x00;
   	PORTE= 0xFF;
	sensor_buffer[0] = 0x00;
        sensor_buffer[1] = 0x00;
	sensor_buffer[2] = 0x00;
        sensor_buffer[3] = 0x00;
 
    while(1){
	//PORTA=LED7;
	/*if(~PINE&GEARUP){
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
	}*/

	//sensor_buffer[2] = 0x00;
	//sensor_buffer[3] = 0x00;

	// --- Auto-reply Command
//    sensor_message.ctrl.ide = 0;            //- CAN 2.0A
//    sensor_message.dlc = 4;                 //- Message with 4-byte data
//    sensor_message.id.std = MY_ID_TAG;
//    sensor_message.cmd = CMD_REPLY_MASKED;

    // --- Enable reply
//    while(can_cmd(&sensor_message) != CAN_CMD_ACCEPTED);
    // --- Wait for Reply completed
//    while(can_get_status(&sensor_message) == CAN_STATUS_NOT_COMPLETED);

	sensor_buffer[0] = 0x00;
    sensor_buffer[1] = 0x00;
	sensor_buffer[2] = 0x00;
    sensor_buffer[3] = 0x00;
	
}
}

ISR(INT7_vect){
	PORTA=LED1;
	sensor_buffer[0] = 0x01;
	send_msg(sensor_buffer);
}

ISR(INT6_vect){
    PORTA=LED2;
    sensor_buffer[0] = 0x20;
	send_msg(sensor_buffer);
}

ISR(INT5_vect){
    PORTA=LED3;
    sensor_buffer[0] = 0x30;
	send_msg(sensor_buffer);
}

ISR(INT4_vect){
	PORTA=LED4;
	sensor_buffer[0] = 0x02;
	send_msg(sensor_buffer);
}

ISR(INT3_vect){
	PORTA=LED5;
	sensor_buffer[0] = 0x10;
	send_msg(sensor_buffer);
}

void send_msg(U8 msg_buffer[8]){

	st_cmd_t sensor_message;
	// --- Init Reply data
    

	sensor_message.pt_data = &msg_buffer[0];

	

	sensor_message.ctrl.ide = 0;            //- CAN 2.0A
	sensor_message.dlc = 4;                 //- Message with 4-byte data
   	sensor_message.id.std = MY_ID_TAG;
    sensor_message.cmd = CMD_REPLY_MASKED;

    // --- Enable reply
    while(can_cmd(&sensor_message) != CAN_CMD_ACCEPTED);
    // --- Wait for Reply completed
    while(can_get_status(&sensor_message) == CAN_STATUS_NOT_COMPLETED);
}
