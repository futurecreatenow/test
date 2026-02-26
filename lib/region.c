#include <stdlib.h>
#include <heap.h>
#include <region.h>
#include <index.h>

/* class region for sorting resion information (left - right) */
acc_region RegCreate(acc_index l, acc_index r) {
   acc_region aReg;
   aReg = (acc_region) HPAlloc(HPCreate(), sizeof(region));
   aReg->from = l; aReg->to = r;

   return aReg;
}

void RegFree(acc_region aReg) { HPFree(HPCreate(), (void *) aReg); }

void RegRestore(region aReg, acc_index *l, acc_index *r) {
   *l  = aReg.from; *r  = aReg.to; 
}

acc_index RegFrom(acc_region aReg) { return aReg->from; }

acc_index RegTo(acc_region aReg) { return aReg->to; }

void RegSet_From(acc_region aReg, acc_index f) { aReg->from = f; }

void RegSet_To(acc_region aReg, acc_index t) { aReg->to = t; }

bool RegIs_out_of_Region(acc_region aReg, acc_index y) {
   return (IdxCompare(y, aReg->from) < 0) || (IdxCompare(aReg->to, y) < 0);
}

bool RegIs_in_Region(acc_region aReg, acc_index y) {
   return (IdxCompare(aReg->from, y) <= 0) && (IdxCompare(y, aReg->to) <= 0);
}

/* end class region for sorting resion information (left - right) */
