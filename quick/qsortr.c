#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

const int array_Size = 1024;

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
   int i, j, p;

   if (left >= right) return;
   
   i = left; j = right; p = a[(left + right)/2];
   while (true) {
      while (a[i] < p) ++i;
      while (p < a[j]) --j;
      if (i <= j) { swap(&a[i], &a[j]); ++i; --j; }
      if (i > j) break;
   }

   if (left < j) quick_Sort(a, left, j);
   if (i < right) quick_Sort(a, i, right);
}

/* driver for quick sort (recursive version) */

int main() {
   printf("Enter Data? ");

   // read data
   int d, n = 0, *a;

   a = (int *) malloc(sizeof(int) * array_Size);

   while (scanf("%d", &d) != EOF) a[n++] = d;
   // end read data

   print("Data entered: ", a, n);

   quick_Sort(a, 0, n - 1);

   print("Data sorted: ", a ,n);
}
