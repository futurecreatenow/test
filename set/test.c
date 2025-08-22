/*
   character frequency counting
*/

#include <stdio.h>
#include <mydef.h>
#include <heap.h>
#include <set.h>

/* main function for character frequency counting */

#define PROMPT "Which key, c for character, frequency otherwise? "

int main() {
   acc_set s1, s2; 
   
   HPInit(); /* initialize heap */

   s1 = SetCreate(); s2 = SetCreate();

   int y;
   for (y = 0; y < 3; ++y) {
      SetAdd(s1, y);
      printf("%d is put into Set 1.\n", y);
   }
   
   for (y = 1; y < 4; ++y) {
      SetAdd(s2, y);
      printf("%d is put into Set 2.\n", y);
   }

   SetDump(s1, "Set 1");
   SetDump(s2, "Set 2");

   set s;
   s = SetUnion(s1, s2);
   SetDump(&s, "Union");

   s = SetIntersection(s1, s2);
   SetDump(&s, "Intersection");

   s = SetDifference(s1, s2);
   SetDump(&s, "Difference");
   
   return 0;
}
