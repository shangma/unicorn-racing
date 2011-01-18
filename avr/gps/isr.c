/*********************************************
 * Interrupt-service-rutiner
 *********************************************/

#include <config.h>
#include <extern.h>
#include <prototyper.h>
#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <avr/interrupt.h>
#include <util/delay.h>

char start_flag = 0;
char GPGGA_flag = 0;
int char_counter = 0;

char msg_type[5];

// Time from gps
// Uden init, virker index 0 ikke !?!?!?
char the_time_char[7] = {'0','0','0','0','0','0'}; 
char sec_char[3] = {'0','0'};
char min_char[3] = {'0','0'};
char hours_char[3] = {'0','0'};

char satellites_char[3] = {'0','0'};

 // UART0 interrupt
ISR(USART0_RX_vect)
{
	char data;
	data = UDR0;
}

ISR(USART1_RX_vect)
{			
	char data;
	data = UDR1;
	//UDR0 = UDR1;

	char_counter++;

	// Finder starten af beskeden
	if((data == '$'))
	{
		char_counter = 0;	// Reset char counter
		GPGGA_flag = 0;
	}

	// Besked typen, index 1-5
	if((char_counter>=1) && (char_counter<=5))
		msg_type[char_counter-1] = data;

	// Undersøger beskedtypen
	if(char_counter == 5)
	{
		if(!strcmp(msg_type,"GPGGA"))
		{
			GPGGA_flag = 1;
			//UDR0 = 'A';	
		}
		else
			char_counter = 0;
	}

	// The time, index 7 to 12
	if((GPGGA_flag == 1) && ((char_counter>=7) && (char_counter<=12)))
	{
		the_time_char[char_counter-7] = data;
	}

	if((char_counter==12))
	{

	char i;
		for(i=0 ; i<=5 ; i++)
		{
			if((i==0) || (i==1))
				hours_char[i] = the_time_char[i];

			if((i==2) || (i==3))
				min_char[i-2] = the_time_char[i];

			if((i==4) || (i==5))
				sec_char[i-4] = the_time_char[i];
		}
		// Time to integer
		the_time_h = atoi(hours_char) +1;
		the_time_m = atoi(min_char);
		the_time_s = atoi(sec_char);
	}

	// N/S Indicator, Index 28
	if((GPGGA_flag == 1) && (char_counter==28))
		N_S_indicator = data;

	// E/W Indicator, Index 41
	if((GPGGA_flag == 1) && (char_counter==41))
		E_W_indicator = data;

	// Antal satelitter, index 45 to 46
	if((GPGGA_flag == 1) && ((char_counter>=45) && (char_counter<=46)))
		satellites_char[char_counter-45] = data;

	if((char_counter==46))
		satellites = atoi(satellites_char);

}
