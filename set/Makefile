#
#	Makefile for building state transition program
#	

#
#	root directory
#

ROOT	= /Users/yoshie
# ROOT	= ~/research/SRA2024/C

#
#	library directory
#

LIB	= 	$(ROOT)/lib/C

CFILES	= 	set.c	test.c

OFILES	= 	set.o	test.o

HFILES	=	set.h	set_ds.h	mydef.h

LIBFILES =	$(LIB)/heap/heap.o

#
#	debug flags
#

DFLAGS	= -g

#
#	include paths
#

INCS	= -I. -I$(ROOT)/include -I$(LIB)/heap -I$(LIB)/com_args -I../../include -I../spec -I../types -I../include

#
#	defines
#

# DEFS	= -DIGNORED

#
#	compile flags
#

CFLAGS	=	$(INCS)	$(DEFS)

#
#	C compiler
#

CC	= cc

RM	= rm -f

# all	:	${OFILES}
all 	:	test

test	:	${OFILES}
		${CC} ${DFLAGS} -o test ${OFILES} ${LIBFILES}

.c.o	:
		${CC} ${CFLAGS} ${DFLAGS} -c $*.c

tar	:
		touch *.c *.h
clean	:
		${RM} lst ${OFILES} gt  \#*\# *\~

