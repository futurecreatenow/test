#ifndef QUEUE_H
#define QUEUE_H

#include <queue_ds.h>

acc_queue QCreate(void);
bool QEmpty(acc_queue);
int QLength(acc_queue);
void QEnqueue(acc_queue, item_type);
item_type QDequeue(acc_queue);
item_type QHead(acc_queue);
int QLength(acc_queue);
void QPrint(acc_queue, char *);
void QFree(acc_queue);

#endif
