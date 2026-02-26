#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <common.h>
#define RC_TYPE int
#include <index.h>

#include <qsortr.h>

void Print(char *header, int a[], int n) {
   printf("%s", header);
   int y;
   for (y = 0; y < n; ++y) printf("%d ", a[y]);
   printf("\n");
}

static void swap(int *x, int *y) {
   int t = *x; *x = *y; *y = t;
}

void Quick_Sort(int a[], acc_index left, acc_index right) {
   index i, j; int p;

   if (IdxIs_out_of_Range(left) || IdxIs_out_of_Range(right)) {
      printf("Out of range indicies may be give.\n"); exit(-1);
   }
   if (IdxIntVal(left) >= IdxIntVal(right)) return;
   
   i = *left; j = *right;
   p = a[(IdxIntVal(left) + IdxIntVal(right))/2];

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

   if (!IdxIs_out_of_Range(&j) && (IdxCompare(left, &j) < 0))
      Quick_Sort(a, left, &j);
   if (!IdxIs_out_of_Range(&i) && (IdxCompare(&i, right) < 0)) 
      Quick_Sort(a, &i, right);
}
