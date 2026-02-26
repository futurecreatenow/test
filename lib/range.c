#include <range.h>

#include <stdlib.h>

#include <heap.h>

/* class range for sorting resion information (left - right) */
acc_range RGCreate(int l, int r) {
   acc_range aRange;
   aRange = (acc_range) HPAlloc(HPCreate(), sizeof(range));
   aRange->from = l; aRange->to = r;

   return aRange;
}

void RGFree(acc_range ar) { HPFree(HPCreate(), (void *) ar); }

void RGRestore(range ar, int *f, int *t) {
   *f  = ar.from; *t  = ar.to; 
}

int RGFrom(acc_range ar) { return ar->from; }

int RGTo(acc_range ar) { return ar->to; }

void RGSet_From(acc_range ar, int f) { ar->from = f; }

void RGSet_To(acc_range ar, int t) { ar->to = t; }

bool RGIs_out_of_Range(acc_range ar, int y) {
   return (y < ar->from) || (ar->to < y);
}

bool RGIs_in_Range(acc_range ar, int y) {
   return (ar->from <= y) && (y <= ar->to);
}

/* end class region for sorting resion information (left - right) */
