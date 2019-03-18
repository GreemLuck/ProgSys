/* Authos: Fulvio Frapolli and Beat Hirsbrunner, University of Fribourg, July 2007 */

#include <stdio.h>

/* my_atoi: convert s to integer --- kr43 */
int my_atoi(char s[])
{
  int i, n;

  n = 0;
  for(i=0; s[i] >= '0' && s[i] <= '9'; ++i)
    n = 10 * n + (s[i] - '0');
  return n;
}

main()
{
   char s[100];
   
   scanf("%s",s);
   printf("%d\n", my_atoi(s) + 1);
}
