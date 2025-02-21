#ifndef HEAP_H
#define HEAP_H

//#include <heap_ds.h>
#include "heap_ds.h"

extern void HPInit(void);
extern heap *HPCreate(void); /* singleton */
extern void HPFree(heap *, void *);
extern void *HPAlloc(heap*, int);
extern void HPFree_All(heap *);

#endif
