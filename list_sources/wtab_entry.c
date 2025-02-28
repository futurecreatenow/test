/* operations for word table entry */

#include <stdio.h>
#include <string.h>

#include <mydef.h>
#include <local.h>
#include <heap.h>
#include <wtab_entry_ds.h>

acc_wtab_entry WTECreate(string s) {
   acc_wtab_entry awe; heap *accHeap = HPCreate();

   awe = (acc_wtab_entry) HPAlloc(accHeap, sizeof(wtab_entry));
   awe->s = s; awe->freq = 1;

   return awe;
}

void WTEFree(acc_wtab_entry awe) { HPFree(HPCreate(), (void *) awe); }

boolean WTEIs_this_me(acc_wtab_entry awe, string s) {
   if (strcmp(awe->s, s) == 0) return YES; else return NO;
}

void WTEInc_Freq(acc_wtab_entry awe) { ++awe->freq; }

int WTEFreq(acc_wtab_entry awe) { return awe->freq; }

string WTEWord(acc_wtab_entry awe) { return awe->s; }

equality WTERelation(acc_wtab_entry l, acc_wtab_entry r, sort_key cc) {
   int rl, rr;
   
   switch (cc) {
   case BY_STRING:
      rl = (strcmp(l->s, r->s) < 0)? 1 : 0;
      rr = (strcmp(l->s, r->s) > 0)? 1 : 0;
      break;
   case BY_FREQ:
      rl = l->freq < r->freq;
      rr = l->freq > r->freq;
   }
   
   if (rl == 1) return LESS_THAN;
   else if (rr == 1) return GREATER_THAN;
   else return EQUAL;
}
