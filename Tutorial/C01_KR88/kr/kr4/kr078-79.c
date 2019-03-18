#include <stdio.h>
#define NUMBER '0'	/* signal that a number was found */


/* ----------------------------------- */
/* getop "module" --------------- kr78 */
/* ----------------------------------- */

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand --- kr78 */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;		/* not a number */
    i = 0;
    if (isdigit(c))		/* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')		/* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}


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
