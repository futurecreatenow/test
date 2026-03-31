#ifndef QUEUE_DS
#define QUEUE_DS

#include <stdbool.h>

#define item_type int

// const item_type QItem_Init_Val = 0;

// #define Q_SIZE 128

struct queue_ {
  item_type *q;
  int head, tail;
};

typedef struct queue_ queue, *acc_queue;

#endif
