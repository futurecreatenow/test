#
#	Makefile for building character frequency counting  program
#	

CFILES	= 	heap.c

OFILES	= 	heap.o

HFILES	=	heap.h	heap_ds.h	mydef.h

#
#	debug flags
#

DFLAGS	= -g

#
#	include paths
#

GINC	= /Users/yoshie/include/
INCS	= -I. -I$(GINC)

#
#	defines
#

DEFS	=

#
#	compile flags
#

CFLAGS	=	$(INCS)	$(DEFS)

#
#	C compiler
#

CC	= cc

RM	= rm -f

all 	:	cf

cf	:	${OFILES}

.c.o	:
		${CC} ${CFLAGS} ${DFLAGS} -c $*.c

tar	:
		touch *.c *.h
clean	:
		${RM} lst ${OFILES}  \#*\# *\~

