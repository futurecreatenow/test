#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Btree_ds.h"
#include "Btree.h"

// 単語の挿入位置を探す
int search_key(BNode *x, const char *word) {
    int i = 0;
    while (i < x->n && strcmp(word, x->keys[i]) > 0) i++;
    return i;
}

// ノードが満杯時に分割する
void BNode_split_child(BNode *x, int i) {
    BNode *y = x->child[i]; //分割対象のノード。ノードの個数はT-1でこれ以上格納できない。
    BNode *z = BNode_create(y->leaf); //分割後のノード。
    z->n = T - 1; //分割後のノード。分割後は右側にT-1個。

    // 分割後のノードzに単語と頻度をコピーする。
    // y->keys[T,,,2T-2]をz->keys[0,T-2]にコピーする。
    for (int j = 0; j < T - 1; j++) {
        z->keys[j] = y->keys[j + T];
        z->freq[j] = y->freq[j + T];
    }
    // 分割後のノードzにポインタをコピーする。
    if (!y->leaf) {
        for (int j = 0; j < T; j++) z->child[j] = y->child[j + T];
    }

    y->n = T - 1; //分割後のノード。分割後は左側にT-1個。
    for (int j = x->n; j >= i + 1; j--)
        x->child[j + 1] = x->child[j];

    x->child[i + 1] = z; //分割後の右側ノードのポインタを登録。
    for (int j = x->n - 1; j >= i; j--) {
        x->keys[j + 1] = x->keys[j];
        x->freq[j + 1] = x->freq[j];
    }

    // indexT-1を親ノードxに格納。
    x->keys[i] = y->keys[T - 1];
    x->freq[i] = y->freq[T - 1];
    x->n++;
}

// ノードが満杯になるまで挿入する
void BNode_insert_nonfull(BNode *x, const char *word) {
    int i = x->n - 1; //最後のノードを設定

    if (x->leaf) {
        //leafノードの処理
        while (i >= 0 && strcmp(word, x->keys[i]) < 0) {
            //最後のノードから挿入位置まで既存のキーを後ろへずらす。
            x->keys[i + 1] = x->keys[i];
            x->freq[i + 1] = x->freq[i];
            i--;
        }

        if (i >= 0 && strcmp(word, x->keys[i]) == 0) {
            // 既にキーが存在する際は頻度を1追加する。
            x->freq[i]++;
            return;
        }

        //index[i+1]にキーと頻度1を挿入する。
        x->keys[i + 1] = strdup(word);
        x->freq[i + 1] = 1;
        x->n++;
    } else {
        while (i >= 0 && strcmp(word, x->keys[i]) < 0) i--;

        if (i >= 0 && strcmp(word, x->keys[i]) == 0) {
            x->freq[i]++;
            return;
        }

        i++;

        if (x->child[i]->n == MAX_KEYS) {
            x->split_child(x, i);
            if (strcmp(word, x->keys[i]) > 0) i++;
        }
        x->child[i]->insert_nonfull(x->child[i], word);
    }
}

void BNode_traverse(BNode *x) {
    for (int i = 0; i < x->n; i++) {
        if (!x->leaf) x->child[i]->traverse(x->child[i]);
        printf("%s : %d\n", x->keys[i], x->freq[i]);
    }
    if (!x->leaf) x->child[x->n]->traverse(x->child[x->n]);
}

BNode* BNode_create(int leaf) {
    BNode *node = malloc(sizeof(BNode));
    node->leaf = leaf;
    node->n = 0;

    for (int i = 0; i < MAX_CHILD; i++)
        node->child[i] = NULL;

    node->split_child = BNode_split_child;
    node->insert_nonfull = BNode_insert_nonfull;
    node->traverse = BNode_traverse;

    return node;
}

void BTree_insert(BTree *tree, const char *word) {
    BNode *r = tree->root;

    int pos = search_key(r, word);
    if (pos < r->n && strcmp(r->keys[pos], word) == 0) {
        // 既に存在するキーのため頻度を1プラスする。
        r->freq[pos]++;
        return;
    }

    if (r->n == MAX_KEYS) {
        // ノードが満杯のため分割する。
        BNode *s = BNode_create(0); //leafノードとして作成する。
        tree->root = s;
        s->child[0] = r; //
        s->split_child(s, 0);
        s->insert_nonfull(s, word);
    } else {
        r->insert_nonfull(r, word);
    }
}

BTree* BTree_create() {
    BTree *tree = malloc(sizeof(BTree));
    tree->root = BNode_create(1);
    tree->insert = BTree_insert;
    return tree;
}

void BNode_free(BNode *node){
    if(!node) return;

    if(!node->leaf){
        for (int i = 0;i <= node->n;i++) BNode_free(node->child[i]);
    }

    for(int i = 0;i < node->n;i++) free(node->keys[i]);
    free(node);
}

void BTree_free(BTree *tree){
    if(!tree) return;
    BNode_free(tree->root);
    free(tree);
}

int main() {
    BTree *tree = BTree_create();

    const char *filename = "words.txt";
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("can not open file");
        return 1;
    }

    char word[256];
    while (fgets(word, sizeof(word), fp)) {
        word[strcspn(word, "\r\n")] = '\0';
        if (strlen(word) == 0) continue;
        tree->insert(tree, word);
    }

    fclose(fp);

    //単語と頻度の出力
    tree->root->traverse(tree->root);

    //メモリの解放
    BTree_free(tree);
    return 0;
}

