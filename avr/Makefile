OBJCOPY        = avr-objcopy
OBJDUMP        = avr-objdump

FRONTOBJ	= front.o
BACKOBJ		= back.o backTimer.o backDisplay.o backRPM.o backGear.o backADC.o

MCU_TARGET	= atmega8
OPTIMIZE	= -O2

TEXTFORMAT	= hex

DEFS           =
LIBS           =

CC             = avr-gcc

# Override is only needed by avr-lib build system.

override CFLAGS        = -g -Wall $(OPTIMIZE) -mmcu=$(MCU_TARGET) $(DEFS)
override LDFLAGS       = -Wl,-Map,$(PRG).map

OBJCOPY        = avr-objcopy
OBJDUMP        = avr-objdump

all: compile front back

$(PRG).elf: $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

lst:  $(PRG).lst

front:
	@make PRG=front OBJ="$(FRONTOBJ)" subdir
        
back:
	@make PRG=back OBJ="$(BACKOBJ)" subdir

subdir:
	@cd $(PRG)-files; make OBJ="$(OBJ)" PRG=$(PRG) -f ../Makefile lst doBurn; cd ..

compile:
	@echo "==============================="
	@echo "Disabling burn-on-compile"
	@echo "run 'make burn [...]' to enable"
	@echo "==============================="
	@-rm BURN

burn:
	@echo "==================================="
	@echo "Enabling burn-on-compile"
	@echo "run 'make compile [...]' to disable"
	@echo "==================================="
	@touch BURN

doBurn:	../BURN $(PRG).hex
	@echo "==================================================="
	@echo "Trying to burn $(PRG).hex to device..."
	@echo "run 'make compile [...]' to disable burn-on-compile"
	@echo "==================================================="
	avrdude -p m8 -c pony-stk200 -e -U flash:w:$(PRG).hex

buffer:	
	@echo "========================="
	@echo "3-stating buffer"
	@echo "(requires fix in avrdude)"
	@echo "========================="
	avrdude -p m8 -c buffer -E vcc 2> /dev/null

parport:
	-sudo mknod /dev/parport0 c 99 0
	-sudo chmod a+rw /dev/parport0

# dependency:
%.o: %.c %.h $(PRG)Defines.h

clean: clr
	cd front-files; make -f ../Makefile clr; cd ..
	cd back-files; make -f ../Makefile clr; cd ..
	-rm BURN
clr:
	-rm -rf *.o *.elf
	-rm -rf *.lst *.map $(EXTRA_CLEAN_FILES)

%.lst: %.elf
	$(OBJDUMP) -h -S $< > $@

# Rules for building the .text rom images

text: hex bin srec

hex:  $(PRG).hex
bin:  $(PRG).bin
srec: $(PRG).srec

%.hex: %.elf
	$(OBJCOPY) -j .text -j .data -O ihex $< $@

%.srec: %.elf
	$(OBJCOPY) -j .text -j .data -O srec $< $@

%.bin: %.elf
	$(OBJCOPY) -j .text -j .data -O binary $< $@

# Rules for building the .eeprom rom images

eeprom: ehex ebin esrec

ehex:  $(PRG)_eeprom.hex
ebin:  $(PRG)_eeprom.bin
esrec: $(PRG)_eeprom.srec

%_eeprom.hex: %.elf
	$(OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O ihex $< $@ \
        || { echo empty $@ not generated; exit 0; }

%_eeprom.srec: %.elf
	$(OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O srec $< $@ \
        || { echo empty $@ not generated; exit 0; }

%_eeprom.bin: %.elf
	$(OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O binary $< $@ \
        || { echo empty $@ not generated; exit 0; }

# Every thing below here is used by avr-libc's build system and can be ignored
# by the casual user.

EXTRA_CLEAN_FILES       = *.hex *.bin *.srec

