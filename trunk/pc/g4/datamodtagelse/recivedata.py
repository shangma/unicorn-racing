#!/usr/bin/env python
# -*- coding: utf-8 -*-

import serial

ser=serial.Serial("/dev/ttyUSB0",115200)

sold = 0
speed = 0
temp = 0
air = 0
batt = 0
pot = 0
Map = 0
Lambda = 0
print "startet"
while 1:
    tmp = ser.read(1)
    if ord(tmp) == 123:
        tmp = ser.read(1)
        if ord(tmp) == 255:
            tmp = ser.read(1)
            if ord(tmp) == 10:
                #print "data modtaget"
                tmp = ser.read(17)
		if ord(tmp[0]) == 0:
			speed = int(((ord(tmp[3])<<8)+ord(tmp[4]))*0.01*0.2+sold*0.8)
			sold = speed
			temp = int( ((ord(tmp[5])<<8)+ord(tmp[6]))*(-150.0/3840)+120)
			air = int( ((ord(tmp[7])<<8)+ord(tmp[8]))*(-150.0/3840)+120)
			batt = int( ((ord(tmp[9])<<8)+ord(tmp[10]))*(1./210))
			pot = int( ((ord(tmp[11])<<8)+ord(tmp[12]))*(0.0510)-31.4)
			Map = int( ((ord(tmp[13])<<8)+ord(tmp[14]))*(1.0/800/5*3000))
			Lambda = int( ((ord(tmp[15])<<8)+ord(tmp[16]))*(-14.7*0.6/3840)+0.7*14.7)
			print "Rpm: {0:5d} Speed: {1:3d} Vand temp: {2:3d} Luft temp: {3:3d} Batt: {4:2d} Pot: {5:3d} Map: {6:4d} Lambda: {7:4d}".format(int((ord(tmp[1])<<8)+ord(tmp[2])*0.9408), speed, temp, air, batt, pot, Map, Lambda)
		elif ord(tmp[0]) == 1:
			print "ECU communication error"
		else:
			print "data error"
    else:
        print "no data"
