#
#	Makefile for building parser object file
#

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
GENINCS	=

INCS	= $(GENINCS) -I.

CFLAGS 	= $(INCS) -c

HFILES 	= 

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

OFILES	=	qsort_buffer.o	ordered_pair.o 		common.o \
		stack.o		region.o		main.o

all 	: 	${OFILES}  hpsort

.c.o	:
		${CC} ${CFLAGS} ${DEFS} ${DFLAGS} -c $*.c

hpsort	:	${OFILES}
		${CC} ${DEFS} ${DFLAGS} -o qsort ${OFILES}

clean	:
		${RM} *.o; ${RM}  \#*\#; ${RM} *\~; ${RM} qsort

tar	:
		touch *.c
