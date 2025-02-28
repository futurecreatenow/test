#include <mydef.h>
#include <local.h>

#include <out.h>

#include <word_table.h>
#include <wtab_entry.h>

#define HEADER1 " word     | count"
#define HEADER2 "----------|-------"

void OUTPrint_Word_Table() {
   acc_word_table awt = WTCreate();
    
   acc_wtab_entry awe;

   if (WTNo_Entry(awt) == NO) return;
   
   printf("%s\n%s\n", HEADER1, HEADER2);
   WTSetSearch(awt);
   while ((awe = WTNext(awt)) != Null_Word_Table_Entry) {
      printf("%-10s|  %3d\n", WTEWord(awe), WTEFreq(awe));
   }
}
