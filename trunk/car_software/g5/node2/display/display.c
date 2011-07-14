#include <util/twi.h>
#include "display.h"
#include "../twi/twi.h"

int test_display( void )
{
	if (!(TWI_start())) return -1;
	
	TWI_send(0xC2);
	if (!(TW_STATUS == TW_MT_SLA_ACK)) return -2;		/* No ACK from device return */

	TWI_send(0x12);
        if (!(TW_STATUS == TW_MT_DATA_ACK)) return -2;		/* No ACK from device return */

        TWI_send(0x00);
        if (!(TW_STATUS == TW_MT_DATA_ACK)) return -2;          /* No ACK from device return */

        TWI_send(0x02);
        if (!(TW_STATUS == TW_MT_DATA_ACK)) return -2;          /* No ACK from device return */

        TWI_send(0x02);
        if (!(TW_STATUS == TW_MT_DATA_ACK)) return -2;          /* No ACK from device return */

        TWI_send(0x80);
        if (!(TW_STATUS == TW_MT_DATA_ACK)) return -2;          /* No ACK from device return */

        TWI_send(0xAA);
        if (!(TW_STATUS == TW_MT_DATA_ACK)) return -2;          /* No ACK from device return */

        TWI_send(0xAA);
        if (!(TW_STATUS == TW_MT_DATA_ACK)) return -2;          /* No ACK from device return */

        TWI_send(0xFF);
        if (!(TW_STATUS == TW_MT_DATA_ACK)) return -2;          /* No ACK from device return */

        TWI_send(0x00);
        if (!(TW_STATUS == TW_MT_DATA_ACK)) return -2;          /* No ACK from device return */

	/* send stop */
	TWI_stop();

	return 1;
}
