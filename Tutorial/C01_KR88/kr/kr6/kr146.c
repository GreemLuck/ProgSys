/* Compiled by Kathrin Meyer, University of Fribourg, July 2006 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

typedef struct tnode *Treeptr;

typedef struct tnode {	/* the tree node --- kr146 */
    char *word;     /* points to the next */
    int count;      /* number of occurrences */
    Treeptr left;   /* left child */
    Treeptr right;  /* right child */
} Treenode;

Treeptr addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

main() /* word frequency count --- kr140 */
{
    Treeptr root;
    char word[MAXWORD];
	
    root = NULL;
    while (getword(word, MAXWORD) != EOF)
	if (isalpha(word[0]))
	    root = addtree(root, word);
    treeprint(root);
    return 0;
}


/* ----------------------------------------- */
/* addtree, treeprint "module" --- kr141-142 */
/* ----------------------------------------- */

Treeptr talloc(void);	
char *my_strdup(char *);

/* addtree: add a node with w, at or below p --- kr141 */
Treeptr addtree(struct tnode *p, char *w)
{
    int cond;
	
    if (p == NULL) {    /* a new word has arrived */
	    p = talloc();   /* make a new node */
	    p->word = my_strdup(w);
	    p->count = 1;
	    p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
	    p->count++;     /* repeated word */
    else if (cond < 0)  /* less than into left subtree */
	    p->left = addtree(p->left, w);
    else                /* greater than into right subtree */
	    p->right = addtree(p->right, w);
    return p;
}

/* treeprint: in-order print of tree p --- kr142 */
void treeprint(struct tnode *p)
{
    if (p != NULL) {
	    treeprint(p->left);
	    printf("%4d %s\n", p->count, p->word);
	    treeprint(p->right);
    }
}


/* ---------------------------------------- */
/* talloc, my_strdup "module" --- kr142-143 */
/* ---------------------------------------- */

/* talloc: make a tnode --- kr142 */
Treeptr talloc(void)
{
  return (Treeptr) malloc(sizeof(Treenode));
}

char *my_strdup(char *s) /* make a duplicate of s --- kr143 */
{
    char *p;
	
    p = (char *) malloc(strlen(s)+1);	/* +1 for '\0' */
    if (p != NULL)
	    strcpy(p,s);
    return p;
}


/* -------------------------------- */
/* getch, ungetch "module" --- kr79 */
/* -------------------------------- */

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


/* getword: get next word or character from input --- kr136 */
int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;
	
    while (isspace(c = getch()))
	;
    if (c != EOF)
	*w++ = c;
    if (!isalpha(c)){
	*w = '\0';
	return c;
    }
    for ( ; --lim > 0; w++)
	if (!isalnum(*w = getch())) {
	    ungetch(*w);
	    break;
	}
    *w = '\0';
    return word[0];
}



	
