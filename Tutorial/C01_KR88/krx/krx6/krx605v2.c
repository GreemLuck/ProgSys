/*--------------------------------------------------------------------------
K&R, pages 144

(in order to be able to compile Gregory's solution, added by B. Hirsbrunner) 
--------------------------------------------------------------------------*/

#include <stdlib.h>

struct nlist { /* table entry: */
    struct nlist *next; /* next entry in chain */
    char *name;	        /* defined name */
    char *defn;	        /* replacement text */
};

#define HASHSIZE 10

static struct nlist *hashtab[HASHSIZE];	/* pointer table */

/* hash: form hash value for string s */
unsigned hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
	hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}



/*----- Gregory Pietsch -----*/

void undef(char *s)
{
    struct nlist *np1, *np2;
    unsigned hashval = hash(s);

    for (np1 = hashtab[hashval], np2 = NULL; 
         np1 != NULL;
         np2 = np1, np1 = np1->next) 
        if (strcmp(s, np1->name) == 0) {
            /* found a match */
            free(np1->name);
            free(np1->defn);
            if (np2 == NULL) 
                /* at the beginning? */
                hashtab[hashval] = np1->next;
            else 
                /* in the middle or at the end? */
                np2->next = np1->next;
            free(np1);
            return;
        }
}

