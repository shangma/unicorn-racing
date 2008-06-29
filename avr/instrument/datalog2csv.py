#! /usr/bin/python

from sys import argv
from configCSV import *
from time import sleep

###################################

def writeLabels(csvFile):
  for item in display:
    csvFile.write(item.label + ", ")
#    print item.label
#    sleep(0.5)

  csvFile.write("\n")

###################################

def writeData(logFile,csvFile):
  c=0
  eof=False
  while not eof:
    data=logFile.readline()
#    print data
#    print len(data)

    if len(data)==0:
      eof=True
      continue
    if not (len(data)==229 or len(data)==230):
      continue
    
    rpm.updateData(data)
    for item in display:
      csvFile.write(str(item.value()) + ", ")
      
    csvFile.write("\n")
#    sleep(0.1)
#    c+=1
    if c==10:
      eof=True

###################################

if len(argv)==1:
  exit()

argv=argv[1:]
for log in argv:
#  print log
  logFile=open(log,"r")
  csvFile=open(log + ".csv","w")
  writeLabels(csvFile)
  writeData(logFile,csvFile)
  logFile.close()
  csvFile.close()
