/* Author: Fulvio Frapolli, University of Fribourg, July 2007 */

#include <stdio.h>
#include <string.h>

/* reverse: reverse string s  ---  kr62 */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}


main()
{
    char s[100];
    scanf("%s",s);
    reverse(s);
    printf("%s\n",s);
}
