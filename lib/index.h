#include <stdbool.h>
#include <index_ds.h>

void dump_Index(acc_index);
acc_index IdxCreate(int, int, int);
int IdxIntVal(acc_index);
void IdxPut_IntVal(acc_index, int);
void IdxInc(acc_index);
void IdxDec(acc_index);
void IdxFree(acc_index);
bool IdxIs_out_of_Range(acc_index);
int IdxCompare(acc_index, acc_index);


