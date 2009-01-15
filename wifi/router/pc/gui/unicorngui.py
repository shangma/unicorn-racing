#!/usr/bin/env python

#Gui for unicorn race engineering

import pygtk
pygtk.require('2.0')
import gtk, gobject
import threading, os

t1, t2 = 0, 0


from os import name
import socket

from binascii import hexlify, unhexlify
from fpformat import fix

from classMeas import *
from defineData import *

from time import sleep

#Create a socket to receive data
host = "192.168.2.219"
port = 21567
buf = 1024
addr = (host,port)

UDPSock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
UDPSock.bind(addr)

class UpdateData (threading.Thread):
	def __init__(self, nUpobj):
		global upobj
		upobj=nUpobj
		threading.Thread.__init__ ( self )

	def run(self):
		while 1:
			#Retreive data from the socket
			data_buf = UDPSock.recv(buf)
			data=hexlify(data_buf)
	
			#Decoding the received data set. 
			## meas(data,n=0,g=1,o=0,t="w",l=2)
			## data,byteOffset,gain,offset,type,length
		
			waterTemp=meas(data,46,-150.0/3840,120).value()
			airTemp=meas(data,48,-150.0/3840,120).value()
			potmeter=meas(data,50,0.0510,-31.4).value()
			rpm=meas(data,54,0.9408).value()
	
			ecutime=meas(data,12,0.000001,0,"l",4).value()
	
			##Update the label in the GUI
			upobj.rpm_label.set_text(str(fix(rpm,0)))
			upobj.clt_label.set_text(str(fix(waterTemp,1)))
			upobj.iat_label.set_text(str(fix(airTemp,1)))
			upobj.time_label.set_text(str(fix(ecutime,1)))

			#print "Runs: " + str(runs)
			#runs=runs+1
			sleep(0.1)

class MainWindow(threading.Thread):

	def __init__(self):
		gtk.gdk.threads_init()
		self.window = gtk.Window(gtk.WINDOW_TOPLEVEL)
		self.window.connect("destroy", lambda w: gtk.main_quit())
					
		self.window.set_title("Unicorn Race Engineering")
	
		hbox=gtk.HBox(False,5)
		self.window.add(hbox)
		

		vbox=gtk.VBox(False, 5)
		vbox.set_border_width(10)
		hbox.pack_start(vbox, False, False, 0)
		
		#Create a 10x10 table, used to display engineinformation
		engine_table = gtk.Table(10, 10, False)		
		engine_frame = gtk.Frame("Engineinformation")
		engine_frame.add(engine_table)

		label = gtk.Label("RPM:")
		engine_table.attach(label,1,2,1,2)
		self.rpm_label = gtk.Label("0")
		engine_table.attach(self.rpm_label,2,3,1,2)

		label = gtk.Label("Intake air temperature:")
		engine_table.attach(label,1,2,2,3)
		self.iat_label = gtk.Label("0")
		engine_table.attach(self.iat_label,2,3,2,3)

		label = gtk.Label("Coolant temperature:")
		engine_table.attach(label,1,2,3,4)
		self.clt_label = gtk.Label("0")
		engine_table.attach(self.clt_label,2,3,3,4)

		label = gtk.Label("Speed (km/t)")
		engine_table.attach(label,1,2,4,5)
		self.speed_label = gtk.Label("0")
		engine_table.attach(self.speed_label,2,3,4,5)

		label = gtk.Label("ECU time:")
		engine_table.attach(label,1,2,5,6)
		self.time_label = gtk.Label("0")
		engine_table.attach(self.time_label,2,3,5,6)	

		#Pack the engine information in a frame
		vbox.pack_start(engine_frame, False, False, 0)


		gtk.gdk.threads_enter()
		UpdateData(self).start()
		t2 = os.getpid()
		gtk.gdk.threads_leave()

		self.window.show_all()
		print t2	
		
		
def main():
	gtk.main()
	return 0


if __name__ == "__main__":
	MainWindow()
	main()
	t2 = os.getpid()
	print t2
	os.popen("kill -9 "+str(t2))
