#include <stdio.h>

/* count characters in input; 1st version  ---  kr18 */
main()
{
  long nc;

  nc = 0;
  while (getchar() != EOF)
    ++nc;
  printf("%ld\n", nc);
}


