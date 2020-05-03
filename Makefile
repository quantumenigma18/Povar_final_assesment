#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# make file for two build platforms
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#       <FILE>.o - Builds the object file
#       <FILE>.i - Builds the preprocessed file
#       <FILE>.asm - Builds the assembly file
#       <FILE>.d - Builds the dependency file
#       compile-all - Compiles all source files in project
#       build - Builds all object files in project (links as well)
#       clean - Removes all generated files
#
#
# Platform Overrides:
#       HOST - Default platform
#       MSP342 - Target cross-compiled platform
#
#	Author: Povar Tetiana
#	Data:02.05.2020
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = MSP432
VERBOSE = DISABLE
COURSE = COURSE

#General Flags
GFLAGS = -Wall -Werror -g -O0 -std=c99
 
TARGET = c1m2

ifeq ($(PLATFORM),HOST)
	# Compiler Flags and Defines for HOST
	CC =gcc
	LD = ld
	LDFLAGS =  -Wl,-Map=$(TARGET).map
	CFLAGS = $(GFLAGS)
	CPPFLAGS = -DHOST
else
	# Architectures Specific Flags
	LINKER_FILE = msp432p401r.lds
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
	FLOAT =hard
	FPU = fpv4-sp-d16

	# Compiler Flags and Defines
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	CFLAGS = $(GFLAGS) -mcpu=$(CPU) -mthumb --specs=$(SPECS) -march=$(ARCH) -mfloat-abi=$(FLOAT) -mfpu=$(FPU)
	CPPFLAGS = -DMSP432

	#Size Utility
	SIZE = arm-none-eabi-size 
endif
ifeq ($(VERBOSE),ENABLE)
CPPFLAGS += -DVERBOSE
endif

ifeq ($(COURSE),COURSE1)
CPPFLAGS += -DCOURSE1
endif

PRES = $(SOURCES:.c=.i)
ASMS = $(SOURCES:.c=.asm)
OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)

%.i : %.c
	$(CC) $(INCLUDES) -E $< $(CPPFLAGS) $(CFLAGS) -o $@

%.asm : %.c
	$(CC) $(INCLUDES) -S $<  $(CFLAGS) $(CPPFLAGS)  -o $@

%.o : %.c
	$(CC) $(INCLUDES) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

%.d : %.c
	$(CC) $(INCLUDES) -M $< $(CFLAGS) $(CPPFLAGS) -o $@

.PHONY: compile-all
compile-all: $(OBJS)
		

.PHONY: build
build: $(TARGET).out

$(TARGET).out: $(OBJS) $(DEPS)  
	$(CC) $(OBJS) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -o $@ 
	$(SIZE) $(TARGET).out

clean:
	rm -f $(PRES) $(ASMS) $(OBJS) $(DEPS) $(TARGET).out $(TARGET).map 
