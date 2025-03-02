//サンプルコード
//マージソートのプログラム作成する
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_ *acc_node;
struct node_{
    char* w;
    int count;
#  ifdef TWO_WAY
   acc_node prev;
#  endif
};
typedef struct node_ node;
#define CENTINEL (acc_node) 0

typedef struct ow2_list_{
    acc_node head,tail;
}list_body ,*list;
#define NULL_LIST (list) 0
