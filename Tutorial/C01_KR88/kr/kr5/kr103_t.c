/* Author: Beat Hirsbrunner, University of Fribourg, July 2007 */

#include <stdio.h>

#define MAX 10  // maximum length of a string

/* strlen: return length of string s --- kr103 */
int my_strlen(char *s)
{
	char *p = s;
	
	while (*p != '\0')
		p++;
	return p - s;
}

main()
{
	int i = 0;
	char c, s[MAX+1];

	while (i < MAX  &&  (c = getchar()) != '\n')  s[i++] = c;
	s[i] = '\0';

	printf("The length of the input string is %d\n", my_strlen(s));
}
