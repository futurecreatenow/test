#ifndef SUBMIT_DS
#define SUBMIT_DS

#define MIN_ARRAY_ELE 5 //Minimum number of elements
#define MAX_ARRAY_ELE 20 //Maximum number of elements
#define MIN_ARRAY_NUM 1 //Minimum integer value that an array can take
#define MAX_ARRAY_NUM 100 //Maximum integer value that an array can take

struct int_set {
    int elements[MAX_ARRAY_ELE];
    int numOfElts;
};

typedef struct int_set ARRAY;
#endif
