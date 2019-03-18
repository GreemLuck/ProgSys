/* Author: Beat Hirsbrunner, University of Fribourg, January 2008 */

#include <stdio.h>

/* month_name: return name of n-th month  ---  kr113 */
char *month_name(int n)
{
    static char *name[] = {
		"Illegal month",
		"January", "February", "March",
		"April", "May", "June",
		"July", "August", "September",
		"October", "November", "December"
    };


    return (n < 1 || n > 12) ? name[0] : name[n];
}

main()
{
    int n;

    scanf("%d", &n);
    printf("%s\n", month_name(n));
}
    
