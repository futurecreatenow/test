#include <stdio.h>

#define MAX_ARRAY_NUM 10
#define UNION_INIT_ELE 0
#define UNION_INIT_NUM 0
#define INTER_INIT_ELE 0
#define INTER_INIT_NUM 0

struct int_set {
    int elements[MAX_ARRAY_NUM];
    int numOfElts;
};

typedef struct int_set ARRAY;

// 要素が集合に含まれているかを判定
int memberOf(ARRAY s, int i) {
    for (int y = 0; y < s.numOfElts; ++y) if (s.elements[y] == i) return 1;
    return 0;
}

// 集合に要素を追加
void put(ARRAY *s, int i) {
    if (s->numOfElts < MAX_ARRAY_NUM && !memberOf(*s, i)) {
        s->elements[s->numOfElts++] = i;
    }
}

// 和集合を計算
ARRAY unionSet(ARRAY first, ARRAY second) {
    ARRAY result = {{UNION_INIT_ELE}, UNION_INIT_NUM};
    for (int i = 0; i < first.numOfElts; ++i) put(&result, first.elements[i]);
    for (int i = 0; i < second.numOfElts; ++i) put(&result, second.elements[i]);
    return result;
}

// 積集合を計算
ARRAY intersectionSet(ARRAY first, ARRAY second) {
    ARRAY result = {{INTER_INIT_ELE}, INTER_INIT_NUM};
    for (int i = 0; i < first.numOfElts; ++i) {
        if (memberOf(second, first.elements[i])) put(&result, first.elements[i]);
    }
    return result;
}

// 集合の表示
void printSet(ARRAY s) {
    printf("{ ");
    for (int i = 0; i < s.numOfElts; ++i) printf("%d ", s.elements[i]);
    printf("}\n");
}

int main() {
    ARRAY first_array = {{1, 2, 3}, 3};
    ARRAY second_array = {{3, 4, 5}, 3};
    
    printf("first_array: \n");
    printSet(first_array);
    printf("second_array: \n");
    printSet(second_array);

    ARRAY union_array = unionSet(first_array, second_array);
    ARRAY intersection_array = intersectionSet(first_array, second_array);
    
    printf("union_array: \n");
    printSet(union_array);
    printf("intersection_array: \n");
    printSet(intersection_array);

    return 0;
}
