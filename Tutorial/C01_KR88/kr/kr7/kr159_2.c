/* Formatted Input - scanf - KR chap. 7.4 */

/* Kathrin Meyer, University of Fribourg, July 2006 */
/* revised by Beat Hirsbrunner, University of Fribourg, January 2008 */

#include <stdio.h>

int getline(char line[], int max);

main()  /* --- kr159, slightly modified by BH */
{
  int day, month, year;
  char monthname[20];
  char line[50]; 
  
  printf("> Insert a date (of form 28 Dec 1988 or mm/dd/yy)\n> ");
  while (getline(line, sizeof(line)) > 0) {
    if (sscanf(line, "%d %s %d", &day, monthname, &year) == 3)
      printf("valid: %d %s %d\n", day, monthname, year); /* 25 Dec 1988 form */
    else if (sscanf(line, "%d/%d/%d", &month, &day, &year) == 3)
      printf("valid: %d %d %d\n", month, day, year);     /* mm/dd/yy form */
    else
      printf("invalid: %s", line);  /*invalid form */
    printf("> ");
  }
}

/* getline: get line into s, return length --- kr69 */
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

 
