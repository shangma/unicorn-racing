/*********************************************
 * Unicorn main gear kontrol
 *********************************************/

#include <config.h>
#include <extern.h>
#include <prototyper.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>

// GPS TIME
int volatile the_time_h = 0;
int volatile the_time_m = 0;
int volatile the_time_s = 0;

// North/South
char volatile N_S_indicator = '0';

// East/West
char volatile E_W_indicator = '0';

// satellites
unsigned short int volatile satellites = 0;

unsigned int speed = 0;

int main(void)
{
	char tempchar[2];

	ioinit();
	uartinit0();

	sendtekst("\n\nStartet\n\n\r");

	uartinit1();

	sei();

	while (1)
	{
		sendtekst("Time: ");
		itoa(the_time_h,tempchar,10);
		sendtekst(tempchar);
		sendtekst(":");
		itoa(the_time_m,tempchar,10);
		sendtekst(tempchar);
		sendtekst(":");
		itoa(the_time_s,tempchar,10);
		sendtekst(tempchar);
		sendtekst("  ");

		sendtekst("N/S: ");
		while ((UCSR0A & (1 << UDRE0)) == 0) {};
		UDR0 = N_S_indicator;
		sendtekst("  ");

		sendtekst("E/W: ");
		while ((UCSR0A & (1 << UDRE0)) == 0) {};
		UDR0 = E_W_indicator;
		sendtekst("  ");

		sendtekst("Sat: ");
		itoa(satellites,tempchar,10);
		sendtekst(tempchar);
		sendtekst("  ");

		sendtekst("Speed [km/h]: "); // Ikke testet, ikke engang om index er ok
		itoa(speed,tempchar,10);
		sendtekst(tempchar);

		sendtekst("\n\r");

		_delay_ms(500);
		PORTC^= (1<<PC7);
		_delay_ms(500);
	}
    return 0;
}
