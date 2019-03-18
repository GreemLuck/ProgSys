/* Authors: Fulvio Frapolli and Beat Hirsbrunner, University of Fribourg, July 2007 */

#include <stdio.h>

/* my_strlen: return length of s; Kernighan-Ritchie, p. 39 */
int my_strlen(char s[])
{
  int i;

  i = 0;
  while(s[i] != '\0')
    ++i;
  return i;
}


main()
{
	char s[100];
	
	scanf("%s", s);
	printf("%d\n", my_strlen(s));
}


