/*********************************************
 * vim:sw=8:ts=8:si:et
 * To use the above modeline in vim you must have "set modeline" in your .vimrc
 * Author: Guido Socher
 * Copyright: GPL V2
 *
 * Ethernet remote device and sensor
 *
 * Title: Microchip ENC28J60 Ethernet Interface Driver
 * Chip type           : ATMEGA88 with ENC28J60
 *********************************************/
#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ip_arp_udp.h"
#include "enc28j60.h"
#include "timeout.h"
#include "avr_compat.h"
#include "net.h"

long adc(uint8_t adc_port);
void init_adc(void);
void goADC(void);

// please modify the following two lines. mac and ip have to be unique
// in your local area network. You can not have the same numbers in
// two devices:
static uint8_t mymac[6] = {0x54,0x55,0x58,0x10,0x00,0x24};
uint8_t myip[4] = {192,168,0,200};
uint8_t dstip[4] = {192,168,0,100};
char dstmac[6] = {'N','o','d','e',0,2};
static uint16_t myport =1200; // listen port for udp
// how did I get the mac addr? Translate the first 3 numbers into ascii is: TUX

#define BUFFER_SIZE 250
static uint8_t buf[BUFFER_SIZE+1];
uint16_t plen;
uint8_t ledstatus=0;
// the password string (only the first 5 char checked):

void putmsg(char *str)
{
	send_udp(buf,str,strlen(str),myport, dstip, dstmac);
}


uint8_t parsecom(char *result){
// led----------
	uint8_t buf_pos=0;
	uint8_t payloadlen=0;

	if (ledstatus){
			/* set output to Vcc, LED off */
			PORTB|= (1<<PB1);
			ledstatus=0;
	}else{
			/* set output to GND, LED on */
			PORTB &= ~(1<<PB1);
			ledstatus=1;
	}
			
	// arp is broadcast if unknown but a host may also
	// verify the mac address by sending it to 
	// a unicast address.
	if(eth_type_is_arp_and_my_ip(buf,plen)){
			make_arp_answer_from_request(buf,plen);
			return(2);
	}
	// check if ip packets (icmp or udp) are for us:
	if(eth_type_is_ip_and_my_ip(buf,plen)==0){
			return(2);
	}
	
	if(buf[IP_PROTO_P]==IP_PROTO_ICMP_V && buf[ICMP_TYPE_P]==ICMP_TYPE_ECHOREQUEST_V){
			// a ping packet, let's send pong
			make_echo_reply_from_request(buf,plen);
			return(2);
	}
	// we listen on port 1200=0x4B0
	if (buf[IP_PROTO_P]==IP_PROTO_UDP_V&&buf[UDP_DST_PORT_H_P]==4&&buf[UDP_DST_PORT_L_P]==0xb0){
			payloadlen=buf[UDP_LEN_L_P]-UDP_HEADER_LEN;
					
					/*
					while(space_pos<payloadlen){
							space_pos++;
							if (buf[UDP_DATA_P+space_pos]==' '){
									space_pos++; // put on start of cmd
									break;
							}
					}
					// a command is one char and a value. At
					// least 3 characters long. It has an '=' on
					// position 2:
					if (cmd_pos<2 || cmd_pos>payloadlen-3){
							strcpy(result,"e=no_cmd");
							return(0);
					} */
					
					while(buf[UDP_DATA_P+buf_pos] != ' ' && buf_pos<payloadlen){
						//strcat(result,(char *)&buf[UDP_DATA_P+buf_pos]);
						result[buf_pos] = buf[UDP_DATA_P+buf_pos];
						buf_pos++;
					}
					return(1);
			//strcpy(result,"e=invalid_pw=");
			//strcat(str,(char *)&(buf[UDP_DATA_P]));
	}
	return(0);

}

int main(void){
        
	uint8_t i=0;
	uint8_t counter = 0;
	uint8_t cmdresult;
	char command[30];
	uint8_t newip[4] = {192,168,0,201};
	
	// set the clock speed to 8MHz
	// set the clock prescaler. First write CLKPCE to enable setting of clock the
	// next four instructions.
	CLKPR=(1<<CLKPCE);
	CLKPR=0; // 8 MHZ
	init_adc();
	delay_ms(10);
	
	/* enable PB0, reset as output */
	DDRB|= (1<<DDB0);

	/* enable PD2/INT0, as input */
	DDRD&= ~(1<<DDD2);

	/* set output to gnd, reset the ethernet chip */
	PORTB &= ~(1<<PB0);
	delay_ms(10);
	/* set output to Vcc, reset inactive */
	PORTB|= (1<<PB0);
	delay_ms(200);
	
	/*initialize enc28j60*/
	enc28j60Init(mymac);
	delay_ms(20);
	
	// LED
	/* enable PB1, LED as output */
	DDRB|= (1<<DDB1);

	/* set output to Vcc, LED off */
	PORTB|= (1<<PB1);

	// the transistor on PD7
	DDRD|= (1<<DDD7);
	PORTD &= ~(1<<PD7);// transistor off

	
	/* Magjack leds configuration, see enc28j60 datasheet, page 11 */
	// LEDB=yellow LEDA=green
	//
	// 0x476 is PHLCON LEDA=links status, LEDB=receive/transmit
	// enc28j60PhyWrite(PHLCON,0b0000 0100 0111 01 10);
	enc28j60PhyWrite(PHLCON,0x476);
	delay_ms(20);
	
	/* set output to GND, red LED on */
	PORTB &= ~(1<<PB1);
	i=1;

	//init the ethernet/ip layer:
	init_ip_arp_udp(mymac,myip);

	while(1){
		// get the next new packet:
		
		plen = enc28j60PacketReceive(BUFFER_SIZE, buf);
		goADC();
		/*plen will ne unequal to zero if there is a valid 
		 * packet (without crc error) */
		if(plen!=0){
			memset(command,'\0', (int) sizeof(command));
			cmdresult = parsecom(command);
			if (cmdresult == 1){
				//putmsg("jeghaderdederlange");
				//putmsg(command);
				
				if (strcmp(command,"chgip") == 0){
					//putmsg("Changing IP");
					//putmsg("Changing IP2");
					goADC();
					//init_ip_arp_udp(mymac,newip);
				}
				else{
					putmsg("Bad Command or filename");
				}			
			}
		}
		//delay_ms(100);
		//goADC();
		
	}      
	return (0);
}

void goADC(void)
{
	uint16_t adcl;
	char str[50];
	
	//putmsg("Trying ADC");
	adc(0);
	adcl=(ADCL | ADCH << 8);
	
	sprintf(str,"ADC0%d",adcl);
	
	putmsg(str);
}

long adc(uint8_t adc_port)
{
	long adc_buf=0;
	
	ADMUX = adc_port;        // Choose which ADC-port to take the input from
	
    ADCSRA |= (1 << ADEN);        // Analog-Digital enable bit
 
 
    ADCSRA |= (1 << ADSC);            // start single conversion
        while (ADCSRA & (1 << ADSC))  // wait until conversion is done
 
    ADCSRA &= ~(1<<ADEN);             // shut down the ADC
    adc_buf=(ADCL|ADCH<<8);	

	return adc_buf;
}

void init_adc(void){
DDRD = 0xFF;                            // Set output direction on PORTB
ADCSRA |= (1 << ADEN) |               // Analog-Digital enable bit
          (1 << ADPS1)|               // set prescaler to 8    (clock / 8)
          (1 << ADPS0);               // set prescaler to 8    (doc Atmega168 23.8.2 p.258)
 
ADMUX |=  (0 << REFS1) |
	  (0 << REFS0) |
	  (0 << ADLAR) /*|
	  (1 << MUX0) |
	  (1 << MUX1) |
	  (0 << MUX2) |               // AD result store in (more significant bit in ADCH)
	  (0 << MUX3)*/;                // Choose AD input AD2 (PC2) 
}
