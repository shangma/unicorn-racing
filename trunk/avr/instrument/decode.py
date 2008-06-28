#! /usr/bin/python

#from uspp import *
from binascii import hexlify, unhexlify
from time import sleep

from os import name
import socket

#linTTYs="/dev/ttyS0"
#winTTYs="COM5"

host = "localhost"
port = 21567
buf = 1024
addr = (host,port)

#if name=="posix":
#  print "Linux (I think) using " + linTTYs
##  tty=SerialPort(linTTYs, 70, 19200)
#else:
#  print "Windows (or what?) using " + winTTYs
##  tty=SerialPort(winTTYs, 70, 19200)

rdOnly="12345678"
H8cmd=hexlify(chr(23))
reqStatus="0800000000"
    
UDPSock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
UDPSock.bind(addr)

def requestStatus():
  print "Requesting status: " + rdOnly+H8cmd+reqStatus
#  tty.write(unhexlify(rdOnly+H8cmd+reqStatus))

from configDisplay import *

reply=True

#print rdOnly+H8cmd+reqStatus
#print unhexlify(rdOnly+H8cmd+reqStatus)
c=0
#d=0



while 1:
  data = UDPSock.recv(buf)
  
  c+=1
  
  if reply or c==5:
#    requestStatus()
    reply=False
  

#  print data
  rpm.updateData(data)
  reply=True
    
  if reply:
    c=0

    print
    
    for item in display:
      print item.label + "\t",
      
    print
      
    for item in display:
      print item.s() + "\t",

    print
    
    for item in display:
      if item.value() > item.upperL or item.value() < item.lowerL:
        print "#######",
      else:
        print "-------",
        
    print

    triggerErr.upperL=triggerErr.value()
