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
string moji[MOJINUM]={"one","two","three","two"};

//リスト型の構造体
//typedef int item_type;
typedef struct node_ *acc_node;
struct node_ {
    //item_type d;
    string w;
    int count;
    acc_node next;
    //acc_node prev;
};
typedef struct node_ node;
#define CENTINEL (acc_node) 0
typedef struct ow2_list_ {
    acc_node head,tail;
    //string w;
    //int count;
} list_body,*list;
#define NULL_LIST (list) 0

//関数のプロトタイプ宣言
list ListCreate();
list ListAppend(list,string);
acc_node LNCreate(string);

//関数の実体
/* function to create a oneway list */
list ListCreate() {
   list l;
   l = (list) HPAlloc(HPCreate(), sizeof(list_body));
   l->head = l->tail = CENTINEL;
   return l;
}
/*リスト先のポインタを指定せず値のみ格納した構造体*/
acc_node LNCreate(string w){
    acc_node an;
    an = (acc_node) HPAlloc(HPCreate(),sizeof(node));
    strcpy(an->w,w);
    an->next = CENTINEL;
    return an;
}
/*function to put the node after the tail of the list*/
list ListAppend(list l,string moji){
    acc_node t = LNCreate(moji);
    if (l == NULL_LIST){
        printf("List is never allocated");
    }
    return l;
}
int main(){
    sort_key sKey;
    sKey = BY_FREQ;
    list wordlist = ListCreate();
    int mojisize = sizeof(moji) /sizeof(moji[0]);
    for (int i = 0;i < mojisize ;i++){
        printf("%s\n",moji[i]);
        wordlist = ListAppend(wordlist,moji[i]);
    }
    printf("no problem");
    return 0;
}
