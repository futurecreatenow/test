#include <stdio.h>
#include <stdlib.h>

#include <mydef.h>

#include <heap.h>

#include <list.h>
#include <list_node.h>

/* static list this_List = NULL_LIST; */

/* function to create a oneway list */

list ListCreate() {
   list l;

   l = (list) HPAlloc(HPCreate(), sizeof(list_body));
   l->head = l->tail = CENTINEL;
   
   return l;
}

/* function to dispose a list whose head is an */

static void free_List(acc_node an) {
   if (LNIs_Null(an) == YES) return;
   else {
      free_List(LNNext(an)); LNDispose(an);
   }
}

/* procedure to dispose a given list */

void ListFree(list l) {
   if (l == NULL_LIST) {
      fprintf(stderr, "List is never allocated, detected in ListFree.\n");
      exit(ERROR);
   }
   else free_List(l->head);
   HPFree(HPCreate(), (void *) l);
}

/* function to check if the given list is null */

boolean ListIs_Null(list l) {
   if (l == NULL_LIST){
      fprintf(stderr, "List is never allocated., detected in ListIs_Null.\n");
      exit(ERROR);
   }
   else if ((LNIs_Null(l->head) == YES) && (LNIs_Null(l->tail) == YES))
      return YES;
   else
      return NO;
}

/* function to reference the head of the given list */

acc_node ListHead(list l) {
   if (l == NULL_LIST) {
      fprintf(stderr, "List is never allocated, detected in ListHead.\n");
      exit(ERROR);
   }
   else return l->head;
}

/* function to get the next node of the given list's head
   this method (function) may be obsolete */

acc_node ListNext(list l) {
   if (l == NULL_LIST) {
      fprintf(stderr, "List is never allocated, detected in ListNext.\n");
      exit(ERROR);
   }
   else return LNNext(l->head);
}

/* function to get the tail of the list */

acc_node ListTail(list l) {
   if (ListIs_Null(l) == YES) {
      fprintf(stderr, "List is never allocated, detected in ListTail.\n");
      exit(ERROR);
   }
   else return l->tail;
}

/* function to get the i'th node of the list. */

acc_node ListIth(list l, int i) {
   if (ListIs_Null(l) == YES) {
      fprintf(stderr, "List is never allocated, detected in ListIth.\n");
      exit(ERROR);
   }
   else if (i == 0) return l->head;
   else {
      acc_node h = l->head, r;
      l->head = ListNext(l);
      r = ListIth(l, i - 1);
      l->head = h;

      return r;
   }
}

/* function to put the node after the tail of the list */

list ListAppend(list l, item_type d) {
   acc_node t = LNCreate(d);

   if (l == NULL_LIST) {
      fprintf(stderr, "List is never allocated, detected in ListAppend.\n");
      exit(ERROR);
   }
   /*
   {
      l = ListCreate(); l->head = l->tail = t;
   }
   */
   else if (LNIs_Null(l->head) == YES)
      l->head = l->tail = t;
   else {
      LNAppend(l->tail, t);
      l->tail = t;
   }

   return l;
}

/* function to put a node befoe the head of the list */
list ListPrepend(list l, item_type d) {
   acc_node t = LNCreate(d);

   if (l == NULL_LIST) {
      fprintf(stderr, "List is never allocated, detected in ListPrepend.\n");
      exit(ERROR);
   }
   /*
   {
      l = ListCreate(); l->head = l->tail = t;
   }
   */
   else if (LNIs_Null(l->head) == YES)
      l->head = l->tail = t;
   else {
      LNAppend(t, l->head);
      l->head = t;
   }

   return l;
}

/* function to remode the head of the given list */

list ListRm_Head(list l) {
   if (l == NULL_LIST) {
      fprintf(stderr, "List is never allocated, detected in ListRm_Head.\n");
      exit(ERROR);
   }
   else {
      acc_node h = l->head ;
      l->head = LNNext(h);
      if (LNIs_Null(l->head) == YES) l->tail = CENTINEL;
      LNDispose(h);
   }
   return l;
}

/* function to remove the tail of the given list */

list ListRm_Tail(list l) {
   if (l == NULL_LIST) {
      fprintf(stderr, "List is never allocated, detected in ListRm_Tail.\n");
      exit(ERROR);
   }
   else {
      acc_node t = l->tail;
      l->tail = LNPrev(t);
      if (LNIs_Null(l->tail) == YES) l->head = CENTINEL;
      LNDispose(t);
   }
   return l;
}

/* function to get the length of the list */

int ListLength(list l) {
   if (l == NULL_LIST) {
      fprintf(stderr, "List is never allocated, detected in ListLength.\n");
      exit(ERROR);
   }
   else if (ListIs_Null(l))
      return 0;
   else if (l->head == l->tail)
      return 1;
   else {
      acc_node h = l->head;
      int ll;
      l->head = LNNext(l->head);
      ll = 1 + ListLength(l);
      l->head = h;
      return ll;
   }
}

/* procedure to swap node content */

void ListSwap(list l, int i, int j) {
   acc_node ith = ListIth(l, i), jth = ListIth(l, j);

   if ((LNIs_Null(ith) == NO) && (LNIs_Null(jth) == NO)) LNSwap(ith, jth);
}

/* procedure to sort the list */

#ifdef CTAB_LIST

// for char table
void ListSort(list l,
	     equality (*comp)(acc_ctab_entry, acc_ctab_entry, sort_key),
	     sort_key key)

#elif WTAB_LIST
// for word table
void ListSort(list l,
	      equality (*comp)(acc_wtab_entry, acc_wtab_entry, sort_key),
	      sort_key key)

#else
void ListSort(list l)
#endif
{
   int i, j, n = ListLength(l);

   switch(n) {
   case 0: return;
   case 1: return;
   default:
      for (i = 0; i < n -1; ++i) {
	 int minpos = i;
	 for (j = i + 1; j < n; ++j) {
#           ifdef CTAB_LIST
	    if ((*comp)(LNData_Ref(ListIth(l, minpos)),
			LNData_Ref(ListIth(l, j)), key) == GREATER_THAN)
#           elif WTAB_LIST
	    if ((*comp)(LNData_Ref(ListIth(l, minpos)),
			LNData_Ref(ListIth(l, j)), key) == GREATER_THAN)
#           else
	    if (LNData_Ref(ListIth(l, minpos)) > LNData_Ref(ListIth(l, j)))
#           endif
	       minpos = j;
	 }
	 if (minpos != i) ListSwap(l, minpos, i);
      }
    }
}

#ifdef TEST

/* procedure to print out the list */

void ListPrint(list l) {
   acc_node n;

   if (ListIs_Null(l) == YES) {
      printf("Null list.");
   }
   else
      for (n = l->head; LNIs_Null(n) == NO; n = LNNext(n)) 
         printf("%d ", LNData_Ref(n));
}

#endif
