/* data structure for word table entry */

#ifndef WTAB_ENTRY_DS
#define WTAB_ENTRY_DS

struct wtab_entry_ {
   string s; /* a string entried */
   int freq; /* its frequency */
};

typedef struct wtab_entry_ wtab_entry;
typedef wtab_entry *acc_wtab_entry;

typedef enum {BY_STRING, BY_FREQ} sort_key;
typedef enum {LESS_THAN, EQUAL,  GREATER_THAN} equality;

// #define NULL_WORD_TABLE_ENTRY (acc_wtab_entry) 0
// const acc_wtab_entry Null_Word_Table_Entry = (acc_wtab_entry) 0;
#define Null_Word_Table_Entry (acc_wtab_entry) 0

#define SPACE ' '

#endif
