//---------------------------------------------------------------------
//Client that will send messages through the TCP protocol
//---------------------------------------------------------------------
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/time.h>
#include <arpa/inet.h>
//---------------------------------------------------------------------
using namespace std;

//Structure Declarations-----------------------------------------------
struct sockaddr_in ServerAddress;			

//Variable Declarations-----------------------------------------
int fd;	//Socket File Descriptors
int size_sent;
int connection_ok;
char messageBuffer[20]="TCP PROTOCOL";
int result = 0;
//Main Function--------------------------------------------------------
int main()
{
	fd=socket(AF_INET, SOCK_STREAM, 0);
	if(fd==-1)
	{
		cerr<<"error couldnt create socket"<<endl;
		exit(1);
	}

	ServerAddress.sin_family=AF_INET;
	ServerAddress.sin_port= htons(2005);
	ServerAddress.sin_addr.s_addr=inet_addr("192.168.0.1");

	connection_ok=connect(fd,(sockaddr *)&ServerAddress ,sizeof(ServerAddress));
	if(connection_ok==-1)
	{
		cerr<<"unable to connect"<<endl;
		exit(1);
	}
	size_sent = send(fd, messageBuffer, sizeof(messageBuffer), 0);
	close(fd);	
	
   	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////
