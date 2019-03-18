#include <stdio.h>

/* copy input to output; 2nd version  ---  kr17 */
main()
{
    int c;

    while ((c = getchar()) != EOF)
        putchar(c);
}
