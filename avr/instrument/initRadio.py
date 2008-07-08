#! /usr/bin/python

import serial
from time import sleep

ttyName="COM1"
tty=serial.Serial(ttyName, 19200, timeout=0.35)

sleep(1)
print "SENDING: +++"
tty.write("+++")
sleep(3)
tmp=tty.inWaiting()
print "RECEIVING: " + tty.read(tmp)
sleep(1)
print "SENDING: AT^SETUP"
tty.write("\r\nAT^SETUP\r\n")
sleep(3)
tmp=tty.inWaiting()
print "RECEIVING: " + tty.read(tmp)
sleep(1)
print "SENDING: ATO"
tty.write("\r\nATO\r\n")
sleep(5)
tmp=tty.inWaiting()
print "RECEIVING: " + tty.read(tmp)
sleep(1)