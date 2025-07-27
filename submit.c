#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "submit_ds.h"

// Determine whether an element is contained in set.
int memberOf(ARRAY s, int i) {
    for (int y = 0; y < s.numOfElts; ++y)
        if (s.elements[y] == i) return 1;
    return 0;
}

// Append of array
void put(ARRAY *s, int i) {
    if (s->numOfElts < MAX_ARRAY_ELE && !memberOf(*s, i)) {
        s->elements[s->numOfElts++] = i;
    }
}

// Calculation of union set
ARRAY unionSet(ARRAY first, ARRAY second) {
    ARRAY result = {{UNION_INIT_ELE}, UNION_INIT_NUM};
    for (int i = 0; i < first.numOfElts; ++i) put(&result, first.elements[i]);
    for (int i = 0; i < second.numOfElts; ++i) put(&result, second.elements[i]);
    return result;
}

// Calculation of intersection set
ARRAY intersectionSet(ARRAY first, ARRAY second) {
    ARRAY result = {{INTER_INIT_ELE}, INTER_INIT_NUM};
    for (int i = 0; i < first.numOfElts; ++i) {
        if (memberOf(second, first.elements[i])) put(&result, first.elements[i]);
    }
    return result;
}

// Output of set
void printSet(ARRAY s) {
    printf("{ ");
    for (int i = 0; i < s.numOfElts; ++i) printf("%d ", s.elements[i]);
    printf("}\n");
}

// Initialization of array
ARRAY generateRandomSet() {
    ARRAY s = {{ARRAY_INIT_ELE}, ARRAY_INIT_NUM};
    int count = rand() % (MAX_ARRAY_ELE - MIN_ARRAY_ELE + 1) + MIN_ARRAY_ELE; 
    while (s.numOfElts < count) {
        int value = rand() % (MAX_ARRAY_NUM - MIN_ARRAY_NUM + 1) + MIN_ARRAY_NUM; 
        put(&s, value);
    }
    return s;
}


int main() {
    srand((unsigned int)time(NULL)); 

    ARRAY first_array = generateRandomSet();
    printf("first_array: \n");
    printSet(first_array);

    ARRAY second_array = generateRandomSet();
    printf("second_array: \n");
    printSet(second_array);

    ARRAY union_array = unionSet(first_array, second_array);
    printf("union_array: \n");
    printSet(union_array);
    
    ARRAY intersection_array = intersectionSet(first_array, second_array);
    printf("intersection_array: \n");
    printSet(intersection_array);

    return 0;
}
