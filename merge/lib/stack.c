#include <heap.h>
#include <stack.h>

/* class stack for region memories */

acc_stack StackCreate() {
  acc_stack as = (acc_stack) HPAlloc(HPCreate(), sizeof(stack));
  as->sp = 0;
  as->regs = (acc_region*) HPAlloc(HPCreate(),
				   sizeof(acc_region) * stack_Size);
  return as;
}

void StackFree(acc_stack as) {
   HPFree(HPCreate(), (void *) as->regs);
   HPFree(HPCreate(), (void *) as);
}

void StackPush(acc_stack s, acc_region i) {
   if (s->sp >= (stack_Size)) {
      printf("Stack overflow.\n"); exit(-1);
   }
   else
      s->regs[s->sp++] = i;
}

acc_region StackPop(acc_stack s) {
   if (s->sp <= 0) {
      printf("Stack empty.\n"); exit(-1);
   }
   else
      return s->regs[--s->sp];
}

bool StackIs_Empty(acc_stack s) { return s->sp == 0; }

/* end class stack for region memories */

