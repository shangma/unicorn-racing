#include "config.h"
#include "hydrorear.h"
#include "can_lib.h"
#include "uart_lib.h"
#include "led_drv.h"
#include "rtc_drv.h"
#include <avr/interrupt.h>
//#include <util/delay.h>

#define TIME_GEARUP 200
#define TIME_GEARDOWN 400

#define ID_TAG_BASE 128       //- 0x80 hexa
#define NB_TARGET   10

int main(void){
	CLKPR = 0x80;  CLKPR = 0x00;  // Clock prescaler Reset



	rtc_int_init();
	uart_init(CONF_8BIT_NOPAR_1STOP,UART_BAUDRATE);
	wait_for(100);
    uart_mini_printf("\r\n\n= UNICORN RACE ENGINEERING LAB =\r\n");
    uart_mini_printf      ("===============================\r\n");


	//enable CAN interrupt
	CANGIT = (1 << CANIT);
	CANGIE = (1 << ENIT) | (1 << ENRX);

	CANIE1=0x00;
	CANIE2=(1 << IEMOB0);
	
    can_init(0);

	
	//Enable interrupts
	sei();
 	U8 i, j;
    U16 temp;
	U8 tx_remote_buffer[8];
    st_cmd_t tx_remote_msg;

    U8 response_buffer[8];
    st_cmd_t response_msg;

    // --- Init variables
    tx_remote_msg.pt_data = &tx_remote_buffer[0];
    tx_remote_msg.status = 0;

    response_msg.pt_data = &response_buffer[0];
    response_msg.status = 0;
	
 
    while (1)
    {
//	_delay_ms(2000);
//        wait_for(100);  // 2 secondes between refreshed screen

		//Kill all LEDs
		PORTA=0x00;
        uart_mini_printf("\rWaiting for new data\n");
        for(j=0; j<NB_TARGET; j++)
        {
            // --- Init Rx Commands
      	    for(i=0; i<8; i++) response_buffer[i]=0;
            response_msg.id.std = ID_TAG_BASE + j;
            response_msg.ctrl.ide = 0;
            response_msg.ctrl.rtr = 0;
            response_msg.dlc = 4;
            response_msg.cmd = CMD_RX_DATA_MASKED;
            // --- Rx Command
            while(can_cmd(&response_msg) != CAN_CMD_ACCEPTED);

            // --- Init Tx Commands
  	        for(i=0; i<8; i++) tx_remote_buffer[i]=0;
            tx_remote_msg.id.std = ID_TAG_BASE + j;
            tx_remote_msg.ctrl.ide = 0;
            tx_remote_msg.ctrl.rtr = 1;
            tx_remote_msg.dlc = 4;
            tx_remote_msg.cmd = CMD_TX_REMOTE;
            // --- Tx Command
            while(can_cmd(&tx_remote_msg) != CAN_CMD_ACCEPTED);

            // --- Wait for Tx remote completed
            while(can_get_status(&tx_remote_msg) == CAN_STATUS_NOT_COMPLETED)

            wait_for(50); // Wait 50ms for a response if exits
            if (can_get_status(&response_msg) == CAN_STATUS_COMPLETED)
            {
                // Printing example: "Target 0: Temp=+21°C, Lum=077, VCC=5.12V"
				
                // --- Get "target number" and print it
				                //uart_mini_printf("   - Target_ID = 0x%03X, ", response_msg.id.std);
                
                // --- Get "temperature" value and print it               
                //uart_mini_printf("Temp. = %02d degC, ", response_buffer[0]);
                
                // --- Get "luminosity" and print it
                //uart_mini_printf(", Lum. = %02u, ", response_buffer[1]);
                
                // --- Get "VCC" and print it
                //temp = (((U16)response_buffer[2])<<8) | (U16)response_buffer[3];
                //uart_mini_printf("VCC = %03u0 mV", temp);
                
                // --- Print "end of line"
                //uart_mini_printf("\r\n");
				if(response_buffer[0]==0x01){
					PORTA=0x01;
					uart_mini_printf("Gear up \n");
					wait_for(TIME_GEARUP);
					uart_mini_printf("Done \n");
				}
				if(response_buffer[0]==0x02){
					PORTA=0x02;
					uart_mini_printf("Gear down\n");
					wait_for(TIME_GEARDOWN);
					uart_mini_printf("Done\n");
				}

            }
            else
            {
                response_msg.cmd = CMD_ABORT;
  	            while (can_cmd(&response_msg) != CAN_CMD_ACCEPTED);
            }
        }
    }
}


ISR(CANIT_vect){
cli();
PORTA=0xFF;
wait_for(1000);
uart_mini_printf("CAN interrupt\n");

sei();
}
