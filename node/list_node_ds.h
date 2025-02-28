#ifndef LIST_NODE_DS_H
#define LIST_NODE_DS_H

#include <mydef.h>

#ifdef MY_ITEM_TYPE
/* #include <ctab_entry_ds.h> */
#include <wtab_entry_ds.h>
typedef acc_wtab_entry item_type;
#else
typedef int item_type;
#endif

typedef struct node_ *acc_node;
struct node_ { 
   item_type d; 
   acc_node next;
#  ifdef TWO_WAY
   acc_node prev;
#  endif
};
typedef struct node_ node;

#define CENTINEL (acc_node) 0

#endif
