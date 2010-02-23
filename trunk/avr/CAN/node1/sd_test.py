#!/usr/bin/env python

import serial
import time

ser = serial.Serial()
ser.baud = 9600 
ser.port = '/dev/ttyUSB0'
ser.open()

t1 = time.time()
for i in range(1000):
	ser.write('s')
	ser.read(1)
t2 = time.time()
print t2-t1
