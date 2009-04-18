# UDP client example
import socket
import time
import threading
import sys

class UDPRecv ( threading.Thread ):
    def run ( self ):
        

        print "UDPServer Waiting for client on port 3000"

        while running:
            data, address = socket.recvfrom(256)
            print "( " ,address[0], " " , address[1] , " ) said : ", data

socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
socket.bind(("", 1200))
running=1	
UDPRecv().start()


print "Sender til 192.168.1.2 paa port 1200"
tal1=3
tal2=6
while 1:
	data = raw_input("Type something(q or Q to exit): ")
	if (data <> 'q' and data <> 'Q'):	
		socket.sendto(data, ("192.168.0.200",1200))
		time.sleep(0.1)
	else:
		break


running = 0
socket.close()
sys.exit(0)
