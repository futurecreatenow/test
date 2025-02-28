/* data structure for word table entry */

#ifndef WTAB_ENTRY_DS_H
#define WTAB_ENTRY_DS_H

#include <wtab_entry_ds.h>

extern acc_wtab_entry WTECreate(string);
extern void WTEFree(acc_wtab_entry);

extern boolean WTEIs_this_me(acc_wtab_entry, string);
extern void WTEInc_Freq(acc_wtab_entry);
extern int WTEFreq(acc_wtab_entry);
extern string WTEWord(acc_wtab_entry);
extern equality WTERelation(acc_wtab_entry, acc_wtab_entry, sort_key);

#endif
