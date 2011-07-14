//_____ I N C L U D E S ________________________________________________________
#include "config.h"
#include "can_std/can_lib.h"
#include <util/delay.h>
#include "can_new.h"
#include "../lib/can_defs.h"

//_____ D E F I N I T I O N S __________________________________________________
#define ID_BASE 0x80
//_____ D E C L A R A T I O N S ________________________________________________
void init(void);

int main (void)
{	
	CLKPR = 0x80;  CLKPR = 0x00;  // Clock prescaler Reset

//  Init CAN, UART, I/O
	init();

	sei();		/* Interrupt enable */

	Can_sei();		/* Enable general can interrupt */
	Can_set_tx_int();	/* Enable can tx interrupt */

    	// --- Init variables

	while (1) {
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
