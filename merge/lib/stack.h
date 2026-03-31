#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include <common.h>
#include <heap.h>
#include <region.h>
#include <index.h>

#include <stack_ds.h>

acc_stack StackCreate(void);
void StackFree(acc_stack);
void StackPush(acc_stack, acc_region);
acc_region StackPop(acc_stack);
bool StackIs_Empty(acc_stack);
