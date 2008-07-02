from classMeas import *

############################

def rot(xyzi):
  xx=0.0715
  yy=-0.351
  zz=0
  x1=xyzi[0].value()
  y1=xyzi[1].value()
  z1=xyzi[2].value()
  i=xyzi[3]
  
  ### Rot. about x
  x2=x1
  y2=cos(xx)*y1-sin(xx)*z1
  z2=sin(xx)*y1+cos(xx)*z1
  
  ### Rot. about y
  x3=cos(yy)*x2+sin(yy)*z2
  y3=y2
  z3=-sin(yy)*x2+cos(yy)*z2

  ### Rot. about z
  x=cos(zz)*x3-sin(zz)*y3
  y=sin(zz)*x3+cos(zz)*y3
  z=z3
  
  g=[x,y,z]
  return g[i]

############################

def decFlags(flags):
  flags=flags[0].value()
  string=""
  if flags & 0x04:
    string+="Fuel "
  if flags & 0x01:
    string+="Main "
  if flags & 0x02:
    string+="KL15 "
  if flags & 0x20:
    string+="Error "
  return string

############################

def calcRatio(data):
  rpm=data[0]
  speed=data[1]
  if rpm==0:
    return None
  return speed/rpm

#### ACTUAL MEASUREMENTS

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

waterTemp=meas(46,-150.0/3840,120)
airTemp=meas(48,-150.0/3840,120)
potmeter=meas(50)
rpm=meas(54,0.9408)
triggerErr=meas(56)
camAngle1=meas(58,t="i")
camAngle2=meas(60,t="i")
roadSpeed=meas(62)
mapSensor=meas(64)
batteryV=meas(66,1.0/210)
lambdaV=meas(68,t="i")

load=meas(74,100.0/3840)

injectorTime=meas(78)
ignitionTime=meas(82)
dwellTime=meas(84)

gX=meas(96,1.0/16384,t="i")
gY=meas(98,1.0/16384,t="i")
gZ=meas(100,1.0/16384,t="i")

motorFlags=meas(111,l=1)
outBits=meas(113,l=1)

#### VIRTUAL MEASUREMENTS

x=virtMeas([gX,gY,gZ,0],rot)
y=virtMeas([gX,gY,gZ,1],rot)
z=virtMeas([gX,gY,gZ,2],rot)

flags=virtMeas([outBits],decFlags)

ratio=virtMeas([rpm,roadSpeed],calcRatio)