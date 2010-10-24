#!/usr/bin/env python
#-*- coding:utf-8 -*-

from pylab import *
import codecs

f = open('jens.txt', 'r')

data = f.read()
data2 = data.split('\r\n')

data3 = []

vand1 = []
vand2 = []
olie = []

for streng in data2:
    if len(streng) > 1:
        if streng[0] == '1':
            vand1.append(138.34*exp(-0.015*int(str.split(str.split(streng,',')[0],'=')[1])))
            vand2.append(138.34*exp(-0.015*int(str.split(str.split(streng,',')[1],'=')[1])))
            olie.append(int(str.split(str.split(streng,',')[2],'=')[1]))

plot(vand1)
plot(vand2)


savetxt('wireless_data_jens.csv', flipud(rot90(vstack([vand1,vand2,olie]))), delimiter=',')
f = open('wireless_data_jens.csv', 'r')
tmp = f.read()
f.close()
f = codecs.open('wireless_data_jens.csv', encoding='utf-8', mode='w')
f.write(u'Vand ud af køler, Vand ind i køler, Olie\n')
f.write(tmp)
f.close()

show()

