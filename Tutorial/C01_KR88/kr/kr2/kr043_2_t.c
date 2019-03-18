/* Author:  Fulvio Frapolli, University of Fribourg, July 2007 */

#include <stdio.h>

/* lower: convert c to lower case; ASCII only  ---  kr43 */
int lower(int c)
{
	if (c >= 'A' && c <='Z')
		return c + 'a' - 'A';
	else
		return c;
}

int main()
{
	char c;
	
	scanf("%c", &c);
	printf("%c\n", lower(c));
}
