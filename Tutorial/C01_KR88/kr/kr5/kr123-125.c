/* ---------------------------------------------------------- */
/* Convert C declaration to word description (declare - dcl)  */
/*                                                            */
/* Reference: Kernighan-Ritchie, 1988, section 5.12           */
/* ---------------------------------------------------------- */

// Compiled by Michael Kaufmann, University of Fribourg, March 2004
// Revised by Beat Hirsbrunner, University of Fribourg, January 2008


/* ----------------------------------------------- */
/* global variables "module" --------------- kr124 */
/* ----------------------------------------------- */
#include <stdio.h>   // EOF, getchar, printf
#include <string.h>  // strcat, strcpy
#include <ctype.h>   // isalpha

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);

int gettoken(void);
int tokentype;            /* type of last token */
char token[MAXTOKEN];     /* last token string */
char name[MAXTOKEN];      /* identifier name */
char datatype[MAXTOKEN];  /* data type = char, int, etc. */
char out[1000];           /* output string */


/* ----------------------------------------- */
/* get/ungetch "module" --------------- kr79 */
/* ----------------------------------------- */
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


/* --------------------------------------- */
/* gettoken "module" --------------- kr125 */
/* --------------------------------------- */
int gettoken(void)	/* return next token --- kr125 */
{
	int c, getch(void);
	void ungetch(int);
	char *p = token;

	while ((c = getch()) == ' ' || c == '\t')
		;
	if (c == '(') {
		if ((c = getch()) == ')') {
			strcpy(token, "()");
			return tokentype = PARENS;
		} else {
			ungetch(c);
			return tokentype = '(';
		}
	} else if (c == '[') {
		for (*p++ = c; (*p++ = getch()) != ']'; )
			;
		*p = '\0';
		return tokentype = BRACKETS;
	} else if (isalpha(c)) {
		for (*p++ = c; isalnum (c = getch()); )
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	} else
		return tokentype = c;
}

/* ----------------------------------------------- */
/* decl/dirdecl "module" --------------- kr123-124 */
/* ----------------------------------------------- */
void dcl(void) /* dcl: parse a declarator --- kr123 */
{
	int ns;
	
	for (ns = 0; gettoken() == '*'; )	/* count *'s */
		ns++;
	dirdcl();
	while (ns-- > 0)
		strcat(out, "pointer to ");
}

void dirdcl(void) /* dirdcl: parse a direct declarator --- kr124 */
{
	int type;

	if (tokentype == '(') {		/* (dcl) */
		dcl();
		if (tokentype != ')')
			printf("error: missing )\n");
		} else if (tokentype == NAME)		/* variable name */
			strcpy(name, token);
		else
			printf("error: expected name or (dcl)\n");
		while ((type = gettoken()) == PARENS || type == BRACKETS)
			if (type == PARENS)
				strcat(out, " function returning ");
			else {
				strcat(out, " array");
				strcat(out, token);
				strcat(out, " of");
			}
}


/* ----------------------------------------- */
/* Main test program ----------------- kr125 */
/* ----------------------------------------- */
main() /* dcl: Convert C declaration to word description --- kr125 */
{
	while (gettoken() != EOF) {    /* 1st token on line */
		strcpy(datatype, token);   /* is the datatype */
		out[0] = '\0';
		dcl();      /* parse rest of line */
		if (tokentype != '\n')
			printf("syntax error\n");
		printf("%s: %s %s\n", name, out, datatype);
	}
	return 0;
}





