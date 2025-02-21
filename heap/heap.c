#include <stdio.h>
#include <stdlib.h>

//#include <mydef.h>
//
//#include <heap_ds.h>
#include "../mydef/mydef.h"
#include "heap_ds.h"

static heap *heap_Space;

/*	Initialization for Heap Controls				*/

void HPInit() { heap_Space = NULL_HEAP; }

/*	create a singleton instance of heap				*/

heap *HPCreate() {
   if (heap_Space == NULL_HEAP) {
        int y;

        heap_Space = (heap *) malloc(sizeof(heap));
	heap_Space->next = 0;
	for (y = 0; y < HEAP_SIZE; ++y) heap_Space->heapSpace[y] = NULLV;
   }
   return heap_Space;
}

/*	function to get heap space					*/

void *HPAlloc(heap* thisHeap, int size) {
   if (heap_Space->next >= HEAP_SIZE) {
       fprintf(stderr, "Heap area is overflow.");
       exit(-1);
   }
   else {
	thisHeap->heapSpace[thisHeap->next] = malloc(size);
	return thisHeap->heapSpace[thisHeap->next];
   }
}

/*	Clean all Heap area						*/

void HPFree_All(heap *thisHeap) {
    int y;

    for (y = 0; y < thisHeap->next; ++y) {
       if (thisHeap->heapSpace[y] != NULLV) {
	  free(thisHeap->heapSpace[y]);
	  thisHeap->heapSpace[y] = NULLV;
      }
    }
    thisHeap->next = 0;
}

/*	FreeSpace							*/

void HPFree(heap *thisHeap, void *allocatedArea) {
   int y;

   for (y = 0; y < thisHeap->next; ++y) {
      if (thisHeap->heapSpace[y] == allocatedArea) {
         free(thisHeap->heapSpace[y]);
	 thisHeap->heapSpace[y] = NULLV;
	 return;
      }
   }
}
