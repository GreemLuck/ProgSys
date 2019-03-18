/* Formatted Input - scanf - KR chap. 7.4 */

/* Beat Hirsbrunner, University of Fribourg, July 2006 */

#include <stdio.h>

main()  /* --- kr159 */
{
    int day, month, year;
    char monthname[20];
    char line[50]; 

    printf("> Insert a date of the form 28 Dec 1988: ");
    scanf("%d %s %d", &day, monthname, &year);
    printf("%d %s %d\n", day, monthname, year); /* 25 Dec 1988 form */
	
    printf("> Insert a date of the form mm/dd/yy: ");
    scanf("%d/%d/%d", &month, &day, &year);
    printf("%d %d %d\n", month, day, year); /* mm/dd/yy form */
}

