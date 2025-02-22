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
boolean is_Centinel(acc_node);
boolean LNIs_Null(acc_node);
void LNAppend(acc_node,acc_node);
void ListPrint(list);
boolean ListIs_Null(list);
acc_node LNNext(acc_node);
string LNData_Ref(acc_node);

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

boolean is_Centinel(acc_node an){
    return (an == CENTINEL) ? YES : NO;

}
boolean LNIs_Null(acc_node an){
    return is_Centinel(an);
}

void LNAppend(acc_node e,acc_node a){
    e->next = a;
}

/*function to put the node after the tail of the list*/
list ListAppend(list l,string moji){
    acc_node t = LNCreate(moji);
    if (l == NULL_LIST){
        printf("List is never allocated");
    }else if(LNIs_Null(l->head)==YES){
        printf("ListAppend func else if >>  %s\n",moji);
        l->head=l->tail=t;
    }else{
        printf("ListAppend func else >>  %s\n",moji);
        LNAppend(l->tail,t);
    }
    return l;
}

boolean ListIs_Null(list l){
    if(l == NULL_LIST) {printf("List is never allocated");}
    else if((LNIs_Null(l->head)==YES) && (LNIs_Null(l->tail) == YES)){
        return YES;
    }else{return NO;}
}

acc_node LNNext(acc_node an){
    if(is_Centinel(an)) return an;
    else return an->next;
}

string LNData_Ref(acc_node an){ return an->w; }

void ListPrint(list l){
    acc_node n;
    if(ListIs_Null(l) == YES){
        printf("Null list\n");
    }else{
        for(n=l->head;LNIs_Null(n) == NO;n=LNNext(n)){
            printf("%s\n",LNData_Ref(n));
        }
    }
}


int main(){
    sort_key sKey;
    sKey = BY_FREQ;
    list wordlist = ListCreate();
    int mojisize = sizeof(moji) /sizeof(moji[0]);
    for (int i = 0;i < mojisize ;i++){
        printf("moji >> %s\n",moji[i]);
        wordlist = ListAppend(wordlist,moji[i]);
    }
    printf("-----------------");
    ListPrint(wordlist);
    return 0;
}
