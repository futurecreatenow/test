#include <stdlib.h>
#include <stdio.h>

#include <common.h>
#include <heap.h>

#include <queue.h>

#include <merge.h>

/* driver for merge sort */

int main() {
   printf("Enter Data? ");

   // read data
   int d, n = 0, *t, *a;

   // a = (int *) malloc(sizeof(int) * array_Size);
   acc_queue aq = QCreate();
   
   while (scanf("%d", &d) != EOF) {
      if (++n >= queue_Size) {
	 fprintf(stderr, "No space for sorting bunnfer."); exit(-1);
      }
      QEnqueue(aq, d);
   }

   QPrint(aq, "Data entered: ");
   aq = Merge_Sort(aq);
   QPrint(aq, "Data sorted: ");

   HPFree_All(HPCreate());
}
