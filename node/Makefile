#
#	Makefile for building heap sort program
#

CFILES	= 	list_node.c

OFILES	= 	list_node.o

HFILES	=	list_node_ds.h	list_node.h

#
#	debug flags
#

DFLAGS	= -g

#
#	include paths
#

GINC	= /Users/yoshie/include
HINC	= /Users/yoshie/lib/C/heap
APPDIR	= /Users/yoshie/research/SRA2024/C/word_freq
ATDIR	= $(APPDIR)/adt/list/types
ASDIR	= $(APPDIR)/adt/list/spec
INCS	= -I. -I$(GINC) -I$(HINC) -I$(ATDIR) -I$(ASDIR)
# INCS	= -I. -I$(GINC) -I$(HINC) 

#
#	defines
#

# DEFS	= -D CTAB_LIST -D MY_ITEM_TYPE -D TWO_WAY
DEFS	= -D WTAB_LIST -D MY_ITEM_TYPE -D TWO_WAY
# DEFS	= -D CTAB_LIST -D MY_ITEM_TYPE
# DEFS	=

#
#	compile flags
#

CFLAGS	=	$(INCS)	$(DEFS)

#
#	C compiler
#

CC	= cc

RM	= rm -f

# all 	:	${OFILES}
all	:	wlist_node

wlist_node 	:	list_node.o

# .c.o	:
#		${CC} ${CFLAGS} ${DFLAGS} -c $*.c

list_node.o	:	list_node.c
		${CC} ${CFLAGS} ${DFLAGS} -c list_node.c

tar	:
		touch *.c *.h
clean	:
		${RM} lst ${OFILES}  \#*\# *\~

