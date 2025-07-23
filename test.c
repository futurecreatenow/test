#include <stdio.h>
#include <stdbool.h>

#define SIZE1 5
#define SIZE2 5

// 配列を含む構造体を定義
typedef struct {
    int array1[SIZE1];
    int array2[SIZE2];
} Arrays;

// 配列に初期値を設定する関数
void putArrays(Arrays *arrays) {
    // 配列1の初期値を設定
    int initArray1[SIZE1] = {1, 2, 3, 4, 5};
    for (int i = 0; i < SIZE1; i++) {
        arrays->array1[i] = initArray1[i];
    }

    // 配列2の初期値を設定
    int initArray2[SIZE2] = {4, 5, 6, 7, 8};
    for (int i = 0; i < SIZE2; i++) {
        arrays->array2[i] = initArray2[i];
    }
}

// 構造体のポインタを引数として受け取るunionSet関数
void unionSet(Arrays *arrays) {
    printf("Union: ");
    for (int i = 0; i < SIZE1; i++) {
        printf("%d ", arrays->array1[i]);
    }
    for (int i = 0; i < SIZE2; i++) {
        bool exists = false;
        for (int j = 0; j < SIZE1; j++) {
            if (arrays->array2[i] == arrays->array1[j]) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            printf("%d ", arrays->array2[i]);
        }
    }
    printf("\n");
}

// 構造体のポインタを引数として受け取るintersectionSet関数
void intersectionSet(Arrays *arrays) {
    printf("Intersection: ");
    for (int i = 0; i < SIZE1; i++) {
        for (int j = 0; j < SIZE2; j++) {
            if (arrays->array1[i] == arrays->array2[j]) {
                printf("%d ", arrays->array1[i]);
                break;
            }
        }
    }
    printf("\n");
}

int main() {
    Arrays arrays;

    // 初期値を設定する関数を呼び出し
    putArrays(&arrays);

    // 構造体のポインタを渡して関数を呼び出す
    unionSet(&arrays);
    intersectionSet(&arrays);

    return 0;
}
