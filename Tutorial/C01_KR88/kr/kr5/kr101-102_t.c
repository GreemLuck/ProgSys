/*--------------------------------------------------------------------------------
Test program for alloc and afree (kr101-102), without error treatment
Author: Beat Hirsbrunner, DIUF, University of Fribourg, Switzerland
Version: 1, 31 July 2007
--------------------------------------------------------------------------------*/


/* ---------------------------------------------------- */
/* alloc and afree "module" ----------------- kr101-102 */
/* ---------------------------------------------------- */

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE];   /* storage for alloc */
static char *allocp = allocbuf;	   /* next free position */

char *alloc(int n)   /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits in */ 
        allocp += n;
        return allocp - n;  /* old p */
    } else  /* not enough memory */
        return 0;
}

void afree(char *p)   /* free storage pointed to by p */
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}


/* ----------------------------------- */
/* Main test program ----------------- */
/* ----------------------------------- */

#include <stdio.h>
#include <ctype.h>

#define MAX 7

void print_usage()
//----------------
{
  printf("\n--- BE AWARE: THIS TEST PROGRAM HAS NO ERROR TREATMENT ---\n\n");
  printf("alloc/afree usage:  a)lloc(i)  f)afree  t)otal allocated memory\n");
  printf("Test program usage: H)Help  Q)Quit\n");
}

main() /* Test program for the alloc/afree functions */
{
  char c; 
  int size, i=-1;
  char *p[MAX];
  
  char *prompt = ">";
  
  print_usage();
  printf("%s", prompt);

  /*---------------------------
  Main loop of the test program
  ---------------------------*/
  while (c = getchar()) {
    switch(c) {
      
      case 'a': // alloc
        scanf("%i", &size);  // read input
        p[++i] = alloc(size);  // allocate memory
        printf("%i bytes have been allocated\n", sizeof(*p[0]) * (allocp - p[i]));
        break;
      
      case 'f': // afree
        size = allocp - p[i];
        afree(p[i--]);  // free memory
        printf("%i bytes have been deallocated\n", sizeof(*p[0]) * size);
        break;
      
      case 't': // total allocated memory
        printf("total allocated memory: %i bytes\n", sizeof(*p[0]) * (allocp - allocbuf));
        break;
      
      case 'H': // Help
        print_usage();
        break;
        
      case 'Q': // Quit
        return 0;
 
      default:
        print_usage();
        break;
    }
    while (getchar() != '\n') {} /* skip end of line */
    printf("%s", prompt);
  }
  /*--------------------------------------
  End of the main loop of the test program
  --------------------------------------*/
}