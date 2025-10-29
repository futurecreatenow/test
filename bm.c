#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char *string;

int d[0x80];

void set_Distance(string p) {
  int l = strlen(p), y;
  for (y = 0; y <= 0x7f; ++y) d[y] = l;
  for (y = 0; y <= l - 2; ++y) d[p[y]] = l - y -1;
}

void print_Distance(string p) {
   int y, l;

   l = strlen(p);
   for (y = 0; y < l; ++y) {
      printf ("  %c ", p[y]);
   }
   printf("\n");
   for (y = 0; y < l; ++y) {
      printf (" % d ", d[p[y]]);
   }
   printf("\n");
}

int bm_Search(string s, string p) {
  int M, N, i, j, k;

   set_Distance(p);
   print_Distance(p);

   M = strlen(p); N = strlen(s);
   
   i = M;
   do {
      j = M; k = i;
      do {
	 --k; --j;
      } while (j >= 0 && p[j] == s[i]);
      i += d[s[i - 1]];
   } while (j >= 0 && i < N) ;

   if (j < 0) return i - strlen(p); else return -1;
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

   mpos = bm_Search(s, p);
   printf("Source:  %s\n", s);
   printf("Pattern: %s\n", p);
   if (mpos == -1)
      printf("Pattern not found.\n");
   else
     printf("Pattern found at the position of %d.\n", mpos);
}
