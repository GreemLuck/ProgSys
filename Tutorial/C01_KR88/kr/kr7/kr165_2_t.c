/* Line Input and Output - KR chap. 7.7 */
/* Beat Hirsbrunner, University of Fribourg, January 2008 */

#include <stdio.h>
#include <stdlib.h>  // atoi
#include <string.h>  // strlen

#define MAX 1000 // big enough

int getline(char *line, int max);

/* -------------------- */
/* getline test program */
/* -------------------- */
int main(int argc, char *argv[]) {
  char str[MAX]; int length, max;
  
  max = atoi(argv[1]);
  
  if (argc != 2 && max > MAX) {  // error treatment
    printf("Usage: %s n (with n < %d)\n", argv[0], MAX);
    return -1;
  }
  
  while ((length = getline(str, max)) > 0) {  // getline
    if (str[strlen(str)-1]  == '\n')
      printf("%5d: %s", length, str);   // str is a line, ended with '\n'
    else
      printf("%5d: %s\n", length, str); // str is part of a line, not ended with '\n'
                                        // (for readability, add an extra '\n' to the output) 
  }
}


/* read a line or at most max-1 characters, and return its length  ---  kr165 */
int getline(char *line, int max) {
  if (fgets(line, max, stdin) == NULL)
    return 0;
  else
    return strlen(line);
}