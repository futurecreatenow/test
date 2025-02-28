#include <stdio.h>
#include <stdlib.h>

#include <heap.h>

#include <mydef.h>

#include <list_node.h>

acc_node LNCreate(item_type d)
{
   acc_node an;

   an = (acc_node) HPAlloc(HPCreate(), sizeof(node));
   an->d = d;
   an->next = CENTINEL;

#  ifdef TWO_WAY
   an->prev = CENTINEL;
#  endif

   return an;
}

static boolean is_Centinel(acc_node an) { return (an == CENTINEL) ? YES : NO; }

boolean LNIs_Null(acc_node an) { return is_Centinel(an); }

item_type LNData_Ref(acc_node an) { return an->d; }

acc_node LNNext(acc_node an)
{
  if (is_Centinel(an)) return an;
  else return an->next;
}

acc_node LNPrev(acc_node an)
{
  if (is_Centinel(an)) return an;
  else return an->prev;
}

void LNAppend(acc_node e, acc_node a) { e->next = a; }

void LNBreak_Link(acc_node a) { a->next = CENTINEL; }

void LNBreak_PLink(acc_node a) { a->prev = CENTINEL; }

void LNDispose(acc_node a) { HPFree(HPCreate(), (void *) a); }

void LNSwap(acc_node i, acc_node j) {
   item_type t;

   t = i->d; i->d = j->d; j->d = t;
}
