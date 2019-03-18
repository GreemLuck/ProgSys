/* Author: Fulvio Frapolli and Beat Hirsbrunner, University of Fribourg, July 2007 */

#include <stdio.h>

main()  /* Artificial sequence showing how to declare a pointer and how to use & and *  ---  kr94 */
{
  int x=1, y=2, z[10];
  int *ip;	/* ip is a pointer to int */
  
  printf("\n");
  printf("   x = %d     &x = %p\n", x, &x);
  printf("   y = %d     &y = %p\n", y, &y);
  printf("z[0] = %d  &z[0] = %p\n", z[0], &z[0]);
  printf("\n");
  printf("ip = %p   &ip = %p   *ip = %d\n", ip, &ip,   *ip);
  printf("BE AWARE, the value of ip is garbage, i.e. has not yet been initialized !!!\n");
  
  ip = &x;  /* ip now points to x */
  printf("\n> ip = &x;  /* ip now points to x */\n");
  printf("ip = %p  *ip = %d\n", ip, *ip);
  
  y = *ip;  /* y is now 1 */
  printf("\n> y = *ip;  /* y is now 1 */\n");
  printf("y = %d\n", y);
      
  *ip = 0;  /* x is now 0 */
  printf("\n> *ip = 0;  /* x is now 0 */\n");
  printf("x = %d\n", x);
      
  ip = &z[0];  /* ip now points to z[0] */
  printf("\n> ip = &z[0];  /* ip now points to z[0] */\n");
  printf("ip = %p\n\n", ip);
}
