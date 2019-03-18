/* Author: Beat Hirsbrunner, University of Fribourg, July 2007 */

#include <stdio.h>

#define MAX 1000

/* my_strcpy: copy t to s: array subscript version --- kr105 */
void my_strcpy(char *s, char *t)
{
	int i;

	i = 0;
	while ((s[i] = t[i]) != '\0')
	    i++;
}

/* my_strcpy1: copy t to s: pointer version --- kr105 */
void my_strcpy1(char *s, char *t)
{
	while ((*s = *t) != '\0') {
		s++;
		t++;
	}
}

/* my_strcpy2: copy t to s: pointer version 2 --- kr105 */
void my_strcpy2(char *s, char *t)
{
	while ((*s++ = *t++) != '\0')
        ;
}

/* my_strcpy3: copy t to s: pointer version 3 --- kr106 */
void my_strcpy3(char *s, char *t)
{
	while (*s++ = *t++)
		;
}

main()
{
	int i = 0;
	char c, s[MAX], t[MAX];

	while ((c = getchar()) != '\n') 
	   t[i++] = c;
	t[i] = '\0';

	printf("\n");
	my_strcpy(s,t);  printf("%s\n", s);
	my_strcpy1(s,t); printf("%s\n", s);
	my_strcpy2(s,t); printf("%s\n", s);
	my_strcpy3(s,t); printf("%s\n", s);
}
