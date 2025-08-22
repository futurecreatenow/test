#ifndef SET_DS_H
#define SET_DS_H

#ifndef MEMBER_TYPE
#define MEMBER_TYPE int
#endif

static const int max_No_Set_Members = 1024;

struct set_ {
   MEMBER_TYPE set[max_No_Set_Members];
   int noMembers, scanningPosition;
};

typedef struct set_ set, *acc_set                       ;

#endif
