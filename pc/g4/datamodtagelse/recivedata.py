#!/usr/bin/env python
# -*- coding: utf-8 -*-

import serial

ser=serial.Serial("/dev/ttyUSB1",115200)

sold = 0
speed = 0
temp = 0
air = 0
batt = 0
print "startet"
while 1:
    tmp = ser.read(1)
    if ord(tmp) == 123:
        tmp = ser.read(1)
        if ord(tmp) == 255:
            tmp = ser.read(1)
            if ord(tmp) == 10:
                #print "data modtaget"
                tmp = ser.read(11)
		if ord(tmp[0]) == 0:
			speed = int(((ord(tmp[3])<<8)+ord(tmp[4]))*0.01*0.2+sold*0.8)
			sold = speed
			temp = int( ((ord(tmp[5])<<8)+ord(tmp[6]))*(-150.0/3840)+120)
			air = int( ((ord(tmp[7])<<8)+ord(tmp[8]))*(-150.0/3840)+120)
			batt = int( ((ord(tmp[9])<<8)+ord(tmp[10]))*(1./210))
			print "Rpm: {0:5d} Speed: {1:3d} Vand temp: {2:3d} Luft temp: {3:3d} Batt: {4:2d} v".format(int((ord(tmp[1])<<8)+ord(tmp[2])*0.9408), speed, temp, air, batt)
		elif ord(tmp[0]) == 1:
			print "ECU communication error"
		else:
			print "data error"
    else:
        print "no data"
