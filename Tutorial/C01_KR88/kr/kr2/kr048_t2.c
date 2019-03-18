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
  char c, s[100], t[100];
  int i;
  
  i=0;
  while ((c=getchar()) != '\n') 
     s[i++] =c; 
  s[i]='\0';

  i=0;
  while ((c=getchar()) != '\n') 
     t[i++] =c; 
  t[i]='\0';
  
  my_strcat(s, t);
  printf("%s\n", s);
}
