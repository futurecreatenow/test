/*
   string frequency counting
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <mydef.h>
#include <local.h>

#include <heap.h>

#include <token.h>
#include <word_stm.h>
#include <digits_stm.h>
#include <com_args.h>
#include <string_input_device.h>

#include <word_table.h>
#include <wtab_entry.h>
#include <out.h>


static boolean eofReached;

/* main  function for word frequency counting */

#define PROMPT "Which key, w for word, frequency otherwise? "

int main(int noComArgs, string ComArgs[]) {
   sort_key sKey; acc_word_table awt; 

   string w;
   acc_com_args aca;
   string words[128];
   int nw = 0, y;
   acc_string_input_device inDev;
   FILE *inFile;
   acc_stm wordSTM, digSTM;

   static const int no_STMs = 2, word_STM_No = 0, dig_STM_No = 1;

   HPInit(); /* initialize heap */

   /* command argument processing */
   aca = CACreate(noComArgs, ComArgs);
   inFile = CAOpen_Nth_Arg(aca, 1, READMODE);
   inDev = SIDCreate(inFile, no_STMs);

   /* open string input device */
   SIDPut_STM(inDev, WSCreate(), word_STM_No);
   SIDPut_STM(inDev, DIGCreate(), dig_STM_No);
   
   WTInit(); /* word table initialization */
   awt = WTCreate();
   
   /* set soprt key */
   fprintf(stderr, PROMPT);
   if (getchar() == 'w') sKey = BY_STRING; else sKey = BY_FREQ;

   /* read string and put it into the table */
   while ((w = SIDGet_Token(inDev)) != NULLS)  WTPut(awt, w);

   /* sort'em */
   WTSort(awt, sKey);

   /* print'em out */
   OUTPrint_Word_Table();
   
   WTFree();
   fclose(inFile);

   return 0;
}
