#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_ *acc_node;
struct node_{
    char* w;
    int count;
    acc_node next;
    //acc_node prev;
};
typedef struct node_ node;
#define CENTINEL (acc_node) 0
typedef struct ow2_list_{
    acc_node head,tail;
}list_body,*list;
#define NULL_LIST(list) 0

//Function prototype
acc_node createNode(const char*,int);
void addNode(list,const char*,int);
int listToArray(list,node** );
int compareByCount(const void*,const void*);
int compareByWord(const void*,const void*);
void arrayToList(node *,int,list);
void printList(list);

acc_node createNode(const char* word,int count){
    acc_node newNode = (acc_node)malloc(sizeof(node));
    newNode->w = strdup(word);
    newNode->count = count;
    newNode->next = NULL;
    return newNode;
}

void addNode(list l,const char* word,int count){
    acc_node newNode = createNode(word,count);
    if(l->head==NULL){
        l->head = newNode;
        l->tail = newNode;
    }else{
        l->tail->next = newNode;
        l->tail=newNode;
    }
}

int listToArray(list l,node** arr){
    int count = 0;
    acc_node current = l->head;
    while(current != NULL){
        count++;
        current = current->next;
    }
    *arr= (node*)malloc(count * sizeof(node));
    current = l->head;
    for(int i= 0;i < count;i++){
        (*arr)[i] = *current;
        current = current->next;
    }
    return count;
}
int compareByCount(const void *a,const void *b){
    node* nodeA=(node*)a;
    node* nodeB=(node*)b;
    return (nodeA->count - nodeB->count);
}

int compareByWord(const void* a,const void* b){
    node* nodeA=(node*)a;
    node* nodeB=(node*)b;
    return strcmp(nodeA->w,nodeB->w);
}

void arrayToList(node *arr,int size ,list l){
    l->head = l->tail = NULL;
    for (int i = 0;i<size;i++){
        acc_node newNode = (acc_node)malloc(sizeof(node));
        *newNode=arr[i];
        newNode->next=NULL;
        if(l->head==NULL){
            l->head=l->tail=newNode;
        }else{
            l->tail->next = newNode;
            l->tail = newNode;
        }
    }
}

void printList(list l){
    acc_node current=l->head;
    while(current != NULL){
        printf("(WORD:Count)=(%s:%d)\n",current->w,current->count);
        current = current->next;
    }
}

int main(){
    list myList=(list)malloc(sizeof(list_body));
    myList->head=NULL;
    myList->tail=NULL;
    addNode(myList,"apple",3);
    addNode(myList,"banana",4);
    addNode(myList,"cherry",5);
    addNode(myList,"date",1);
    addNode(myList,"clderberry",4);
    node* arr;
    int size=listToArray(myList,&arr);

    qsort(arr,size,sizeof(node),compareByCount);
    arrayToList(arr,size,myList);
    printf("Sorted by count\n");
    printList(myList);

    qsort(arr,size,sizeof(node),compareByWord);
    arrayToList(arr,size,myList);
    printf("Sorted by word\n");
    printList(myList);

    free(arr);
    return 0;
}
