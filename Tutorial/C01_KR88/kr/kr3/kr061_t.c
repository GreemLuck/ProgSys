/* Author: Fulvio Frapolli, University of Fribourg, July 2007 */

#include <stdio.h>

/* atoi: convert s to integer; version 2  ---  kr61 */
int my_atoi2(char s[])
{
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++)	/* skip with space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')	/* skip again */
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}

main()
{
    char s[100];
    scanf("%s",s);
    printf("%d\n", my_atoi2(s) + 1);
}
