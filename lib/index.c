#include <stdlib.h>
#include <stdio.h>
#include <heap.h>
#include <common.h>

// #include <region.h>
#include <index.h>

void dump_Index(acc_index a) {
   printf("from:%d to:%d ofIt:%d\n",
	  // RegFrom(a->aReg), RegTo(a->aReg),
	  a->from, a->to,
	  a->ofIt);
}

acc_index IdxCreate(int from, int to, int ofIt) {
   acc_index accIndex; // acc_region aReg;

   if (from < 0 || array_Size <= to) {
      printf("No such index can be created.\n"); exit(-1);
   }
   // aIndex = (acc_index) malloc(sizeof(index));
   accIndex = (acc_index) HPAlloc(HPCreate(), sizeof(index));
   // aIndex->aReg = RegCreate(from, to);
   accIndex->from = from; accIndex->to = to;
   accIndex->ofIt = ofIt;

   return accIndex;
}

// #define IN_RANGE(AR) ((AR->ofIt != out_of_Range) &&			\
//		      ((AR->from <= AR->ofIt) && (AR->ofIt <= AR->to)))
bool IdxIs_in_Range(acc_index accIndex) {
   if (accIndex->from <= accIndex->ofIt && accIndex->ofIt <= accIndex->to)
      return true;
   else
      return false;
}

bool IdxIs_over_Range(acc_index accIndex) {
   if (accIndex->ofIt > accIndex->to) return true; else return false;
}

bool IdxIs_below_Range(acc_index accIndex) {
   if (accIndex->ofIt < accIndex->from) return true; else return false;
}

int IdxIntVal(acc_index accIndex) {
   if (IdxIs_below_Range(accIndex)) return below_Range;
   else if (IdxIs_over_Range(accIndex)) return over_Range;
   else return accIndex->ofIt;
}

void IdxPut_IntVal(acc_index accIndex, int x) {
   // if IN_RANGE(aIndex)
      // (RegIs_in_Region(aIndex->aReg, aIndex->ofIt))
   if (IdxIs_below_Range(accIndex)) accIndex->ofIt = below_Range;
   else if (IdxIs_over_Range(accIndex)) accIndex->ofIt = over_Range;
   else accIndex->ofIt = x;
}

void IdxInc(acc_index accIndex) {
   // printf("before inc = %d,", aIndex->ofIt);

   if (++accIndex->ofIt > accIndex->to)
      accIndex->ofIt = over_Range;
      // (RegIs_out_of_Region(aIndex->aReg, ++aIndex->ofIt))
      // aIndex->ofIt = out_of_Range;
   
   // printf("after inc = %d,", aIndex->ofIt);
}

void IdxDec(acc_index accIndex) {
   // printf("before dec = %d,", aIndex->ofIt);  
   if (--accIndex->ofIt < accIndex->from)
      // (RegIs_out_of_Region(aIndex->aReg, --aIndex->ofIt))
      accIndex->ofIt = below_Range;
   // printf("after dec = %d,", aIndex->ofIt);
}

void IdxFree(acc_index aIndex) { HPFree(HPCreate(), (void *) aIndex); }

bool IdxIs_out_of_Range(acc_index accIndex) {
   // return RegIs_out_of_Region(aIndex->aReg, aIndex->ofIt);
   return (accIndex->ofIt < accIndex->from) ||
          (accIndex->to < accIndex->ofIt);
}

int IdxCompare(acc_index x, acc_index y) {
   // printf("x in IdxCompare->"); dump_Index(x);
   // printf("y in IdxCompare->"); dump_Index(y);  
   // if (!IN_RANGE(x) || !IN_RANGE(y)) {
      // (IdxOut_of_Range(x) || IdxOut_of_Range(y)) {
      // printf("Out of Range in index compare.\n"); exit(-1);
   // }
   if (x->ofIt < y->ofIt) return -1;
   else if (x->ofIt == y->ofIt) return 0;
   else return 1;
}
