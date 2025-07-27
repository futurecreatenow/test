#ifndef SUBMIT_H
#define SUBMIT_H

#include "submit_ds.h"

extern int memberOf(ARRAY, int);
extern void put(ARRAY, int);
extern ARRAY unionSet(ARRAY, ARRAY);
extern ARRAY intersectionSet(ARRAY, ARRAY);
extern void printSet(ARRAY);
extern ARRAY generateRandomSet();

#endif