#! /usr/bin/python

#from uspp import *
import serial
from binascii import hexlify, unhexlify
from os import name
from time import sleep, time, strftime
import socket

host = "localhost"
port = 21567
buf = 1024
addr = (host,port)

linTTYs="/dev/ttyS0"
winTTYs="COM5"

############################# 
#dataLogPath="C:\\Documents and Settings\\Laptop\\Skrivebord\\dataLogs\\"
dataLogPath="C:\\dataLogs\\"    # FIXME: hent path fra config fil

fileName=dataLogPath + "dataLog " + strftime("%y-%m-%d %H%M") + ".txt"
print fileName

rdOnly="12345678"
H8cmd=hexlify(chr(23))
reqStatus="0800000000"

if name=="posix":
  print "Linux (I think) using " + linTTYs
  tty=serial.Serial(linTTYs, 19200, timeout=0.25)
else:
  print "Windows (or what?) using " + winTTYs
  tty=serial.Serial(winTTYs, 19200, timeout=0.25)

tty.setDTR(1)   #DTR is used to power the CarrierDetect generator circuit

def requestStatus():
  print "Requesting status: " + rdOnly+H8cmd+reqStatus
  tty.write(unhexlify(rdOnly+H8cmd+reqStatus))

tty.flushInput()
sleep(1)
print "SENDING: +++"
tty.write("+++")
sleep(5)
tmp=tty.inWaiting()
print "RECEIVING: " + tty.read(tmp)
sleep(2)
print "SENDING: AT^SETUP"
tty.write("\r\nAT^SETUP\r\n")
sleep(5)
tmp=tty.inWaiting()
print "RECEIVING: " + tty.read(tmp)
sleep(2)
print "SENDING: ATO"
tty.write("\r\nATO\r\n")
sleep(5)
tmp=tty.inWaiting()
print "RECEIVING: " + tty.read(tmp)
sleep(2)

print tty.read(10)

UDPSock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
logFile=open(fileName,"w")

w=0

while 1:

############################# 
#  while not tty.getCD():
#    sleep(0.001)
#    continue
  tty.flushInput()

############################# ADDED FOR DIRECT DATALOG  
  requestStatus()
  sleep(0.5)
#############################  
  try:
    data=hexlify(tty.read(114))
    if len(data)!=228:
      print len(data)
      continue
#    tmp=tty.inWaiting()
  except:
    print "Timeout, resynch..."
    sleep(1)
    continue
    
  logFile.write(data+"\n")
  if w==2:
    UDPSock.sendto(data,addr)
    w=0
  else:
    w+=1