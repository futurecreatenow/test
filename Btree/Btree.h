#ifndef BTREE_H
#define BTREE_H
#include "Btree.h"

extern int search_key(BNode *x, const char *word);
extern void BNode_split_child(BNode *x, int i);
extern void BNode_insert_nonfull(BNode *x, const char *word);
extern void BNode_traverse(BNode *x);
extern BNode* BNode_create(int leaf);
extern void BTree_insert(BTree *tree, const char *word);
extern BTree* BTree_create();
extern void BNode_free(BNode *node);
extern void BTree_free(BTree *tree);

#endif
