/*

  Exercise 5-3. Write a pointer version of the function my_strcat that we showed in 
                Chapter 2: my_strcat(s,t) copies the string t to the end of s.

  implementation from chapter 2:

/ * my_strcat:  concatenate t to end of s; s must be big enough * /
void my_strcat(char s[], char t[])
{
  int i, j;

  i = j = 0;
  while (s[i] != '\0')  / * find end of s * /
    i++;
  while ((s[i++] = t[j++]) != '\0')  / * copy t * /
    ;
}


  Author : Bryan Williams 

*/


/* my_strcat:  concatenate t to end of s; s must be big enough; pointer version */
void my_strcat(char *s, char *t)
{
  /* run through the destination string until we point at the terminating '\0' */ 
  while('\0' != *s)
  {
    ++s;
  }

  /* now copy until we run out of string to copy */
  while('\0' != (*s = *t))
  {
    ++s;
    ++t;
  }

}

#define DRIVER         6

#if DRIVER
#include <stdio.h>

int main(void)
{
  char S1[8192] = "String One";
  char S2[8192] = "String Two";


  printf("String one is (%s)\n", S1);
  printf("String two is (%s)\n", S2);
 
  my_strcat(S1, S2);
  printf("The combined string is (%s)\n", S1);

  return 0;
}

#endif


