/*--------------------------------------------------------------------------------
Authors: Fulvio Frapolli and Beat Hirsbrunner, University of Fribourg, July 2007

Remark: This program is not really a test program, but it should at least help you 
to undestand the macro substitution in C, which seems to be trivial at first 
glance, but has in fact to be handled with great care.
--------------------------------------------------------------------------------*/

#include <stdio.h>

/*--- Some macros --- kr89-91 */
#define max(A,B)     ((A)>(B) ? (A) : (B))   /* max macro */

#define square1(x)   x*x        /* square macro, bad implementation !!! */
#define square2(x)   (x)*(x)    /* square macro, ok, but be careful !!! */


/* Some more advanced macros --- kr88-91 */
#define deb_print(expr)  printf(#expr " = %f\n", expr) /* debugging print macro */

#define paste(front,back)  front ## back /* concatenates the two arguments and 
                                            creates the token frontback */

#define forever  for(;;)  /* infinite loop */


main() /* About macro substitution */
{
    float a, b, tmp;
	
    printf("Type the values of a and b, and then return: ");
    scanf("%f %f", &a, &b);
	
    printf("\ndeb_print macro:\n");
    deb_print(a);   /* printf("a = %f\n", a); */
    deb_print(b);   /* printf("b = %f\n", b); */
    deb_print(a+b);
    deb_print(a/b);
	
    printf("\nmax macro:  #define max(A,B)  ((A)>(B) ? (A) : (B))\n");
    deb_print(max(a,b)); /* printf(max(a,b) = %f\n", ((a)>(b) ? (a) : (b)) ); */
	 
    printf("\nsquare1 macro: #define square1(x)  x*x //bad implementation !!!\n");
    deb_print(square1(a));
    deb_print(square1(a + 1)); /* printf(square1(a + 1) = %f\n", a + 1*a + 1); */
			
    printf("\nsquare2 macro:  #define square2(x)  (x)*(x)\n");
    deb_print(square2(a + 1));   	
	
    printf("\nsquare2 macro: side effect, WRONG USAGE !!!\n");
    deb_print(square2(++a));
    deb_print(a); 
	
    printf("\npaste macro:  #define paste(front,back)  front ## back\n");
    tmp = a + b;
    deb_print(tmp);
    deb_print(paste(tm,p));  /* printf("paste(tm,p) = %f\n", tmp); */
  	
    printf("\nforever macro: #define forever for(;;)\n");
    printf("Type ctrl-c to exit the program\n");
    forever;
}
