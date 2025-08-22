#include <stdio.h>
#include <stdlib.h>

#include <mydef.h>

#include <heap.h>

#include <set_ds.h>

/*	create an instance of set				        */

acc_set SetCreate() {
   acc_set s;
   s = (acc_set) HPAlloc(HPCreate(), sizeof(set));
   s->noMembers = 0;

   return s;
}

/*	function to check if the given item is a member of the set	*/

static int is_Member_Of(acc_set s, MEMBER_TYPE m) {
   int y;

   for (y = 0; y < s->noMembers; ++y) if (s->set[y] == m) return y;

   return error;
}

/*	function to check if the given item is a member of the set	*/

boolean SetIs_Member_Of(acc_set s, MEMBER_TYPE m) {
   if (is_Member_Of(s, m) == error) return NO;
   else return YES;
}

/*	procedure to set up for scannning	                        */

void SetScanning(acc_set s) { s->scanningPosition = 0; }

/*	procedure to proceed scannning position	                        */

void SetProceed_Scanning_Position(acc_set s) { ++s->scanningPosition; }

/*	function to get a member currently scanning                     */

MEMBER_TYPE SetGet_Current_Member(acc_set s) {
   if (s->scanningPosition >= s->noMembers)
      return (MEMBER_TYPE) error;
   else
      return s->set[s->scanningPosition];
}

/*	procedure to add an element into set				*/

void SetAdd(acc_set s, MEMBER_TYPE m) {
   if (SetIs_Member_Of(s, m) == YES) return;

   if (s->noMembers >= max_No_Set_Members) {
      fprintf(stderr, STRFMT, "Storage overflow inside a set.");
      exit(error);
   }
   else
      s->set[s->noMembers++] = m;
   return;
}

/*	procedure to remove an element from a set			*/

void SetRemove(acc_set s, MEMBER_TYPE m) {
   int y;

   if ((y = is_Member_Of(s, m)) == error) return;
   else {
      while (y < s->noMembers) {
	 s->set[y] = s->set[y + 1];
	 ++y;
      }
      --s->noMembers;
      return;
   }
}

/*	function to check if the set is empty   			*/

boolean SetIs_Empty(acc_set s) { return (s->noMembers == 0) ? YES : NO; }

/*	function to get the number of element of a given set    	*/

int SetNumber_of_Members(acc_set s) { return s->noMembers; }

/*      procedure to copy a set                                         */
/*
void copy_set(acc_set d, acc_set s) {
   d = SetCreate();
   d->noMembers = s->noMembers;
   d->scanningPosition = s->scanningPosition;
   int y;
   for (y = 0; y < s->noMembers; ++y) d->set[y] = s->set[y];
}
*/

/*	function to calculate a union of sets   			*/

set SetUnion(acc_set thisSet, acc_set thatSet) {
   set solSet; acc_set r;MEMBER_TYPE m;

   for (SetScanning(thisSet), solSet.noMembers = 0;
	(m = SetGet_Current_Member(thisSet)) != (MEMBER_TYPE) error;
	SetProceed_Scanning_Position(thisSet)) {
      SetAdd(&solSet, m);
   }
   
   for (SetScanning(thatSet);
	(m = SetGet_Current_Member(thatSet)) != (MEMBER_TYPE) error;
	SetProceed_Scanning_Position(thatSet)) {
      if (SetIs_Member_Of(&solSet, m) == NO) SetAdd(&solSet, m);
   }
   return solSet;
}

/*	function to check if the set is empty   			*/
set SetIntersection(acc_set thisSet, acc_set thatSet) {
   set solSet; MEMBER_TYPE m;

   for (SetScanning(thisSet), solSet.noMembers = 0;
	(m = SetGet_Current_Member(thisSet)) != (MEMBER_TYPE) error;
	SetProceed_Scanning_Position(thisSet)) {
      if (SetIs_Member_Of(thatSet, m) == YES) SetAdd(&solSet, m);
   }
   return solSet;
}

/*	function to check if the set is empty   			*/

set SetDifference(acc_set thisSet, acc_set thatSet) {
   set solSet; MEMBER_TYPE m;

   for (SetScanning(thisSet), solSet.noMembers = 0;
	(m = SetGet_Current_Member(thisSet)) != (MEMBER_TYPE) error;
	SetProceed_Scanning_Position(thisSet)) {
      if (SetIs_Member_Of(thatSet, m) == NO) SetAdd(&solSet, m);
   }
   return solSet;
}

/* procedure to dump out a set */

void SetDump(acc_set s, string head) {
  int y, n;
   printf("Dump of %s: ", head);
   for (y = 0, n = SetNumber_of_Members(s), SetScanning(s); y < n;
        ++y, SetProceed_Scanning_Position(s)) {
      MEMBER_TYPE m;
      m = SetGet_Current_Member(s);
      printf("%d ", m);
   }
   printf("\n");
}

