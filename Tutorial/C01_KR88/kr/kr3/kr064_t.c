/* Author: Fulvio Frapolli, University of Fribourg, July 2007 */

#include <stdio.h>
#include <string.h> // strlen

void reverse(char s[]); // needed by my_itoa

/* itoa: convert n to characters in s --- kr64 */
void my_itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)	/* record sign */
        n = -n;		/* make n positive */
    i = 0;
    do {		/* generate digits in reverse order */
        s[i++] = n % 10 + '0';	/* get next digit */
    } while ((n /= 10) > 0);	/* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

main()
{
  int n;  char s[100];
  
  scanf("%d",&n);	
  my_itoa(n,s);
  printf("%s\n", s);
}


//-------------------------------------------------------
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}