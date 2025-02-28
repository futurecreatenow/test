#
#	Makefile for building character frequency counting  program
#	

#
#	root directory
#

ROOT	= /Users/yoshie
# ROOT	= ~/research/SRA2024/C

#
#	library directory
#

LIB	= $(ROOT)/lib/C

CFILES	= 	main.c	word_table.c	wtab_entry.c	out.c

OFILES	= 	main.o	word_table.o	wtab_entry.o	out.o

HFILES	=	wtab_entry.h	wtab_entry_ds.h	\
		word_table.h	word_table_ds.h	\
		heap.h	heap_ds.h	out.h	\
		general.h

LIBFILES =	$(LIB)/heap/heap.o	$(LIB)/com_args/com_args.o \
		$(LIB)/stm/stm.o	$(LIB)/stm/stm_state.o \
		$(LIB)/stm/word_stm.o	$(LIB)/stm/digits_stm.o \
		$(LIB)/stm/token.o \
		$(LIB)/input_device/input_device.o \
		$(LIB)/input_device/string_input_device.o \
		$(LIB)/list/two-way/list.o \
		$(LIB)/list/node/list_node.o

#
#	debug flags
#

DFLAGS	= -g

#
#	include paths
#

INCS	= -I. -I$(ROOT)/include -I$(LIB)/heap -I$(LIB)/com_args -I$(LIB)/stm  -I$(LIB)/input_device -I$(LIB)/list/node -I$(LIB)/list/two-way -I../../include -I../spec -I../types -I../include

#
#	defines
#

DEFS	= -D MY_ITEM_TYPE -D WTAB_LIST -D TWO_WAY

#
#	compile flags
#

CFLAGS	=	$(INCS)	$(DEFS)

#
#	C compiler
#

CC	= cc

RM	= rm -f

all 	:	wf

wf	:	${OFILES}
		${CC} ${DFLAGS} -o wf ${OFILES} ${LIBFILES}

.c.o	:
		${CC} ${CFLAGS} ${DFLAGS} -c $*.c

tar	:
		touch *.c *.h
clean	:
		${RM} lst ${OFILES}  \#*\# *\~

