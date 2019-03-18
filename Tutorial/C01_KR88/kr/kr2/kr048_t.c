/* Authors: Fulvio Frapolli and Beat Hirsbrunner, University of Fribourg, July 2007 */

#include <stdio.h>

/* my_strcat: concatenate t to end of s --- kr48 */
void my_strcat(char s[], char t[])
{
  int i, j;

  i = j = 0;
  while (s[i] != '\0') /* find end of s */
    i++;
  while ((s[i++] = t[j++]) != '\0') /* copy t */
    ;
}

main() 
{
  char s[100], t[100];

  scanf("%s %s",s,t);
  my_strcat(s, t);
  printf("%s\n", s);
}
