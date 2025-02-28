#ifndef WORD_TABLE_DS
#define WORD_TABLE_DS

#include <list_node_ds.h>
#include <list_ds.h>
#include <wtab_entry_ds.h>

struct word_table_ {
   list table;
   acc_node w;
};

typedef struct word_table_ word_table, *acc_word_table;

// const acc_word_table Null_Word_Table = (acc_word_table) 0;
#define Null_Word_Table (acc_word_table) 0

#endif
