#include <stdio.h>

/* ----------------------------------- */
/* Stack "module" --------------- kr77 */
/* ----------------------------------- */

#define MAXVAL 100	 /* maximum depth of val stack */

int    sp = 0;		 /* next free stack position */
double val[MAXVAL];	 /* value stack */

/* push: push f onto value stack --- kr77 */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;

    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack --- kr77 */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

