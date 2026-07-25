#ifndef HASH_DS
#define HASH_DS
typedef struct HashNode {
    char *word;
    int count;
    struct HashNode *next;
} HashNode;

typedef struct HashTable {
    int size;
    HashNode **buckets;
    void (*insert)(struct HashTable *self, const char *word);
    HashNode* (*find)(struct HashTable *self, const char *word);
    void (*print)(struct HashTable *self);
    void (*destroy)(struct HashTable *self);
} HashTable;

#endif
