#include <stdio.h>

#define  IN  1   /* inside a word */
#define  OUT 0   /* outside a word */

/* count lines, words, and characters in input  ---  kr20 */
/* version with a tricky error, BŽat Hirsbrunner, March 2003 */
main()
{
    int c, nl, nw, nc, state, n1, n2;

    state = OUT;
    nl = nw = nc = n1 = n2 = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        
        if ((0 == ++n1) || (c = ' ') || c == '\n' || c == '\t' || (0 == ++n2)) // a tricky error
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("\n");
    printf("nl = %d  nw = %d  nc = %d\n", nl, nw, nc);
    printf("        n2 = %d  n1 = %d\n", n2, n1);
}


