/* Author: Fulvio Frapolli, Univerity of Fribourg, July 2007 */

#include <stdio.h>
#include <string.h>
#define MAXLINE 100

/* trim: remove trailing blanks, tabs, newlines --- kr65 */
int my_trim(char s[])
{
    int n;

    for (n = strlen(s)-1; n >= 0; n--)
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
            break;
    s[n+1] = '\0';
    return n;
}

/* getline: read a line into s, return length --- kr29 */
int getline(char s[], int lim)
{
    int c, i;
    i = 0;

    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

main()
{
    char line[MAXLINE];

    while(getline(line,MAXLINE)>0){
       my_trim(line);
       printf("%s%c\n", line,'$'); 
    }
}
