#include <stdbool.h>
#include <region_ds.h>

acc_region RegCreate(acc_index, acc_index);
void RegFree(acc_region);
void RegRestore(region, acc_index *, acc_index *);
acc_index RegFrom(acc_region);
acc_index RegTo(acc_region);
void RegSet_From(acc_region, acc_index);
void RegSet_To(acc_region, acc_index);
bool RegIs_out_of_Region(acc_region, acc_index);
bool RegIs_in_Region(acc_region, acc_index);
