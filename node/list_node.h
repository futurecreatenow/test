#ifndef LIST_NODE_H
#define LIST_NODE_H

#include <mydef.h>
#include <list_node_ds.h>

extern acc_node LNCreate(item_type);
extern boolean LNIs_Null(acc_node);
extern item_type LNData_Ref(acc_node);
/* extern acc_ctab_entry LNData_Ref(acc_node); */
extern acc_node LNNext(acc_node);
#ifdef TWO_WAY
extern acc_node LNPrev(acc_node);
#endif
extern void LNAppend(acc_node, acc_node);
extern void LNBreak_Link(acc_node);
#ifdef TWO_WAY
extern void LNBreak_PLink(acc_node);
#endif
extern void LNDispose(acc_node);
extern void LNSwap(acc_node, acc_node);

#endif
