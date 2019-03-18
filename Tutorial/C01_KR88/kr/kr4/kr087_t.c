/* Author: Beat Hirsbrunner, University of Fribourg, July 2007 */

#include <stdio.h>

/* printd: print n in decimal  ---  kr87 */
void printd(int n)
{
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10)
        printd(n / 10);
    putchar(n % 10 + '0');
}

main()
{
    int n;
    scanf("%i", &n);
	
    /* print the integer n recursively */
    printd(n); 
	
    printf("\n");
}
