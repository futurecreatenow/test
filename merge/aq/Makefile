#
#	Makefile for building heap sort program
#

CFILES	= 	main.c	queue.c

OFILES	= 	main.o	queue.o

HFILES	=	queue_ds.h	queue.h

#
#	debug flags
#

DFLAGS	=

#
#	include paths
#

LIBDIR	= /Users/yoshie/lib/C/heap

INCS	= -I. -I/Users/yoshie/include -I$(LIBDIR)



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

all 	:	q

q	:	${OFILES}
		${CC} ${DFLAGS} -o q ${OFILES} ${LIBDIR}/heap.o

.c.o	:
		${CC} ${CFLAGS} ${DFLAGS} -c $*.c

tar	:
		touch *.c *.h
clean	:
		${RM} q ${OFILES}  \#*\# *\~

