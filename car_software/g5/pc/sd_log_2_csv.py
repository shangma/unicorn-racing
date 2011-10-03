#!/usr/bin/env python

import sys
import numpy
import csv

fil = sys.argv[1]

f = open(fil, 'r')
rawData = numpy.fromfile(f, dtype=numpy.uint8)

water = ['water', 17, 2]
potmeter = ['pot', 19, 2]
rpm = ['rpm', 20, 2]
mapSensor = ['map', 25, 2]
batt = ['batt', 26, 2]
lambdaV = ['lambdav', 27, 2]


class measurement:
    def __init__(self, HumanReadAbleName, idNum, dataLength=2, gain=0, offset=0):
        self.name = HumanReadAbleName
        self.id = idNum
        self.length = dataLength
        self.gain = gain
        self.offset = offset
        self.values = []

    def add_val(self, val):
        self.values.append(val)

    def convert_data(self, data):
        tmp = 0
        for val, shift in zip(data, range( (len(data)-1)*8,-1,-8) ):
            tmp += val<<shift

        return tmp*self.gain+self.offset

dataDefs = []
dataDefs.append( measurement('water', 17, 2, -150.0/3840, 120) )
dataDefs.append( measurement('potmeter', 19, 2, 0.0510, -31.4) )
dataDefs.append( measurement('rpm', 20, 2, 0.9408, 0) )
dataDefs.append( measurement('mapSensor', 25, 2, 1.0/800/5*3000, 0) )
dataDefs.append( measurement('battery', 26, 2, 1.0/210, 0) )
dataDefs.append( measurement('lambda', 27, 2, -14.7*0.6/3840, 0.7*14.7) )


## Make to class when done
# Extract and convert values from sd data file
for i in range(len(rawData)):
    for datadef in dataDefs:
        if rawData[i] == datadef.id:
            for datadef2 in dataDefs:
                if datadef.length + i + 1 >= len(rawData):
                    print "Found ", datadef.name, " msg at ", i
                    datadef.add_val( datadef.convert_data( numpy.array([rawData[i+1], rawData[i+2]]) ) )
                    break
                elif rawData[ i+datadef.length+1 ] == datadef2.id:
                    print "Found ", datadef.name, " msg at ", i
                    datadef.add_val( datadef.convert_data( numpy.array([rawData[i+1], rawData[i+2]]) ) )
                    break


# Write extracted and converted values to a csv file
short = 2**64
for datadef in dataDefs:
    if len(datadef.values) < short:
        short = len(datadef.values)

for datadef in dataDefs:
    datadef.values = datadef.values[:short]

res = numpy.reshape(dataDefs[0].values, (len(dataDefs[0].values), 1) )
names = []
names.append(dataDefs[0].name)

for i in range(1,len(dataDefs)):
    res = numpy.hstack( (res, numpy.reshape(dataDefs[i].values, (len(dataDefs[i].values), 1)) ))
    names.append(dataDefs[i].name)




with open(fil.split('.')[0] + '.csv', 'w+') as f:
    writer = csv.writer(f)
    writer.writerow(names)
    writer.writerows(res)

