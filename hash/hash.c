#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_MAX 256

/* ================================
   HashNode（内部ノード）
   ================================ */
typedef struct HashNode {
    char *word;
    int count;
    struct HashNode *next;
} HashNode;

/* ================================
   HashTable（擬似クラス）
   ================================ */
typedef struct HashTable {
    int size;
    HashNode **buckets;

    /* メソッド */
    void (*insert)(struct HashTable *self, const char *word);
    HashNode* (*find)(struct HashTable *self, const char *word);
    void (*print)(struct HashTable *self);
    void (*destroy)(struct HashTable *self);
} HashTable;

/* ================================
   ハッシュ関数（djb2）
   ================================ */
static unsigned long hash(const char *str) {
    unsigned long h = 5381;
    int c;
    while ((c = *str++)) {
        h = 33 * h + c;
    }
    return h;
}

/* ================================
   find メソッド
   ================================ */
static HashNode* HashTable_find(HashTable *self, const char *word) {
    unsigned long idx = hash(word) % self->size;
    HashNode *cur = self->buckets[idx];

    while (cur) {
        if (strcmp(cur->word, word) == 0) return cur;
        cur = cur->next;
    }
    return NULL;
}

/* ================================
   insert メソッド
   ================================ */
static void HashTable_insert(HashTable *self, const char *word) {
    unsigned long idx = hash(word) % self->size;
    HashNode *node = HashTable_find(self, word);

    if (node) {
        node->count++;
        return;
    }

    node = malloc(sizeof(HashNode));
    node->word = strdup(word);
    node->count = 1;
    node->next = self->buckets[idx];
    self->buckets[idx] = node;
}

/* ================================
   print メソッド
   ================================ */
static void HashTable_print(HashTable *self) {
    for (int i = 0; i < self->size; i++) {
        HashNode *cur = self->buckets[i];
        while (cur) {
            printf("%s : %d\n", cur->word, cur->count);
            cur = cur->next;
        }
    }
}

/* ================================
   destroy メソッド
   ================================ */
static void HashTable_destroy(HashTable *self) {
    for (int i = 0; i < self->size; i++) {
        HashNode *cur = self->buckets[i];
        while (cur) {
            HashNode *next = cur->next;
            free(cur->word);
            free(cur);
            cur = next;
        }
    }
    free(self->buckets);
    free(self);
}

/* ================================
   コンストラクタ
   ================================ */
HashTable* HashTable_new(int size) {
    HashTable *ht = malloc(sizeof(HashTable));
    ht->size = size;
    ht->buckets = calloc(size, sizeof(HashNode*));

    ht->insert = HashTable_insert;
    ht->find   = HashTable_find;
    ht->print  = HashTable_print;
    ht->destroy = HashTable_destroy;

    return ht;
}

/* ================================
   main（利用側）
   ================================ */
int main() {
    FILE *fp = fopen("words.txt", "r");
    if (!fp) {
        perror("words.txt");
        return 1;
    }

    HashTable *ht = HashTable_new(101);

    char buf[WORD_MAX];
    while (fgets(buf, sizeof(buf), fp)) {
        buf[strcspn(buf, "\n")] = '\0';
        if (strlen(buf) > 0) {
            ht->insert(ht, buf);
        }
    }

    fclose(fp);

    ht->print(ht);
    ht->destroy(ht);

    return 0;
}

