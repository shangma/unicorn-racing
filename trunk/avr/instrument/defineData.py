from classMeas import *

one=float(1)

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

waterTemp=meas(46,0.01) #old gain: 0.01
airTemp=meas(48,0.01)
potmeter=meas(50)
rpm=meas(54)
triggerErr=meas(56)
camAngle1=meas(58)
camAngle2=meas(60)
roadSpeed=meas(62)
mapSensor=meas(64)
batteryV=meas(66)
lambdaV=meas(68)

load=meas(74)

injectorTime=meas(78)
ignitionTime=meas(82)
dwellTime=meas(84)

gX=meas(96,one/16384) #old gain: 0.00006
gY=meas(98,one/16384)
gZ=meas(100,one/16384)
