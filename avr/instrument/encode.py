#! /usr/bin/python

from uspp import *
from binascii import hexlify, unhexlify


#tty=SerialPort("/dev/ttyS0", None, 19200,[8,"NOPARITY",2])
tty=SerialPort("/dev/ttyS0", None, 19200)

replyA=""

rpmH="aa"
rpmL="55"

int("0352",16)

rpm=0;
#for rpm in range(5000,12000,1000):
#  rpmHEX=hex(rpm)[2:]
#  rpmHEX2=hex(rpm>>6)[2:]
#  print "============"
#  print rpm
#  print rpm>>6
#  print rpmHEX
#  print rpmHEX2

for i in range(0,54):
  replyA+="00"

#dat=unhexlify(replyA+rpmHEX+replyA)
#print len(dat)
#print replyA+"1111"
while 1:

  rpm=(rpm+100)%8000
#  print "===="
#  print hex(rpm)
#  print hex(rpm<<2)
  tmp=hex(rpm+4000)[2:]
  rpmHEX="0000"[0:4-len(tmp)]+tmp
#  print rpmHEX

  dat=unhexlify(replyA+rpmHEX+replyA)

  reqRAW=tty.read(10)
  reqHEX=hexlify(reqRAW)
  print reqHEX
  tty.flush()
  if reqHEX[17:19]=="00":
    tty.write(dat)
    print "hej"
