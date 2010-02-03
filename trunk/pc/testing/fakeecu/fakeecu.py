import serial
from string import strip
from binascii import hexlify, unhexlify
from time import sleep

tty=serial.Serial("/dev/ttyUSB0",19200,timeout=0.05)
datalogfile=open("testdatalog.txt","r")

while 1:
	ttydata=hexlify(tty.read(10))
	print ttydata
	if ttydata=="12345678170800000000":
		print ttydata
		data=strip(datalogfile.readline(),"\n\r")
		if len(data)==0:
			print "EOF reached\n"
			datalogfile.close
			datalogfile=open("testdatalog.txt")
			print "File reopened\n"
		tty.flushOutput()
		tty.write(unhexlify(data))
		print "Sent:"
		print data
		tty.flushInput()

	else:
		print "No data received\n"
		tty.flushInput()
		tty.flushOutput()

datalogfile.close
