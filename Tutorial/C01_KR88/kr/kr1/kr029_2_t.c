/* Character Arrays - KR chap. 1.9 */
/* Beat Hirsbrunner, University of Fribourg, January 2008 */

#include <stdio.h>
#include <string.h>  // strlen
#define MAXLINE 10 /* maximum input line size: vary its size in order to test getline! */

int getline(char *line, int lim);

/* -------------------- */
/* getline test program */
/* -------------------- */
int main() {
  char str[MAXLINE]; int length;
	
  while ((length = getline(str, MAXLINE)) > 0) {  // getline
    if (str[strlen(str)-1]  == '\n')
      printf("%5d: %s", length, str);   // str is a line, ended with '\n'
    else
      printf("%5d: %s\n", length, str); // str is part of a line, not ended with '\n'
                                        // (for readability, add an extra '\n' to the output) 
  }
}


/* read a line or at most lim - 1 characters, and return its length  ---  kr29 */
int getline(char s[], int lim)
{
    int c, i;
	
    for (i = 0; i < lim-1 && (c = getchar())!= EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
