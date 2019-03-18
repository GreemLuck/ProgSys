// Fulvio Frapolli and Beat Hirsbrunner, University of Fribourg, Jan. 2008

#include <stdio.h>
#include <ctype.h>

#define MAXOP 100   /* max size of an operand or operator */
#define MAX 100     /* max size of buffer */
#define NUMBER '0'  /* signal that a number was found */

int getop(char s[]);


main() { // Test progam
	int type;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		if (type == '+' || type == '-' || type == '*' || type == '/' || type == '%')
			printf("This is an operator: %c\n", type);
		else if (type == NUMBER) 
			printf("This is an operand: %s\n", s);
		else if (type != '\n')
			printf("This is an invalid character: %c\n",type);
	}
}


/* ----------------------------------- */
/* getop "module" --------------- kr78 */
/* ----------------------------------- */

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand --- kr78 */
int getop(char s[]) {
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c; /* not a number */
	i = 0;
	if (isdigit(c)) /* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.') /* collect fraction part */
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

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character --- kr79 */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input --- kr79 */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}