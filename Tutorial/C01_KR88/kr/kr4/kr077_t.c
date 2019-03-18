// Fulvio Frapolli and Beat Hirsbrunner, University of Fribourg, Jan. 2008

#include <stdio.h>
#include <ctype.h>

void push(double f);
double pop(void);


/* -----------------------------------*/
/* Test progam for push/pop functions */
/* -----------------------------------*/

void print_usage()
{
  printf("push/pop usage:  p)push(f)  o)pop\n");
  printf("Test program usage: H)Help  Q)Quit\n");
}


main(){
  char c; 
  double v;

  char *prompt = ">";

  print_usage();
  printf("%s", prompt);

  while (c = getchar()) { // main loop
    switch(c) {

      case 'p': // push
        scanf("%lf", &v);
        push(v);
        printf("the following element has been added: %lf\n", v);
        break;

      case 'o': // pop
        v = pop();
        printf("the top element has been removed: %lf\n", v);
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



/* ----------------------------------- */
/* Stack "module" --------------- kr77 */
/* ----------------------------------- */
#define MAXVAL 100   /* maximum depth of val stack */

int   sp = 0;        /* next free stack position */
double val[MAXVAL];  /* value stack */


/* push: push f onto value stack --- kr77 */
void push(double f)
{
  if (sp < MAXVAL)
      val[sp++] = f;
  else
      printf("error: stack full, can't push %g\n", f);
}


/* pop: pop and return top value from stack --- kr77 */
double pop(void)
{
  if (sp > 0)
      return val[--sp];
  else {
      printf("error: stack empty\n");
      return 0.0;
  }
}
