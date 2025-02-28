#ifndef LIST_H
#define LIST_H

#include <mydef.h>
#include <list_ds.h>

#ifdef CTAB_LIST
#include <ctab_entry.h>
#endif

#ifdef WTAB_LIST
#include <wtab_entry.h>
#endif

extern list ListCreate(void);
extern void ListFree(list);
extern boolean ListIs_Null(list);
extern acc_node ListHead(list);
extern acc_node ListNext(list);
extern acc_node ListTail(list);
extern acc_node ListIth(list, int);
extern list ListAppend(list, item_type);
extern list ListPrepend(list, item_type);
extern list ListRm_Head(list);
extern list ListRm_Tail(list);
extern int ListLength(list);
extern void ListSwap(list, int, int);
#ifdef CTAB_LIST
extern void ListSort(list,
		    equality (*)(acc_ctab_entry, acc_ctab_entry, sort_key), 
		    sort_key);
#elif  WTAB_LIST
extern void ListSort(list,
		    equality (*)(acc_wtab_entry, acc_wtab_entry, sort_key), 
		    sort_key);
#else
extern void ListSort(list);
#endif

#ifdef TEST
extern void ListPrint(list);
#endif

#endif
