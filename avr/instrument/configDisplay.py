from defineData import *

statusTime.label="Time"

waterTemp.label="CLT"
waterTemp.upperL=105
waterTemp.lowerL=75

roadSpeed.label="Speed"

rpm.label="RPM"
rpm.upperL=10000
rpm.lowerL=5000

statusLapTime.label="Lap T"
statusLapCount.label="Lap #"
statusLapCount.decimals=0

potmeter.label="TP"
gX.label="X"
gX.upperL=1.5
gX.lowerL=-1.5
gX.decimals=3

gY.label="Y"
gY.upperL=1.5
gY.lowerL=-1.5
gY.decimals=3

gZ.label="Z"
gZ.upperL=1.5
gZ.lowerL=0.5
gZ.decimals=3

triggerErr.label="Synch"
triggerErr.decimals=0

airTemp.label="IAT"
mapSensor.label="MAP"
lambdaV.label="lambda"
load.label="Load"

batteryV.label="Bat"

display=[]
display.append(statusTime)
display.append(waterTemp)
display.append(rpm)
display.append(roadSpeed)
display.append(statusLapCount)
display.append(statusLapTime)
display.append(potmeter)
display.append(gX)
display.append(gY)
display.append(gZ)
display.append(airTemp)
display.append(mapSensor)
display.append(triggerErr)
display.append(lambdaV)
display.append(load)
display.append(batteryV)
