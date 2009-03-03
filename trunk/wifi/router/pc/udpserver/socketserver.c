#include <stdio.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

#define BUFFSIZE 255
void Die(char *mess) { perror(mess); exit(1); }


#define SERVER_PORT 1200
//#define LOCAL_IP 192.168.1.2

int main(int argc, char *argv[]) {
            int sock;
            struct sockaddr_in echoserver;
            struct sockaddr_in echoclient;
            char buffer[BUFFSIZE];
            unsigned int echolen, clientlen, serverlen;
            int received = 0;
	    int k=0;
	    int runs=0;
	    int servreceived=0;
	    int recvchar[10];

          printf("Starting udp-server at port 1200\n");
/* Create the UDP socket */
          if ((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
            Die("Failed to create socket");
          }
          /* Construct the server sockaddr_in structure */
          memset(&echoserver, 0, sizeof(echoserver));       /* Clear struct */
          echoserver.sin_family = AF_INET;                  /* Internet/IP */
          echoserver.sin_addr.s_addr = htonl(INADDR_ANY);   /* Any IP address */
          echoserver.sin_port = htons(SERVER_PORT);       /* server port */

          /* Bind the socket */
          serverlen = sizeof(echoserver);
          if (bind(sock, (struct sockaddr *) &echoserver, serverlen) < 0) {
            Die("Failed to bind server socket");
          }
	while(1){
	/* Receive a message from the client */
              clientlen = sizeof(echoclient);
              if ((received = recvfrom(sock, buffer, BUFFSIZE, 0,
                                       (struct sockaddr *) &echoclient,
                                       &clientlen)) < 0) {
                Die("Failed to receive message");
              }
		printf("Received %s\n",buffer);
	servreceived=(buffer[0]|buffer[1]<<8);
        printf("Received %d mV\n",servreceived);

	for(k=0;k<50;k++){
                printf("%02x ",buffer[k]);
        }
        printf("\n");
	
              //fprintf(stderr,
              //        "Client connected: %s\n", inet_ntoa(echoclient.sin_addr));
        printf("Runs: %d\n",runs);
	runs++;
	}
}
