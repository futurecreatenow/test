#ifndef REGION_DS_H
#define REGION_DS_H

#include <index_ds.h>

extern const int stack_Size;

/* class region for sorting resion information (left - right) */

// typedef struct region_ { int from, to; } region, *acc_region;
typedef struct region_ {acc_index from, to; } region, *acc_region;

#endif
