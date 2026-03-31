#include <stdbool.h>
#include <range_ds.h>

acc_range RGCreate(int, int);
void RGFree(acc_range);
void RGRestore(range, int *, int *);
int RGFrom(acc_range);
int  RGTo(acc_range);
void RGSet_From(acc_range, int);
void RGSet_To(acc_range, int);
bool RGIs_out_of_Region(acc_range, int);
bool RGIs_in_Range(acc_range, int);
