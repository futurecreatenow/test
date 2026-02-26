#include <stdlib.h>
#include <stdio.h>

#include <common.h>
#include <heap.h>
#include <index.h>

#include <qsortr.h>

/* driver for quick sort (recursive version) */

int main() {
   printf("Enter Data? ");

   // read data
   int d, n = 0, *a;

   // a = (int *) malloc(sizeof(int) * array_Size);
   a = (int *) HPAlloc(HPCreate(), sizeof(int) * array_Size);
   
   while (scanf("%d", &d) != EOF) a[n++] = d;
   // end read data

   Print("Data entered: ", a, n);

   acc_index l = IdxCreate(0, n - 1, 0), r = IdxCreate(0, n - 1, n - 1);
   Quick_Sort(a, l, r);
   IdxFree(l); IdxFree(r);
   
   Print("Data sorted: ", a ,n);

   HPFree_All(HPCreate());
}
