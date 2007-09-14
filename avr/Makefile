OBJCOPY        = avr-objcopy
OBJDUMP        = avr-objdump

FRONTOBJ	= front.o frontTimer.o
BACKOBJ		= back.o backRPM.o backTimer.o backSPEED.o backADC.o

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

all: front back

$(PRG).elf: $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

lst:  $(PRG).lst

front:
	make PRG=front OBJ="$(FRONTOBJ)" subdir
        
back:
	make PRG=back OBJ="$(BACKOBJ)" subdir

subdir:
	cd $(PRG)-files; make OBJ="$(OBJ)" PRG=$(PRG) -f ../Makefile lst; cd ..

burn:	tmp.hex
	echo burn $(HEST)
	-rm tmp.hex

# dependency:
%.o: %.c %.h

clean: clr
	cd front-files; make -f ../Makefile clr; cd ..
	cd back-files; make -f ../Makefile clr; cd ..
clr:
	-rm -rf *.o *.elf *.eps *.png *.pdf *.bak 
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

