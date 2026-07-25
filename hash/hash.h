#ifndef HASH_H
#define HASH_H
#include "hash_ds.h"

extern unsigned long hash(const char *str);
extern HashTable* new(int size);
extern HashNode* find(HashTable *self, const char *word);
extern void insert(HashTable *self, const char *word);
extern void print_fri(HashTable *self);
extern void destroy(HashTable *self);

#endif
