#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T 3
#define MAX_KEYS (2*T - 1)
#define MAX_CHILD (2*T)

typedef struct BNode BNode;
typedef struct BTree BTree;

struct BNode {
    int n;//ノード内に格納されている単語の数
    char *keys[MAX_KEYS];//ノードが保持する単語を格納する配列
    int freq[MAX_KEYS];//単語の出現回数
    BNode *child[MAX_CHILD];//子ノードへのポインタ配列。leafnodeはNULL
    int leaf;//0⇒葉ノード以外。1⇒葉ノード
    void (*split_child)(BNode *self, int i);//子ノードが満杯時にノードを分割する。
    //ノードが満杯出ない場合のinsert。葉ならそのままinsert、内部ノードなら適切な子へinsert
    void (*insert_nonfull)(BNode *self, const char *word);
    //単語と頻度の表示
    void (*traverse)(BNode *self);
};

struct BTree {
    //B木の根ノード。挿入時に根が満杯なら分割して高さが1つ増える。
    BNode *root;

    //木全体への挿入処理。
    void (*insert)(BTree *self, const char *word);
    //単語の頻度の表示
    void (*traverse)(BTree *self);
};

BNode* BNode_create(int leaf);
BTree* BTree_create();

static int search_key(BNode *x, const char *word) {
    int i = 0;
    while (i < x->n && strcmp(word, x->keys[i]) > 0) i++;
    return i;
}

static void BNode_split_child(BNode *x, int i) {
    BNode *y = x->child[i];
    BNode *z = BNode_create(y->leaf);

    z->n = T - 1;

    for (int j = 0; j < T - 1; j++) {
        z->keys[j] = y->keys[j + T];
        z->freq[j] = y->freq[j + T];
    }

    if (!y->leaf) {
        for (int j = 0; j < T; j++)
            z->child[j] = y->child[j + T];
    }

    y->n = T - 1;

    for (int j = x->n; j >= i + 1; j--)
        x->child[j + 1] = x->child[j];

    x->child[i + 1] = z;

    for (int j = x->n - 1; j >= i; j--) {
        x->keys[j + 1] = x->keys[j];
        x->freq[j + 1] = x->freq[j];
    }

    x->keys[i] = y->keys[T - 1];
    x->freq[i] = y->freq[T - 1];
    x->n++;
}

static void BNode_insert_nonfull(BNode *x, const char *word) {
    int i = x->n - 1;

    if (x->leaf) {
        while (i >= 0 && strcmp(word, x->keys[i]) < 0) {
            x->keys[i + 1] = x->keys[i];
            x->freq[i + 1] = x->freq[i];
            i--;
        }

        if (i >= 0 && strcmp(word, x->keys[i]) == 0) {
            x->freq[i]++;
            return;
        }

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

static void BNode_traverse(BNode *x) {
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

static void BTree_insert(BTree *tree, const char *word) {
    BNode *r = tree->root;

    int pos = search_key(r, word);
    if (pos < r->n && strcmp(r->keys[pos], word) == 0) {
        r->freq[pos]++;
        return;
    }

    if (r->n == MAX_KEYS) {
        BNode *s = BNode_create(0);
        tree->root = s;
        s->child[0] = r;
        s->split_child(s, 0);
        s->insert_nonfull(s, word);
    } else {
        r->insert_nonfull(r, word);
    }
}

static void BTree_traverse(BTree *tree) {
    tree->root->traverse(tree->root);
}

BTree* BTree_create() {
    BTree *tree = malloc(sizeof(BTree));
    tree->root = BNode_create(1);
    tree->insert = BTree_insert;
    tree->traverse = BTree_traverse;
    return tree;
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

    tree->traverse(tree);
    return 0;
}

