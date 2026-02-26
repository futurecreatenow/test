ROOT	= /Users/yoshie

OFILES	=	common.o	range.o		index.o	region.o

# LIB	=	$(ROOT)/lib
LIB	=	$(ROOT)/lib/C/heap

INCS	= 	-I$(LIB)	-I.

# DEF	=	-DRC_TYPE=int
# DEF	=	-DRC_TYPE=acc_index

CFLAGS	=	$(INCS)

all	:	${OFILES}
.c.o	:
		cc ${INCS} ${DEF} -c $*.c

clean	:
		rm -f *.o a.out *~
