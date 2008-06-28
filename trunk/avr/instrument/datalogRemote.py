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

dataLogPath="C:\Documents and Settings\Laptop\Skrivebord\dataLogs\"

fileName=dataLogPath + strftime("%y-%m-%d %H%M") + ".txt"
print fileName

if name=="posix":
  print "Linux (I think) using " + linTTYs
  tty=serial.Serial(linTTYs, 19200, timeout=0.1)
else:
  print "Windows (or what?) using " + winTTYs
  tty=serial.Serial(winTTYs, 19200, timeout=0.1)

UDPSock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
logFile=open(fileName,"w")

w=0

while 1:

  while not tty.getCD():
    sleep(0.001)
    continue
  tty.flushInput()
  try:
    data=hexlify(tty.read(114))
    tmp=tty.inWaiting()
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