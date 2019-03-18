/* Author: Beat Hirsbrunner, University of Fribourg, January 2008 */

#include <stdio.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};


/* month_day: set month, day from day of year  ---  kr111 */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for ( i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}

main()
{
	int year, yearday, m, d;

	scanf("%d %d", &year, &yearday);
	month_day(year, yearday, &m, &d);
	printf("month = %d, day = %d\n", m, d);
}