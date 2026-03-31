#ifndef STACK_DS_H
#define STACK_DS_H

extern const int stack_Size;

/* class stack for region memories */

typedef struct stack_ {
   int sp;
   acc_region *regs;
} stack, *acc_stack;

#endif
