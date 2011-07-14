//_____ I N C L U D E S ________________________________________________________
#include "config.h"
#include "can_std/can_lib.h"
#include <util/delay.h>
#include "can_new.h"
#include "../lib/can_defs.h"
#include "display/display.h"

//_____ D E F I N I T I O N S __________________________________________________
#define ID_BASE 0x80
//_____ D E C L A R A T I O N S ________________________________________________
void init(void);

int main (void)
{	
	int tmp;
	CLKPR = 0x80;  CLKPR = 0x00;  // Clock prescaler Reset

//  Init CAN, UART, I/O
	init();
	TWI_init();

	sei();		/* Interrupt enable */

	Can_sei();		/* Enable general can interrupt */
	Can_set_tx_int();	/* Enable can tx interrupt */

    	// --- Init variables

	DDRB |= (1<<PB6 | 1<<PB5);

	//PORTB |= (1<<PB6 | 0<<PB5);

	_delay_ms(100);


	_delay_ms(2000);

	while (1) {
	tmp = test_display();

	if (tmp == 1) PORTB |= (1<<PB6 | 1<< PB5);
	if (tmp == -1) PORTB |= (0<<PB6 | 1<< PB5);
	if (tmp == -2) PORTB |= (1<<PB6 | 0<< PB5);
	_delay_ms(2000);
	PORTB &= ~(1<<PB6 | 1<<PB5);
	_delay_ms(500);
	}
	return 0;
}

void init(void)
{
    // CAN Init
    can_init(0);
}
