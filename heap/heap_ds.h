#ifndef HEAP_DS
#define HEAP_DS

#define HEAP_SIZE 1024

struct heap_ {
    void *heapSpace[HEAP_SIZE];
    int   next;
};

typedef struct heap_ heap;

#define NULL_HEAP (heap *) 0
/* #define NULLV (void *) -1 */ /* NULLV is in mydef.h */

#endif
