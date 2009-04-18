# UDP client example
import socket
import time
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
print "Sender til 192.168.1.2 paa port 1200"
tal1=3
tal2=6
while 1:
	data = raw_input("Type something(q or Q to exit): ")
	if (data <> 'q' and data <> 'Q'):
		client_socket.sendto("data: %s" %data, ("192.168.1.2",1200))
	else:
		break
	
		

client_socket.close()

