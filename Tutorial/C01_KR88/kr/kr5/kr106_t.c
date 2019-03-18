/* Author: Beat Hirsbrunner, University of Fribourg, July 2007 */

#include <stdio.h>

#define MAX 100

/* my_strcmp: return <0 if s<t, 0 if s==t, >0 if s>t  ---  kr106 */
int my_strcmp(char *s, char *t)
{
	int i;

	for(i = 0; s[i] == t[i]; i++)
		if(s[i] == '\0')
			return 0;
	return s[i] - t[i];
}

/* my_strcmp2: return <0 if s<t, 0 if s==t, >0 if s>t  ---  kr106 */
int my_strcmp2(char *s, char *t)
{
	for(; *s == *t; s++, t++)
		if(*s == '\0')
			return 0;
	return *s - *t;
}

main()
{
	char s[MAX], t[MAX];
	
	scanf("%s %s",s,t);
	printf("%d\n", my_strcmp(s,t));
	printf("%d\n", my_strcmp2(s,t));	
}
