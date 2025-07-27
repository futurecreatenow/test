#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_ARRAY_ELE 6 //最小の要素数
#define MAX_ARRAY_ELE 10 //最大の要素数
#define MIN_ARRAY_NUM 3 //配列の取り得る最小整数値
#define MAX_ARRAY_NUM 99 //配列の取り得る最大整数値
#define ARRAY_INIT_ELE 0 
#define ARRAY_INIT_NUM 0
#define UNION_INIT_ELE 0
#define UNION_INIT_NUM 0
#define INTER_INIT_ELE 0
#define INTER_INIT_NUM 0

struct int_set {
    int elements[MAX_ARRAY_ELE];
    int numOfElts;
};

typedef struct int_set ARRAY;

// 要素が集合に含まれているかを判定
int memberOf(ARRAY s, int i) {
    for (int y = 0; y < s.numOfElts; ++y)
        if (s.elements[y] == i) return 1;
    return 0;
}

// 集合に要素を追加
void put(ARRAY *s, int i) {
    if (s->numOfElts < MAX_ARRAY_ELE && !memberOf(*s, i)) {
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

// 配列の初期化
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
