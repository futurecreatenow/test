#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include <common.h>
#include <heap.h>
#include <region.h>
#include <index.h>

#include <stack.h>
#include <qsortl.h>

void Print(char *header, int a[], int n) {
   printf("%s", header);
   int y;
   for (y = 0; y < n; ++y) printf("%d ", a[y]);
   printf("\n");
}

void swap(int *x, int *y) {
   int t = *x; *x = *y; *y = t;
}

void Quick_Sort(int a[], acc_index left,  acc_index right) {
   index i, j; int p; int y = 0; 
   acc_region aReg = RegCreate(left, right);
   acc_stack regionStack = StackCreate();
   
   StackPush(regionStack, aReg);

   while (true) {
      if (IdxIs_out_of_Range(left) || IdxIs_out_of_Range(right)) {
	 printf("Out of range indicies may be give.\n"); exit(-1);
      }

      if (IdxIntVal(left) >= IdxIntVal(right)) {
         aReg = StackPop(regionStack);
	 if (StackIs_Empty(regionStack)) {
	    StackFree(regionStack); return;
	 }
      }
      i = *left; j = *right; p = a[(IdxIntVal(left) + IdxIntVal(right)) / 2];
      while (true) {
	 while (a[IdxIntVal(&i)] < p) IdxInc(&i);
	 while (p < a[IdxIntVal(&j)]) IdxDec(&j);

	 if (IdxIs_out_of_Range(&i) || IdxIs_out_of_Range(&j)) break;
	 if (IdxCompare(&i, &j) <= 0) {
	    swap(&a[IdxIntVal(&i)], &a[IdxIntVal(&j)]);
	    IdxInc(&i); IdxDec(&j);
	 }

	 if (IdxIs_out_of_Range(&i) || IdxIs_out_of_Range(&j)) break;
	 if (IdxCompare(&i, &j) > 0) break;
      }
      
      if (!IdxIs_out_of_Range(&j) && (IdxCompare(left, &j) < 0)) {
	 aReg = RegCreate(left, &j);
	 StackPush(regionStack, aReg);
      }
      if (!IdxIs_out_of_Range(&i) && (IdxCompare(&i, right) < 0)) {
	 aReg = RegCreate(&i, right);
	 StackPush(regionStack, aReg);
      }

      aReg = StackPop(regionStack);

      if (StackIs_Empty(regionStack)) {
	RegFree(aReg); StackFree(regionStack);
	return;
      }
      RegRestore(*aReg, &left, &right);
      RegFree(aReg);
   }
}
