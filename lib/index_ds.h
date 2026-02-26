#ifndef INDEX_H
#define INDEX_H

// #include <range_ds.h>
extern const int array_Size;
// extern const int out_Of_Range;
extern const int below_Range;
extern const int over_Range;

typedef struct index_ {
   // acc_range aReg;
   int from, to;
   int ofIt;
} index, *acc_index;

#endif
