#! /usr/bin/python

import serial
from binascii import hexlify, unhexlify
from os import name
from time import sleep, time, strftime
import socket
from string import strip

#### MODE
# FIXME: AUTODETECT
remote=True
remote=False

passive=True
#passive=False
################################

#### READ CONFIG
print "Reading config:\t\tdatalogConfig.txt"
configFile=open("datalogConfig.txt","r")
dataLogPath=strip(configFile.readline(),"\n\r")
ttyName=strip(configFile.readline(),"\n\r")
configFile.close()
################################

fileName=dataLogPath + "dataLog " + strftime("%y-%m-%d %H%M") + ".txt"
print "Logging data to:\t" + fileName

host = "localhost"
port = 21567
buf = 1024
addr = (host,port)

print "Serial interface:\t" + ttyName
tty=serial.Serial(ttyName, 19200, timeout=0.25)

tty.setDTR(1)   #DTR is used to power the CarrierDetect generator circuit

################################

def requestStatus():
#rdOnly="12345678"
#H8cmd="17" #hexlify(chr(23))
#reqStatus="0800000000"
  print "Requesting status..."
  tty.write(unhexlify("12345678"+"17"+"0800000000"))

tty.flushInput()

################################

def initRadio():
  sleep(2)
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

################################

UDPSock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
logFile=open(fileName,"w")

w=0

if remote:
  initRadio()

while 1:

  if passive: 
    while not tty.getCD():
      sleep(0.001)
      continue
    tty.flushInput()
  else:  
    requestStatus()
    sleep(0.5)
  
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