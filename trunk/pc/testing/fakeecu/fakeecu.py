#!/usr/bin/env python
# coding: utf-8

import serial
from string import strip
from binascii import hexlify, unhexlify
from time import sleep

rpmScale = 0.9408   # Faktor rpm fra ecu skal ganges med for at blive rigtig
rpmDataPos = 54     # Byte nummer i strengen hvor rmp står
rpmDataSize = 2     # Længden af rmp i byte

tty=serial.Serial("/dev/ttyUSB1",19200,timeout=1)
datalogfile=open("testdatalog.txt","r")

while 1:
	ttydata=hexlify(tty.read(10))
	#print ttydata
	if ttydata=="12345678170800000000":
		#print ttydata
		data=strip(datalogfile.readline(),"\n\r")
		if len(data)==0:
			print "EOF reached\n"
			datalogfile.close
			datalogfile=open("testdatalog.txt")
			print "File reopened\n"
			data=strip(datalogfile.readline(),"\n\r")
		tty.flushOutput()
		rpm = int((int(data[rpmDataPos*rpmDataSize:rpmDataPos*2+2*rpmDataSize],16)*rpmScale ))
		print rpm		
		tty.write(unhexlify(data))
		#print "Sent:"
		#print data
		tty.flushInput()

	else:
		#print "No data received\n"
		tty.flushInput()
		tty.flushOutput()

datalogfile.close
