#! /usr/bin/python

from binascii import hexlify, unhexlify
from time import sleep

from os import name
import socket

host = "localhost"
port = 21567
buf = 1024
addr = (host,port)
    
UDPSock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
UDPSock.bind(addr)

from configDisplay import *

while 1:
  data = UDPSock.recv(buf)
  rpm.updateData(data)

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
