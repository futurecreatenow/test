#ifndef SUBMIT_DS
#define SUBMIT_DS

#define MIN_ARRAY_ELE 8 //Minimum number of elements
#define MAX_ARRAY_ELE 10 //Maximum number of elements
#define MIN_ARRAY_NUM 3 //Minimum integer value that an array can take
#define MAX_ARRAY_NUM 20 //Maximum integer value that an array can take
#define ARRAY_INIT_ELE 0 //Number of elements in the initial array
#define ARRAY_INIT_NUM 0 //Initial value array of integer values
#define UNION_INIT_ELE 0 //Number of elements in the initial union
#define UNION_INIT_NUM 0 //The union of initial values of integer values.
#define INTER_INIT_ELE 0 //Number of elements in the initial intersection
#define INTER_INIT_NUM 0 //The intersection of initial values of integer values.

struct int_set {
    int elements[MAX_ARRAY_ELE];
    int numOfElts;
};

typedef struct int_set ARRAY;
#endif