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
#define F_CPU 8000000UL  // 8 MHz
#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include "ip_arp_udp.h"
#include "enc28j60.h"
#include "timeout.h"
#include "avr_compat.h"
#include "net.h"
#include <util/delay.h>


/*********************************************


*                   NODE 2                   *


*********************************************/




// please modify the following two lines. mac and ip have to be unique
// in your local area network. You can not have the same numbers in
// two devices:
static uint8_t mymac[6] = {0x4e,0x6f,0x64,0x65,0x30,0x32};  //Node02
static uint8_t myip[4] = {192,168,1,2};
static uint16_t myport =1200; // listen port for udp
// how did I get the mac addr? Translate the first 3 numbers into ascii is: TUX

#define BUFFER_SIZE 250
static uint8_t buf[BUFFER_SIZE+1];

// the password string (only the first 5 char checked):
static char password[]="secret";

// 
uint8_t verify_password(char *str)
{
        // the first characters of the received string are
        // a simple password/cookie:
        if (strncmp(password,str,5)==0){
                return(1);
        }
        return(0);
}

int main(void){

        
        uint16_t plen;
        uint8_t i=0;
        //uint8_t cmd_pos=0;
        uint8_t payloadlen=0;
        char str[30];
        //char cmdval;
        uint8_t old_packid=0;
        uint8_t packid=0;
        uint8_t pack_dif=0;
        
        // set the clock speed to 8MHz
        // set the clock prescaler. First write CLKPCE to enable setting of clock the
        // next four instructions.
        CLKPR=(1<<CLKPCE);
        CLKPR=0; // 8 MHZ
        delay_ms(10);
        
        /* enable PB0, reset as output */
        DDRB|= (1<<DDB0);
        
        /* enable PC0 as output */
        //   DDRC|= (1<<DDC4);

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

                /*plen will ne unequal to zero if there is a valid 
                 * packet (without crc error) */
                if(plen==0){
                        continue;
                }
                        
                // arp is broadcast if unknown but a host may also
                // verify the mac address by sending it to 
                // a unicast address.
                if(eth_type_is_arp_and_my_ip(buf,plen)){
                        make_arp_answer_from_request(buf,plen);
                        continue;
                }
                // check if ip packets (icmp or udp) are for us:
                if(eth_type_is_ip_and_my_ip(buf,plen)==0){
                        continue;
                }
                
                if(buf[IP_PROTO_P]==IP_PROTO_ICMP_V && buf[ICMP_TYPE_P]==ICMP_TYPE_ECHOREQUEST_V){
                        // a ping packet, let's send pong
                        make_echo_reply_from_request(buf,plen);
                        continue;
                }
                // we listen on port 1200=0x4B0
                if (buf[IP_PROTO_P]==IP_PROTO_UDP_V&&buf[UDP_DST_PORT_H_P]==4&&buf[UDP_DST_PORT_L_P]==0xb0){

                        PORTD &= ~(1<<4);
                        PORTD &= ~(1<<3);
                        PORTD &= ~(1<<1);
                        PORTD &= ~(1);
                        PORTC |= (1<<4);
                        payloadlen=buf[UDP_LEN_L_P]-UDP_HEADER_LEN;
                        if(buf[UDP_DATA_P]=='p'){
                                pack_dif = buf[UDP_DATA_P+1]-old_packid;

                                if(pack_dif > 200){
                                        pack_dif = 1;
                                }

                                PORTD |= (pack_dif & 1);
                                PORTD |= (pack_dif & 2);
                                PORTD |= ((pack_dif & 4)<<1);
                                PORTD |= ((pack_dif & 8)<<1);
                                        
                                old_packid = buf[UDP_DATA_P+1];
                        }

                        PORTC &= ~(1<<4);

                }
        //udp_test_sender(buf);
        }
        return (0);
}
