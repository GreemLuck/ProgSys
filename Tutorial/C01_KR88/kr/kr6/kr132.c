/* Author: Fulvio Frapolli and Beat Hirsbrunner, University of Fribourg, January 2008 */

#include <stdio.h>

main() { /* --- kr132 : about the high precedence order of the operator -> */

  struct { 
    int len;
    char *str;
  } q, *p=&q;
  
  printf("> Insert an integer: ");
  scanf("%d", &p->len);      // equivalent to &(p->len)
  printf("%d\n", ++p->len);  // equivalent to ++(p->len)

}