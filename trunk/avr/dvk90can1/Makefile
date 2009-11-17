# makefile, written by guido socher
MCU=at90can128
CC=avr-gcc
OBJCOPY=avr-objcopy
PROJECT=dvk90
# optimize for size:
CFLAGS=-g -mmcu=$(MCU) -Wall -Wstrict-prototypes -Os -mcall-prologues
#-------------------test0.hex test1.hex test2.hex
all: clean dvk90.hex

dvk90.hex: dvk90.out
	$(OBJCOPY) -R .eeprom -O ihex dvk90.out dvk90.hex 
	avr-size dvk90.out
	@echo " "
	@echo "Expl.: data=initialized data, bss=uninitialized data, text=code"
	@echo " "
dvk90.out: dvk90.o
	$(CC) $(CFLAGS) -o dvk90.out -Wl,-Map,dvk90.map dvk90.o

dvk90.o:
	$(CC) $(CFLAGS) -Os -c dvk90.c

clean:
	rm -f *.o *.map *.out *.hex
#-------------------
wf: all
	avrdude -c AVRUSB500 -p $(MCU) -P /dev/ttyUSB0 -e -v -U flash:w:dvk90.hex
