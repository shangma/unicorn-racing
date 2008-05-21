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

global data
data="0000000000170000000000173DB9F6E40000000000000000000000000000000001253C1100000000000000000000095A096801F000030000000000000000000004F80AA6F100000000000548000051C99C060092000801F40000005B028F028F13B3046F3C73000000000000000000142A02"
data="00000000001700000000001F401B0068000000000000000000000000000000000123406F00000000000000000000095A096801F000040000000000000000000004F80ABEF100000000000548000051B59C060092000801F40000005A028F028F13B604713C82000000000000000000142A02"
data="00000000001700000000001742356F3800000000000000000000000000000000012449A100000000000000000000095A096801F000030000000000000000000004F80AA8F100000000000548000051BF9C060092000801F40000005B028F028F13B2046E3C7F000000000000000000142A02"

rdOnly="12345678"
H8cmd=hexlify(chr(23))
reqStatus="0800000000"

class meas:
  dataOffset=0
  dataLength=2
  dataType="w"
  gain=1
  offset=0
  def __init__(self,n=0,g=1,o=0,t="w",l=2):
    self.dataOffset=n*2
    self.dataLength=l*2
    self.dataType=t
    self.gain=g
    self.offset=o
    
  def value(self):
    if self.dataType=="w":
      tmp=self.retWord()
    elif self.dataType=="l":
      tmp=self.retWord()
    elif self.dataType=="i":
      tmp=self.retInt()
    return tmp*self.gain+self.offset
    
  def retHex(self):
    return data[self.dataOffset:self.dataOffset+self.dataLength]
    
  def retWord(self):
    return int(self.retHex(),16)
    
  def retLong(self):
    return int(self.retHex(),16)
    
  def retInt(self):
    return int(self.retHex(),16)
    
  def s(self):
    return str(self.value())

def requestStatus():
  print "Requesting status: " + rdOnly+H8cmd+reqStatus
  tty.write(unhexlify(rdOnly+H8cmd+reqStatus))

fuelPressure=meas(0)
statusLapCount=meas(2)
statusInjSum=meas(4)
lastGearShift=meas(6)
motorOilTemp=meas(8)
oilPressure=meas(10)
statusTime=meas(12,0.000001,0,"l",4)
statusLapTime=meas(16,0.000001,0,"l",4)
gearOilTemp=meas(20)
statusTraction=meas(22)
statusGas=meas(24)
statusLambdaV2=meas(26)
statusCamTrigP1=meas(28)
statusCamTrigP2=meas(30)
statusChokerAdd=meas(32)
statusLambdaPWM=meas(34)

waterTemp=meas(46,0.01)
airTemp=meas(48,0.01)

potmeter=meas(50)
rpm=meas(54)
roadSpeed=meas(62)
mapSensor=meas(64)

batteryV=meas(66)

gX=meas(96,0.00006)
gY=meas(98,0.00006)
gZ=meas(100,0.00006)

reply=True

print rdOnly+H8cmd+reqStatus
print unhexlify(rdOnly+H8cmd+reqStatus)
c=0
while 1:
  sleep(1)
  
  c+=1
  
  if reply or c==5:
    requestStatus()
    reply=False
  
  tmp=tty.inWaiting()
  
  if tmp==114:
    data=hexlify(tty.read())
    reply=True
  else:
    print "Rx buffer length: " + str(tmp)

  if tmp!=114 and c==8:
    reply=True

  if reply:
    c=0
    print data[:114]
    print data[114:]

    print "waterT:\t" + waterTemp.s()
    print "airT:\t" + airTemp.s()

    print "X:\t" + gX.s()
    print "Y:\t" + gY.s()
    print "Z:\t" + gZ.s()

    print "RPM:\t" + rpm.s()

    print "Time:\t" + statusTime.s()
    print "Lap:\t" + statusLapTime.s()
