#include <list.h>
#include <stdio.h>

int main()
{
  item_type d;
  int s = 0;

  list l1 = ListCreate(), l2 = ListCreate(), l3 = ListCreate(), l;
  acc_node n;


  /*  while (scanf("%d", &d) != EOF) { */
  while (scanf("%d", &d) != EOF) {
    l1 = ListAppend(l1, d); l2 = ListPrepend(l2, d);
    if (s == 0) {
      l3 = ListAppend(l3, d); s = 1;
    }
    else {
      l3 = ListPrepend(l3, d); s = 0;
    }
  }

  printf("Print out l1\n");
  ListPrint(l1); putchar(0x0a);

  printf("Print out l2\n");
  ListPrint(l2); putchar(0x0a);

  printf("Print out l3\n");
  ListPrint(l3); putchar('\n');

  printf("Sorting l3.\n");
  ListSort(l3);
  ListPrint(l3); putchar('\n');

  for (l = l1; ListIs_Null(l) == NO; l = ListRm_Head(l)) {
     ListPrint(l); putchar(0x0a);
  }

  for (l = l2; ListIs_Null(l) == NO; l = ListRm_Tail(l)) {
     ListPrint(l); putchar(0x0a);
  }
}
