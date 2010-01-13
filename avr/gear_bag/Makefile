# makefile, written by guido socher
MCU=at90can128
CC=avr-gcc
OBJCOPY=avr-objcopy
PROJECT=hydrorear


INCLUDES = -I"../lib/lib_mcu/can/" -I"../lib/lib_mcu/" -I"../lib/lib_board/"
# optimize for size:
CFLAGS=-g -mmcu=$(MCU) -Wall -Wstrict-prototypes -Os -mcall-prologues $(INCLUDES)
 
OBJECTS=hydrorear.o can_drv.o can_lib.o uart_lib.o uart_drv.o rtc_drv.o timer16_drv.o timer8_drv.o
#-------------------test0.hex test1.hex test2.hex
all: clean hydrorear.hex

hydrorear.hex: hydrorear.out
	$(OBJCOPY) -R .eeprom -O ihex hydrorear.out hydrorear.hex 
	avr-size hydrorear.out
	@echo " "
	@echo "Expl.: data=initialized data, bss=uninitialized data, text=code"
	@echo " "

hydrorear.out: $(OBJECTS)
	$(CC) $(CFLAGS) -o hydrorear.out -Wl,-Map,hydrorear.map $(OBJECTS)

hydrorear.o:
	$(CC) $(CFLAGS) -Os -c hydrorear.c

can_drv.o: 
	$(CC) $(CFLAGS) -c can_drv.c

can_lib.o: .
	$(CC)  $(CFLAGS) -c can_lib.c

uart_lib.o: .
	$(CC)  $(CFLAGS) -c uart_lib.c

uart_drv.o: .
	$(CC)  $(CFLAGS) -c uart_drv.c

rtc_drv.o: .
	$(CC)  $(CFLAGS) -c rtc_drv.c

timer8_drv.o: .
	$(CC)  $(CFLAGS) -c timer8_drv.c

timer16_drv.o: .
	$(CC)  $(CFLAGS) -c timer16_drv.c



clean:
	rm -f *.o *.map *.out *.hex
#-------------------
wf: all
	sudo avrdude -c AVRispmkii -p $(MCU) -P usb -e -v -v  -U flash:w:hydrorear.hex

vlfuse: 
	sudo avrdude -c AVRispmkii -p $(MCU) -P usb -e -v -v  -U lfuse:v:0xFF:m

wlfuse: 
	sudo avrdude -c AVRispmkii -p $(MCU) -P usb -e -v -v  -U lfuse:w:0xFF:m
