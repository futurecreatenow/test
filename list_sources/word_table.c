#include <stdlib.h>

#include <mydef.h>
#include <local.h>

#include <heap.h>
#include <list_node.h>
#include <list.h>

#include <wtab_entry.h>
#include <word_table.h>

static acc_word_table acc_Word_Table;

/* procedure to initialize the type word_table */

void WTInit() { acc_Word_Table = Null_Word_Table; }

/* function to create word_table instance : constructor*/

acc_word_table WTCreate() { /* singleton */
   if (acc_Word_Table == Null_Word_Table) {
      acc_Word_Table =
	 (acc_word_table) HPAlloc(HPCreate(), sizeof(word_table));
      acc_Word_Table->table = ListCreate();
      acc_Word_Table->w = CENTINEL;
   }
   return acc_Word_Table;
}

/* procedure to deallocate the word_table instance */

void WTFree() {
   int y; 

   ListFree(acc_Word_Table->table);
   HPFree(HPCreate(), (void *) acc_Word_Table);
}


/* procedure to put the given string into the table, cout up if exists 
   already */

void WTPut(acc_word_table wTab, string s) {
  int y, l = ListLength(wTab->table);
   acc_wtab_entry awe;
   acc_node thisNode;
   
   for (y = 0, thisNode = ListHead(wTab->table); y < l; ++y) {
      awe = LNData_Ref(thisNode);
      if (WTEIs_this_me(awe, s) == YES) {
	 WTEInc_Freq(awe); /* count up */ return;
      }
      thisNode = LNNext(thisNode);
   }
   wTab->table = ListAppend(wTab->table, WTECreate(s));
}

/* function to check if there is no entry or not */
boolean WTNo_Entry(acc_word_table awt) {
  if (ListIs_Null(awt->table) == YES) return NO; else return YES;
}

/* procedure to sort the entry in the table: selection sort */

void WTSort(acc_word_table wTab, sort_key key) {
   ListSort(wTab->table, WTERelation, key);
}

/* procesure to set table search to the inaitial state */

void WTSetSearch(acc_word_table awt) {
  awt->w = (acc_node) ListHead(awt->table);
}

/* function to get the current vaule in the table */

acc_wtab_entry WTNext(acc_word_table awt) {
   if (LNIs_Null(awt->w) == YES)
      return Null_Word_Table_Entry;
   else {
      acc_wtab_entry awe = LNData_Ref(awt->w);
      awt->w = LNNext(awt->w);
      return awe;
   }

}
