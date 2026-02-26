#
#	Makefile for building PO qucksort program object file
#

#
#	root directory
#

ROOT	= /Users/yoshie
# ROOT	= ~/research/SRA2024/C

#
#	library directory
#

# LIB	= $(ROOT)/lib
LIB	= $(ROOT)/lib/C/heap

LOCALLIB =	$(ROOT)/C/sort/lib

LIBFILES =	$(LOCALLIB)/common.o	$(LIB)/heap.o \
		$(LOCALLIB)/region.o	$(LOCALLIB)/index.o \
#		$(LIB)/heap/heap.o	$(LIB)/com_args/com_args.o \
#		$(LIB)/stm/stm.o	$(LIB)/stm/stm_state.o \
#		$(LIB)/stm/word_stm.o	$(LIB)/stm/digits_stm.o \
#		$(LIB)/stm/token.o \
#		$(LIB)/input_device/input_device.o \
#		$(LIB)/input_device/string_input_device.o

#
#	Denug flag
#
DFLAGS	= -g

#	for local modifications
#
# DEFS	= -DDEBUG $(VHDL93)
DEFS	=

#
#	Include pathes and special definitions (always needed)
#
#		Caution: Do not remove -DARCHSYN in any time
#

INCS	=	-I$(LIB)	-I$(LOCALLIB)	-I. 

CFLAGS 	= 	$(INCS)

#
#	For gcc use
#
# GCC	= gcc -DGNU -DANSI -S
GCC	= gcc -DGNU -DANSI

#
#	C compiler
#
CC	= cc 
# CC	= ${GCC}

CFILES	= 	main.c	stack.c	qsortl.c

OFILES	= 	main.o	stack.o	qsortl.o	

# HFILES	=	common.h	index.h

all 	: 	${OFILES}  qsortl

.c.o	:
		${CC} ${CFLAGS} ${DEFS} ${DFLAGS} -c $*.c

qsortl	:	${OFILES}
		${CC} ${DEFS} ${DFLAGS} -o qsortl ${OFILES} ${LIBFILES}

clean	:
		${RM} *.o; ${RM}  \#*\#; ${RM} *\~; ${RM} qsortl

tar	:
		touch *.c
