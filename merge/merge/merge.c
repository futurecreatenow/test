#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <common.h>

#include <queue.h>

#include <merge.h>

acc_queue merge(acc_queue l, acc_queue r) {
   acc_queue m = QCreate();
   while (!QEmpty(l) && ! QEmpty(r)) {
     if (QHead(l) < QHead(r)) QEnqueue(m, QDequeue(l));
     else QEnqueue(m, QDequeue(r));
   }
   while (!QEmpty(l)) QEnqueue(m, QDequeue(l));
   while (!QEmpty(r)) QEnqueue(m, QDequeue(r));

   return m;
}

void split(acc_queue s, acc_queue *l, acc_queue*r) {
   int len = QLength(s) / 2, y;
   *l = QCreate(); *r = QCreate();
   
   for (y = 0; y < len; ++y) QEnqueue(*l, QDequeue(s));
   while (!QEmpty(s)) QEnqueue(*r, QDequeue(s));
}

acc_queue Merge_Sort(acc_queue s) {
   acc_queue l, r;
   
   if (QLength(s) <= 1) return s;
   else {
      split(s, &l, &r);
      l = Merge_Sort(l);
      r = Merge_Sort(r);
   }
   return merge(l, r);
}
