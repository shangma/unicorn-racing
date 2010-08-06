#! /usr/bin/env python

from time import sleep
import time

f = open('endurance.txt', 'r')

j = 0
for line in f:
        if j>1:
            if len(line) > 10:
                print line,
            time.sleep(0.1)
        j = j +1

f.close()
