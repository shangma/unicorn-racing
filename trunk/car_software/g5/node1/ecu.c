#include "config.h"
#include <util/delay.h>
#include <util/atomic.h>
#include "uart.h"
#include "xitoa.h"
#include "ecu.h"
#include "queue.h"
#include "comm.h"

uint8_t EcuData[] = {65,66,67,68,69,70,71,72,73,74,75,76,77,78,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void val_to_xbee(uint8_t i, uint8_t j)
{
	uint8_t k=0;
//	xprintf(PSTR("i%d,j%d \n"), i, j);
	/* Add value to xbee buffer */
    	ATOMIC_BLOCK(ATOMIC_FORCEON)
    	{
		QUEUE_PUT(my_q, ECUObjects[j].id);	/* Add id */
	}
	for (k=0;k<ECUObjects[j].length;k++) {	/* Add value */
    		ATOMIC_BLOCK(ATOMIC_FORCEON)
    		{
			QUEUE_PUT(my_q, EcuData[i+k]);
		}
	}
	/* Check if more than 20 elements in xbee buffer */
	if (QUEUE_GET_NUM_ELE(my_q) >= 20) {
		//xprintf(PSTR("More than 20 elements\n"));
		xbee_send_trigger();
	}
}

void ecu_data_handler( void )
{
	uint8_t i=0;
	uint8_t	j=0;

	/* Loop over all values in EcuData */
	while(i<=114) {
		/* Check if anything to be done for value */
		if (valueObjects[ECUObjects[j].id].action & (TO_XBEE | TO_SD | TO_CAN) ) {
			/* Value to xbee? */
			if (valueObjects[ECUObjects[j].id].action & TO_XBEE) {
			    	//_delay_us(10);
				val_to_xbee(i,j);
			}
	
			/* Value to SD? */
			if (valueObjects[ECUObjects[j].id].action & TO_SD) {
				/* TODO
				 * Insert call to val_to_sd() when the function is
				 * made
				 */
			}
	
			/* Value to CAN? */
			if (valueObjects[ECUObjects[j].id].action & TO_CAN) {
				/* TODO
				 * Insert call to val_to_CAN() when the function is
				 * made
				 */
			}
		}
		
		/* Find index for next value */
		i += ECUObjects[j].length;
		j++;
	}
}
