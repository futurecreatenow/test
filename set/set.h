#ifndef SET_H
#define SET_H

#include <set_ds.h>

// extern void SetInit(void);
extern acc_set SetCreate(void);
extern boolean SetIs_Member_Of(acc_set, MEMBER_TYPE);
extern void SetScanning(acc_set);
extern void SetProceed_Scanning_Position(acc_set);
extern MEMBER_TYPE SetGet_Current_Member(acc_set);
extern void SetAdd(acc_set, MEMBER_TYPE);
extern void SetRemove(acc_set, MEMBER_TYPE);
extern boolean SetIs_Empty(acc_set);
extern int SetNumber_of_Members(acc_set);
extern set SetUnion(acc_set, acc_set);
extern set SetIntersection(acc_set, acc_set);
extern set SetDifference(acc_set, acc_set);

extern void SetDump(acc_set, string);

#endif
