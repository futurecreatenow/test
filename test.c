//サンプルコード
//マージソートのプログラム作成する
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CENTINEL (acc_node)0
#define NULL_LIST (list)0
typedef struct node_ *acc_node;
struct node_ {
    char *w;
    int count;
#ifdef TWO_WAY
    acc_node prev;
#endif
    acc_node next;
};
typedef struct node_ node;

typedef struct ow2_list_ {
    acc_node head, tail;
} list_body, *list;

// リストを初期化する関数
list init_list() {
    list l = (list)malloc(sizeof(list_body));
    if (l == NULL) {
        return NULL_LIST;
    }
    l->head = l->tail = NULL;
    return l;
}

// ノードを作成する関数
acc_node create_node(char *w, int count) {
    acc_node new_node = (acc_node)malloc(sizeof(node));
    if (new_node == NULL) {
        return CENTINEL;
    }
    new_node->w = strdup(w);
    new_node->count = count;
#ifdef TWO_WAY
    new_node->prev = NULL;
#endif
    new_node->next = NULL;
    return new_node;
}

// リストにノードを追加する関数
void append_node(list l, acc_node new_node) {
    if (l->head == NULL) {
        l->head = l->tail = new_node;
    } else {
        l->tail->next = new_node;
#ifdef TWO_WAY
        new_node->prev = l->tail;
#endif
        l->tail = new_node;
    }
}

// リストを分割する関数
list split_list(list l) {
    if (l == NULL_LIST || l->head == l->tail) {
        return NULL_LIST;
    }

    acc_node slow = l->head;
    acc_node fast = l->head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    list second_half = init_list();
    second_half->head = slow->next;
    second_half->tail = l->tail;
    l->tail = slow;
    slow->next = NULL;

    return second_half;
}

// 2つのソート済みリストをマージする関数
list merge_sorted_lists(list list1, list list2) {
    list merged_list = init_list();
    if (merged_list == NULL_LIST) {
        return NULL_LIST;
    }

    acc_node current1 = list1->head;
    acc_node current2 = list2->head;

    while (current1 != NULL && current2 != NULL) {
        if (strcmp(current1->w, current2->w) < 0 ||
            (strcmp(current1->w, current2->w) == 0 && current1->count < current2->count)) {
            append_node(merged_list, current1);
            current1 = current1->next;
        } else {
            append_node(merged_list, current2);
            current2 = current2->next;
        }
    }

    while (current1 != NULL) {
        append_node(merged_list, current1);
        current1 = current1->next;
    }

    while (current2 != NULL) {
        append_node(merged_list, current2);
        current2 = current2->next;
    }

    free(list1);
    free(list2);
    return merged_list;
}

// マージソート関数
list merge_sort(list l) {
    if (l == NULL_LIST || l->head == l->tail) {
        return l;
    }

    list second_half = split_list(l);
    l = merge_sort(l);
    second_half = merge_sort(second_half);

    return merge_sorted_lists(l, second_half);
}

// リストを表示する関数
void print_list(list l) {
    acc_node current = l->head;
    while (current != NULL) {
        printf("w: %s, count: %d\n", current->w, current->count);
        current = current->next;
    }
}

// リストを解放する関数
void free_list(list l) {
    acc_node current = l->head;
    while (current != NULL) {
        acc_node temp = current;
        current = current->next;
        free(temp->w);
        free(temp);
    }
    free(l);
}

int main() {
    list my_list = init_list();

    append_node(my_list, create_node("apple", 5));
    append_node(my_list, create_node("banana", 3));
    append_node(my_list, create_node("apple", 2));
    append_node(my_list, create_node("orange", 8));
    append_node(my_list, create_node("banana", 7));

    my_list = merge_sort(my_list);

    print_list(my_list);

    free_list(my_list);

    return 0;
}
//挿入ソート法
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CENTINEL (acc_node)0
#define NULL_LIST (list)0
typedef struct node_ *acc_node;
struct node_ {
    char *w;
    int count;
#ifdef TWO_WAY
    acc_node prev;
#endif
    acc_node next;
};
typedef struct node_ node;

typedef struct ow2_list_ {
    acc_node head, tail;
} list_body, *list;

// リストを初期化する関数
list init_list() {
    list l = (list)malloc(sizeof(list_body));
    if (l == NULL) {
        return NULL_LIST;
    }
    l->head = l->tail = NULL;
    return l;
}

// ノードを作成する関数
acc_node create_node(char *w, int count) {
    acc_node new_node = (acc_node)malloc(sizeof(node));
    if (new_node == NULL) {
        return CENTINEL;
    }
    new_node->w = strdup(w);
    new_node->count = count;
#ifdef TWO_WAY
    new_node->prev = NULL;
#endif
    new_node->next = NULL;
    return new_node;
}

// リストにノードを追加する関数
void append_node(list l, acc_node new_node) {
    if (l->head == NULL) {
        l->head = l->tail = new_node;
    } else {
        l->tail->next = new_node;
#ifdef TWO_WAY
        new_node->prev = l->tail;
#endif
        l->tail = new_node;
    }
}

// 挿入ソート関数
list insertion_sort(list l) {
    if (l == NULL_LIST || l->head == l->tail) {
        return l;
    }

    list sorted_list = init_list();
    if (sorted_list == NULL_LIST) {
        return NULL_LIST; // メモリ割り当てエラー
    }

    acc_node current = l->head;
    while (current != NULL) {
        acc_node next_node = current->next;
        if (sorted_list->head == NULL) {
            // ソート済みリストが空の場合、最初のノードをヘッドにする
            sorted_list->head = sorted_list->tail = current;
            current->next = NULL; // 分離
#ifdef TWO_WAY
            current->prev = NULL;
#endif
        } else {
            acc_node insert_pos_prev = NULL;
            acc_node insert_pos = sorted_list->head;

            // 挿入位置を見つける
            while (insert_pos != NULL) {
                if (strcmp(current->w, insert_pos->w) < 0 ||
                    (strcmp(current->w, insert_pos->w) == 0 && current->count < insert_pos->count)) {
                    break; // 挿入位置を発見
                }
                insert_pos_prev = insert_pos;
                insert_pos = insert_pos->next;
            }

            if (insert_pos_prev == NULL) {
                // リストの先頭に挿入
                current->next = sorted_list->head;
                sorted_list->head = current;
#ifdef TWO_WAY
                sorted_list->head->prev = NULL; // sorted_list->head is now current
                if (current->next) current->next->prev = current;
#endif
            } else if (insert_pos == NULL) {
                // リストの末尾に挿入
                insert_pos_prev->next = current;
                sorted_list->tail = current;
                current->next = NULL;
#ifdef TWO_WAY
                current->prev = insert_pos_prev;
#endif
            } else {
                // リストの途中に挿入
                insert_pos_prev->next = current;
                current->next = insert_pos;
#ifdef TWO_WAY
                current->prev = insert_pos_prev;
                insert_pos->prev = current;
#endif
            }
            current->next = NULL; // 分離 (念のため、上記で設定済みだが明示的に)
#ifdef TWO_WAY
            current->prev = NULL; // 分離
#endif
        }
        current = next_node;
    }
    free_list(l); // 元のリストを解放
    return sorted_list;
}


// リストを表示する関数 (変更なし)
void print_list(list l) {
    acc_node current = l->head;
    while (current != NULL) {
        printf("w: %s, count: %d\n", current->w, current->count);
        current = current->next;
    }
}

// リストを解放する関数 (変更なし)
void free_list(list l) {
    if (l == NULL) return;
    acc_node current = l->head;
    while (current != NULL) {
        acc_node temp = current;
        current = current->next;
        free(temp->w);
        free(temp);
    }
    free(l);
}

int main() {
    list my_list = init_list();

    append_node(my_list, create_node("apple", 5));
    append_node(my_list, create_node("banana", 3));
    append_node(my_list, create_node("apple", 2));
    append_node(my_list, create_node("orange", 8));
    append_node(my_list, create_node("banana", 7));

    my_list = insertion_sort(my_list); // マージソートを挿入ソートに変更

    print_list(my_list);

    free_list(my_list);

    return 0;
}
