// Beat Hirsbrunner and Fulvio Frapolli, University of Fribourg, Jan. 2008

#include <stdio.h>

int getch(void);
void ungetch(int c);



/* ----------------------------------------*/
/* Test progam for getch/ungetch functions */
/* ----------------------------------------*/

void print_usage()
{
  printf("getch/ungetch usage: g)getch([c])  u)ungetch(c)\n");
  printf("Test program usage:  H)Help  Q)Quit\n");
}

main(){
  char c;

  char *prompt = ">";

  print_usage();
  printf("%s", prompt);

  while (c = getchar()) { // main loop
    switch(c) {

      case 'g': // getch
        c = getch();  // read the next character from standard input
        printf("character readed by getch: %c\n", c);
        break;

      case 'u': // ungetch
        c = getchar();  // read the character to be pushed back
        ungetch(c);
        printf("character pushed back to the buffer by ungetch: %c\n", c);
        break;

      case 'H': // Help
        print_usage();
        break;

      case 'Q': // Quit
        return 0;

      default:
        print_usage();
        break;
    } // end switch

    while (getchar() != '\n') {} /* skip end of line */
    printf("%s", prompt);

  } // end main loop

}



/* ------------------------------------------- */
/* getch_ungetch "module" --------------- kr79 */
/* ------------------------------------------- */

#define BUFSIZE 5 

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

int getch(void)	/* get a (possibly pushed back) character --- kr79 */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)	/* push character back on input --- kr79 */
{
  if ( bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
