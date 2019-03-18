/* Author: Beat Hirsbrunner, University of Fribourg, July 2007 */

#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn  ---  kr97 */
/* and return -1 on EOF, 0 if the readed input is not a number, and a positive number otherwise */
int getint(int *pn)
{
	int c, sign;
	
	while (isspace(c = getch()))	/* skip with space */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-')
	{
		ungetch(c);	/* it's not a number */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

#define SIZE 7

main()
{
    int array[SIZE];
    int i, max, res;

    /* Read input */
    for (max=0; 
         max < SIZE && (res = getint(&array[max])) != EOF && res != 0; 
         max++)
        ;

    printf("Readed integers: \n");
    for (i=0; i < max; i++) printf("%d\n", array[i]);
    printf("last return value of getint: %d\n", res);
}



/* ------------------------------------------- */
/* getch_ungetch "module" --------------- kr79 */
/* ------------------------------------------- */

#define BUFSIZE 100

char buf[BUFSIZE];	/* buffer for ungetch */
int bufp = 0;		/* next free position in buf */


int getch(void)	/* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)	/* push character back on input */
{
    if ( bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

