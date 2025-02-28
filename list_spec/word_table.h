#ifndef WORD_TABLE_H
#define WORD_TABLE_H

#include <mydef.h>
#include <local.h>
#include <word_table_ds.h>
#include <stdio.h>

extern void WTInit(void);

extern acc_word_table WTCreate(void); /* singleton */
extern void WTFree(void);
extern void WTPut(acc_word_table, string);
extern boolean WTNo_Entry(acc_word_table);
extern void WTSort(acc_word_table, sort_key);
extern void WTSetSearch(acc_word_table);
extern acc_wtab_entry WTNext(acc_word_table);

#endif
