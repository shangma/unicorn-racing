# makefile, written by guido socher
MCU=at90can128
CC=avr-gcc
OBJCOPY=avr-objcopy
PROJECT=hydrogear


INCLUDES = -I"../lib/lib_mcu/can/" -I"../lib/lib_mcu/" -I"../lib/lib_board/"
# optimize for size:
CFLAGS=-g -mmcu=$(MCU) -Wall -Wstrict-prototypes -Os -mcall-prologues $(INCLUDES)

OBJECTS=hydrogear.o can_drv.o can_lib.o
#-------------------test0.hex test1.hex test2.hex
all: clean hydrogear.hex

hydrogear.hex: hydrogear.out
	$(OBJCOPY) -R .eeprom -O ihex hydrogear.out hydrogear.hex 
	avr-size hydrogear.out
	@echo " "
	@echo "Expl.: data=initialized data, bss=uninitialized data, text=code"
	@echo " "

hydrogear.out: $(OBJECTS)
	$(CC) $(CFLAGS) -o hydrogear.out -Wl,-Map,hydrogear.map $(OBJECTS)

hydrogear.o:
	$(CC) $(CFLAGS) -Os -c hydrogear.c

can_drv.o: 
	$(CC) $(CFLAGS) -c can_drv.c

can_lib.o: .
	$(CC)  $(CFLAGS) -c can_lib.c



clean:
	rm -f *.o *.map *.out *.hex
#-------------------
wf: all
	sudo avrdude -c AVRispmkii -p $(MCU) -P usb -e -v -v  -U flash:w:hydrogear.hex

wftest:
	sudo avrdude -c AVRispmkii -p $(MCU) -P usb -e -v -v  -U flash:w:can128_sensor_node0x80_example_gcc.hex

