#! /usr/bin/python

from uspp import *
from binascii import hexlify, unhexlify
from time import sleep

from os import name

linTTYs="/dev/ttyS0"
winTTYs="COM3"

if name=="posix":
  print "Linux (I think) using " + linTTYs
  tty=SerialPort("/dev/ttyS0", 1000, 19200)
else:
  print "Windows (or what?) using " + winTTYs
  tty=SerialPort("COM3", 1000, 19200)

rdOnly="12345678"
H8cmd=hexlify(chr(23))
reqStatus="0800000000"
    

def requestStatus():
#  print "Requesting status: " + rdOnly+H8cmd+reqStatus
  tty.write(unhexlify(rdOnly+H8cmd+reqStatus))

from configDisplay import *

reply=True

#print rdOnly+H8cmd+reqStatus
#print unhexlify(rdOnly+H8cmd+reqStatus)
c=0
d=0

#print gX.retHex()

while 1:
  sleep(0.05)
  
  c+=1
  
  if reply or c==5:
    requestStatus()
    reply=False
  
  sleep(0.01)
  tmp=tty.inWaiting()
  
  if tmp==114:
#    data=hexlify(tty.read(114))
#    newData(hexlify(tty.read(114)))
    rpm.updateData(hexlify(tty.read(114)))
    reply=True
#  else:
#    print "Rx buffer length: " + str(tmp)

  if tmp!=114 and c==8:
    reply=True
    rpm.scrollData()
    d=(d+1)%len(dataM)

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
