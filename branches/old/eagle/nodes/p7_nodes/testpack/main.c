#include <stdio.h>
#include <string.h>
void printhex(int len);
void makemac();
void makeip();
void dopack(int len);
void makeudp(char *data,int data_len);
unsigned int checksum(unsigned int *buf, unsigned int len,unsigned int type);

int mac_buffer[14];
int ip_buffer[20];
int udp_buffer[100];
int buffer[255];
unsigned int ck;



int main(void){

char data[200] = "ABCD";		//udp = ee95     ip = e63e


makeudp(data, strlen(data));

makeip();
makemac();

dopack(42+strlen(data));
ck = checksum(udp_buffer, 20, 1);
printhex(42+strlen(data));
printf("\n\n checksum belv: %x\n",&ck);
}







void makeudp(char *data,int data_len){
// Starter med at smide Dest mac ind på de 6 første, derefter Source på de 6 næste og til sidst 0800 for IPv4

int i;
int src_port[2] = {0x08,0x00};
int dest_port[2] = {0x08,0x00};
int udp_len[2] = {0x08,0x00};			//DET HER SKAL KODES!
int udp_chk[2] = {0x77, 0x77};			//DET HER SKAL KODES!

for (i=0; i<2; i++){
udp_buffer[i] = src_port[i];
}

for (i=0; i<2; i++){
udp_buffer[i+2] = dest_port[i];
}

for (i=0; i<2; i++){
udp_buffer[i+4] = udp_len[i];
}

for (i=0; i<2; i++){
udp_buffer[i+6] = udp_chk[i];
}

for (i=0; i<data_len; i++){
udp_buffer[i+8] = data[i];
}

}










void makeip(){
int i;
int version_headlen_tos[2] = {0x45,0x00};
int length_of_ip[2] = {0x00, 0x1c};		//DET HER SKAL KODES!
int ident_flag_offset_ttl[5] = {0x12, 0x34, 0x40, 0x00, 0xff};
int protocol = 0x11;				//UDP!!
int head_chk[2] = {0x77, 0x77};			//DET HER SKAL KODES!
int source_ip[4] = {192,168,1,4};
int dest_ip[4] = {192,168,1,5};

for (i=0; i<2; i++){
ip_buffer[i] = version_headlen_tos[i];
}

for (i=0; i<2; i++){
ip_buffer[i+2] = length_of_ip[i];
}

for (i=0; i<5; i++){
ip_buffer[i+4] = ident_flag_offset_ttl[i];
}

ip_buffer[i+9] = protocol;

for (i=0; i<2; i++){
ip_buffer[i+10] = head_chk[i];
}

for (i=0; i<4; i++){
ip_buffer[i+12] = source_ip[i];
}

for (i=0; i<4; i++){
ip_buffer[i+16] = dest_ip[i];
}

}









void makemac(){
// Starter med at smide Dest mac ind på de 6 første, derefter Source på de 6 næste og til sidst 0800 for IPv4

int i;
int eth_type[2] = {0x08,0x00};
int destmac[6] = {0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1};
int mymac[6] = {0xb1, 0xb1, 0xb1, 0xb1, 0xb1, 0xb1};


for (i=0; i<6; i++){
mac_buffer[i] = destmac[i];
}
for (i=0; i<6; i++){
mac_buffer[i+6] = mymac[i];
}
for (i=0; i<2; i++){
mac_buffer[i+12] = eth_type[i];
}

}










void dopack(int len){
int i;
for (i=0; i<14; i++){
buffer[i] = mac_buffer[i];
}
for (i=0; i<20; i++){
buffer[i+14] = ip_buffer[i];
}
for (i=0; i<(len+8); i++){
buffer[i+34] = udp_buffer[i];
}

}




unsigned int checksum(unsigned int *buf, unsigned int len,unsigned int type){
        // type 0=ip 
        //      1=udp		len = 16 + datalen
        //      2=tcp
        unsigned int sum = 0;

        if(type==1){
                sum+=17; // protocol udp
                // the length here is the length of udp (data+header len)
                // =length - IP addr length
                sum+=len-8; // = real udp len
        }
        if(type==2){
                sum+=6; 
                // the length here is the length of tcp (data+header len)
                // =length - IP addr length
                sum+=len-8; // = real tcp len
        }
        // build the sum of 16bit words
        while(len >1){
                sum += 0xFFFF & (*buf<<8|*(buf+1));
                buf+=2;
                len-=2;
        }
        // if there is a byte left then add it (padded with zero)
        if (len){
                sum += (0xFF & *buf)<<8;
        }
        // now calculate the sum over the bytes in the sum
        // until the result is only 16bit long
        while (sum>>16){
                sum = (sum & 0xFFFF)+(sum >> 16);
        }
        // build 1's complement:
        return(sum ^ 0xFFFF);
}






void printhex(int len){

int i;
printf("MAC: ");
for (i = 0; i < 14; i++)
   {
   printf("%02x ",mac_buffer[i]);
   }
printf("\n");

printf("IP: ");
for (i = 0; i < 20; i++)
   {
   printf("%02x ",ip_buffer[i]);
   }
printf("\n");

printf("UDP: ");
for (i = 0; i < 30; i++)
   {
   printf("%02x ",udp_buffer[i]);
   }
printf("\n");

printf("BUF: ");
for (i = 0; i < len; i++)
   {
   printf("%02x ",buffer[i]);
   }
printf("\n");

printf("D_BUF: ");
for (i = 0; i < len; i++)
   {
   printf("%c ",buffer[i]);
   }
printf("\n");


}
