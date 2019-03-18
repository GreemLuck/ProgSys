/* Author:  Fulvio Frapolli and Beat Hirsbrunner, University of Fribourg, July 2007 */

#include <stdio.h>

/* squeeze: delete all c from s --- kr47 */
void my_squeeze(char s[], int c)
{
  int i, j;

  for (i = j = 0; s[i] !='\0'; i++)
    if (s[i] != c)
      s[j++] = s[i];
  s[j] = '\0';
}

int main()
{
	char s[100], c;
	
	scanf("%s %c", s, &c);
	my_squeeze(s, c);
	printf("%s\n", s);
}
