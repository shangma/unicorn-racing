#### CONFIGURATION FOR THE CSV GENERATOR
## DEFINE LABELS AND DECIMALS, DEFAULTS TO "" AND 1
##
## THE AVAILABLE OBJECTS ARE DEFINED IN "defineData.py"

from defineData import *

statusTime.label="Time"

waterTemp.label="CLT"
roadSpeed.label="Speed"
rpm.label="RPM"
rpm.decimals=0
statusLapTime.label="Lap T"
statusLapCount.label="Lap #"
statusLapCount.decimals=0

potmeter.label="TP"

triggerErr.label="Synch"
triggerErr.decimals=0

airTemp.label="IAT"
mapSensor.label="MAP"
mapSensor.decimals=0
lambdaV.label="lambda"
lambdaV.decimals=0
load.label="Load"

batteryV.label="Bat"

x.label="X"
x.decimals=3
y.label="Y"
y.decimals=3
z.label="Z"
z.decimals=3

flags.label="Flags"

ratio.label="Ratio"

#### APPEND THE WANTED MODULES TO THE DISPLAY LIST

display=[]
display.append(statusTime)
display.append(waterTemp)
display.append(rpm)
display.append(roadSpeed)
display.append(statusLapCount)
display.append(statusLapTime)
display.append(potmeter)
display.append(x)
display.append(y)
display.append(z)
display.append(airTemp)
display.append(mapSensor)
display.append(triggerErr)
display.append(lambdaV)
display.append(load)
display.append(batteryV)
display.append(ratio)
display.append(flags)
