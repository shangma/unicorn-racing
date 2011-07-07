#include "config.h"
#include <util/delay.h>
#include "uart.h"
#include "xitoa.h"
#include "ecu.h"

void ecu_data_handler( void )
{
	uint8_t i=0;
	uint8_t	j=0;

	/* Loop over all values in EcuData */
	while(i<=114) {
		/* Find info about value in ECUObjects */
		/* TODO When the xbee data function is done the following data 
		 * should use it to get into the bufferindex
		 */
		xprintf(PSTR("%d,%d,%d\n"), i, j, ECUObjects[j].id);
		_delay_us(1000);
/*		ECUObjects[i].id;*/
/*		valueObjects[ECUObjects[i].id];*/
		
		/* Find index for next value */
		i += ECUObjects[j].length;
		j++;
	}
}
