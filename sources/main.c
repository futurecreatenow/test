#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../mydef/mydef.h"
#include "../heap/heap.h"

////単語順か頻度順の選択
//#define PROMPT "Which key,w for word,frequency otherwise?"

//単語順か頻度順かの列挙型変数
typedef enum {BY_STRING,BY_FREQ} sort_key;

//入力された疑似文字列
#define MOJINUM 4
const char* moji[MOJINUM]={"one","two","three","two"};

//リスト型の構造体
typedef int item_type;
typedef struct node_ *acc_node;
struct node_ {
    item_type d;
    acc_node next;
    acc_node prev;
};
typedef struct node_ node;
#define CENTINEL (acc_node) 0
typedef struct ow2_list_ {acc_node head,tail;} list_body,*list;
#define NULL_LIST (list) 0

//関数のプロトタイプ宣言
list ListCreate();

//関数の実体
/* function to create a oneway list */
list ListCreate() {
   list l;
   l = (list) HPAlloc(HPCreate(), sizeof(list_body));
   l->head = l->tail = CENTINEL;
   return l;
}
int main(){
    sort_key sKey;
    sKey = BY_FREQ;
    list wordlist = ListCreate();
    printf("no problem");
    return 0;
}
