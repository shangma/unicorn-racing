from defineData import *

statusTime.label="Time"

waterTemp.label="CLT"
waterTemp.upperL=23.8

roadSpeed.label="Speed"

rpm.label="RPM"
rpm.upperL=200

statusLapTime.label="Lap T"
statusLapCount.label="Lap #"

potmeter.label="TP"
gX.label="X"
gX.upperL=1.5
gX.lowerL=-1.5

gY.label="Y"
gY.upperL=1.5
gY.lowerL=-1.5

gZ.label="Z"
gZ.upperL=1.5
gZ.lowerL=0.5

triggerErr.label="Synch"

airTemp.label="IAT"
mapSensor.label="MAP"
lambdaV.label="lambda"
load.label="Load"

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

