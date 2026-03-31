#include <stdio.h>
#include <stdlib.h>

// #include <mydef.h>
#include <heap.h>

#include <queue.h>

extern const int queue_Size;
extern const int qItem_Init_Val;

acc_queue QCreate() {
  acc_queue aq = (acc_queue) HPAlloc(HPCreate(), sizeof(queue));

  aq->q = (item_type *) HPAlloc(HPCreate(), sizeof(item_type) * queue_Size);

  int y;

  for (y = 0; y < queue_Size; ++y) aq->q[y] = qItem_Init_Val;
  aq->head = aq->tail = 0;

  return aq;
}

bool QEmpty(acc_queue aq) { return (aq->head == aq->tail) ? true : false; }


bool is_Full(acc_queue aq)
{
  if (aq->head == 0) return (aq->tail == (queue_Size - 1)) ? true : false;
  else return ((aq->tail - 1) == aq->head) ? true : false;
}

void QEnqueue(acc_queue aq, item_type d)
{
  if (is_Full(aq)) {
     fprintf(stderr, "Queue is full.\n"); exit(-1);
  }
  else {
     aq->q[aq->tail++] = d; aq->tail %= queue_Size;
  }
}

item_type QDequeue(acc_queue aq)
{
  item_type r;

  if (QEmpty(aq)) {
    fprintf(stderr, "Queue is empty.\n"); exit(-1);
  }
  else {
    r = aq->q[aq->head++]; aq->head %= queue_Size;
  }

  return r;
}

item_type QHead(acc_queue aq) {
   return aq->q[aq->head];
}

int QLength(acc_queue aq) {
   if (aq->head == aq->tail) return 0;
   else if (aq->head < aq->tail) return aq->tail - aq->head;
   else if (aq->head > aq->tail) return (queue_Size - aq->head + aq->tail - 1);
}

void QPrint(acc_queue aq, char *header) {
   int l = QLength(aq), y;

   printf("%s", header);
   for (y = 0; y < l; ++y) {
      int yy;
      printf("%d ", yy = QDequeue(aq));
      QEnqueue(aq, yy);
   }
   printf("\n");
}

void QFree(acc_queue aq) {
   HPFree(HPCreate(), (void *)aq->q); HPFree(HPCreate(), (void *) aq);
}


