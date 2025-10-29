#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct pat_w_shift_value_ {
   char *pattern;
   int patLen;
   int  *shiftValue;
};
typedef struct pat_w_shift_value_ pat_w_shift_value, *acc_pwsv;

pat_w_shift_value *PWSVCreate(char *p) {
   acc_pwsv pp;
   pp = (acc_pwsv) malloc(sizeof(pat_w_shift_value));
   pp->pattern = p;
   pp->patLen = strlen(p);
   pp->shiftValue = (int *) malloc(pp->patLen * sizeof(int));

   return pp;
}

void PWSVCalc_Shift_Value(pat_w_shift_value *p) {
   int j, k;
   j = 0; k = -1; p->shiftValue[0] = -1;
   while (j < p->patLen - 1) {
      while ((k >= 0) && p->pattern[j] != p->pattern[k]) {
	 k = p->shiftValue[k];
      }
      ++j; ++k;
      if (p->pattern[j] == p->pattern[k])
	 p->shiftValue[j] = p->shiftValue[k];
      else
	 p->shiftValue[j] = k;
   }
}

void PWSVPrint(pat_w_shift_value *p) {
   int y;
   for (y = 0; y < p->patLen; ++y) {
      printf ("  %c ", p->pattern[y]);
   }
   printf("\n");
   for (y = 0; y < p->patLen; ++y) {
      printf (" % d ", p->shiftValue[y]);
   }
   printf("\n");
}

void PWSVFree(acc_pwsv ap) {
   free((void *) ap->shiftValue);
   free((void *) ap);
}

int kmp_Search(char * s, char *p) {
   acc_pwsv pp;
   int *d, i, j, M, N;

   pp = PWSVCreate(p);
   PWSVCalc_Shift_Value(pp);
   d = pp->shiftValue;

   printf("Shift Values:\n");
   PWSVPrint(pp);

   M = strlen(p); N = strlen(s);
   i = j = 0;
   while (j < M && i < N) {
     while(j >= 0 && s[i] != p[j]) j = d[j];
     ++i; ++j;
   }
   PWSVFree(pp);

   if (j == M) return i-j; else return -1;
}

const int sourceSize = 256;
const int patternSize = 32;

int main() {
   int y, mpos; char c;
   char s[sourceSize + 1], p[patternSize + 1];

   printf("Source String? ");
   y = 0;
   while ((c = getchar()) != EOF && (y < sourceSize)) {
     if (c == '\n') break;
     s[y++] = c;
   }
   s[y] = (char) 0;
   
   printf("Pattern String? ");
   y = 0;
   while ((c = getchar()) != EOF) {
     if (c == '\n') break;
     p[y++] = c;
   }
   p[y] = (char) 0;

   mpos = kmp_Search(s, p);
   printf("Source:  %s\n", s);
   printf("Pattern: %s\n", p);
   if (mpos == -1)
      printf("Pattern not found.\n");
   else
     printf("Pattern found at the position of %d.\n", mpos);
}
