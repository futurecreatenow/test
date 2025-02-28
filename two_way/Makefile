#
#	Makefile for building heap sort program
#

# CFILES	= 	main.c	list.c
CFILES	= 	list.c

# OFILES	= 	list.o	main.o
OFILES	= 	list.o

HFILES	=	list_ds.h	list.h

#
#	debug flags
#

DFLAGS	= -g

#
#	include paths
#
GINC	= /Users/yoshie/include
LINC	=
LIBDIR	= /Users/yoshie/lib/C
APPDIR	= /Users/yoshie/research/SRA2024/C

LLIBDIR	= ../node
HLIBDIR = $(LIBDIR)/heap
WATDIR	= $(APPDIR)/word_freq/adt/list/types
WASDIR	= $(APPDIR)/word_freq/adt/list/spec
INCS	= -I. -I$(GINC) -I$(LLIBDIR) -I$(HLIBDIR)  -I$(WATDIR) -I$(WASDIR)
# INCS	= -I. -I$(GINC) -I$(LLIBDIR) -I$(HLIBDIR)

#
#	defines
#

# DEFS	= -D TEST
# DEFS	= -D CTAB_LIST -D MY_ITEM_TYPE
# DEFS	= -D CTAB_LIST -D MY_ITEM_TYPE -D TWO_WAY
DEFS	= -D WTAB_LIST -D MY_ITEM_TYPE -D TWO_WAY

#
#	compile flags
#

CFLAGS	= $(INCS) $(DEFS)

#
#	C compiler
#

CC	= cc

RM	= rm -f

# all 	:	lst
all	:	${OFILES}
# all	:	wlist

# lst	:	${OFILES}
#		${CC} ${DFLAGS} -o lst ${OFILES} ${LLIBDIR}/list_node.o ${HLIBDIR}/heap.o

.c.o	:
		${CC} ${CFLAGS} ${DFLAGS} -c $*.c

tar	:
		touch *.c *.h
clean	:
		${RM} lst *.o  \#*\# *\~

