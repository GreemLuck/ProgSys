#include <stdio.h>

/* ------------------------------------------- */
/* getch_ungetch "module" --------------- kr79 */
/* ------------------------------------------- */

#define BUFSIZE 100

char buf[BUFSIZE];	/* buffer for ungetch */
int bufp = 0;		/* next free position in buf */

int getch(void)	/* get a (possibly pushed back) character --- kr79 */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)	/* push character back on input --- kr79 */
{
    if ( bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
