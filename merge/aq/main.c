#include <stdio.h>

#include <queue.h>

const item_type QItem_Init_Val = 0;
const int Queue_Size = 128;

int main()
{
  item_type d;
  acc_queue aq = QCreate();

  while (scanf("%d", &d) != EOF) {
     printf("enqueue %d\n", d);
     QEnqueue(aq, d);
  }

  while (!QEmpty(aq)) { printf("dequeue %d\n", d = QDequeue(aq)); }
}
