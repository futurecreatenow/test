#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

const int array_Size = 1024;
const int stack_Size = 16;

/* class region for sorting resion information (left - right) */

typedef struct region_ { int left, right; }
   region, *acc_region;

acc_region RegCreate(int l, int r) {
   acc_region aReg;
   aReg = (acc_region) malloc(sizeof(region));
   aReg->left = l; aReg->right = r;

   return aReg;
}

void RegFree(acc_region aReg) { free((void *) aReg); }

void RegRestore(acc_region aReg, int *l, int *r) {
   *l  = aReg->left; *r  = aReg->right; 
}

/* end class region for sorting resion information (left - right) */

/* class stack for region memories */

typedef struct stack_ {
   int sp;
   acc_region *regs;
} stack, *acc_stack;

acc_stack StackCreate() {
  acc_stack as = (acc_stack) malloc(sizeof(stack));
  as->sp = 0;
  as->regs = (acc_region*) malloc(sizeof(acc_region) * stack_Size);
  return as;
}

void StackFree(acc_stack as) {
   free((void *) as->regs);
   free((void *) as);
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

void print(char *header, int a[], int n) {
   printf("%s", header);
   int y;
   for (y = 0; y < n; ++y) printf("%d ", a[y]);
   printf("\n");
}

void swap(int *x, int *y) {
   int t = *x; *x = *y; *y = t;
}

void quick_Sort(int a[], int left, int right) {
   int i, j, p; int y = 0; 
   acc_region aReg = RegCreate(left, right);
   acc_stack regionStack = StackCreate();
   
   StackPush(regionStack, aReg);

   while (true) {
      if (left >= right) {
         aReg = StackPop(regionStack);
	 if (StackIs_Empty(regionStack)) {
	    StackFree(regionStack); return;
	 }
      }
      i = left; j = right; p = a[(left + right) / 2];
      while (true) {
	 while (a[i] < p) ++i;
	 while (p < a[j]) --j;
	 if (i <= j) { swap(&a[i], &a[j]); ++i; --j; }
	 if (i > j) break;
      }
      if (left < j) {
	 aReg = RegCreate(left, j);
	 StackPush(regionStack, aReg);
      }
      if (i < right) {
	 aReg = RegCreate(i, right);
	 StackPush(regionStack, aReg);
      }

      aReg = StackPop(regionStack);

      if (StackIs_Empty(regionStack)) {
	RegFree(aReg); StackFree(regionStack);
	return;
      }
      RegRestore(aReg, &left, &right);
      RegFree(aReg);
   }
}

/* driver for quicksort (loop version) */

int main() {
   printf("Enter Data? ");

   // read data
   int d, n = 0, *a;

   a = (int *) malloc(sizeof(int) * array_Size);

   while (scanf("%d", &d) != EOF) a[n++] = d;
   // end read data

   print("Data entered: ", a, n);

   quick_Sort(a, 0, n - 1);

   print("Data sorted: ", a, n);
}
