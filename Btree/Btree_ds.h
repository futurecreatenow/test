#ifndef BTREE_DS
#define BTREE_DS

#define T 3
#define MAX_KEYS (2*T - 1)
#define MAX_CHILD (2*T)

typedef struct BNode {
    int n;//ノード内に格納されている単語の数
    char *keys[MAX_KEYS];//ノードが保持する単語を格納する配列
    int freq[MAX_KEYS];//単語の出現回数
    struct BNode *child[MAX_CHILD];//子ノードへのポインタ配列。leafnodeはNULL
    int leaf;//0⇒葉ノード以外。1⇒葉ノード
    void (*split_child)(struct BNode *self, int i);//子ノードが満杯時にノードを分割する。
    //ノードが満杯出ない場合のinsert。葉ならそのままinsert、内部ノードなら適切な子へinsert
    void (*insert_nonfull)(struct BNode *self, const char *word);
    //単語と頻度の表示
    void (*traverse)(struct BNode *self);
}BNode;

typedef struct BTree {
    //B木の根ノード。挿入時に根が満杯なら分割して高さが1つ増える。
    BNode *root;

    //木全体への挿入処理。
    void (*insert)(struct BTree *self, const char *word);
}BTree;

#endif
