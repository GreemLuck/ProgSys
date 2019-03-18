/* Authors: Fulvio Frapolli and Beat Hirsbrunner, University of Fribourg, July 2007 */

#include <stdio.h>

/* getbits: get n bits from position p  ---  kr49 */
unsigned int my_getbits(unsigned int x, int p, int n)
{
  return (x >> (p+1-n)) & ~(~0 << n);
}

int main()
{
  unsigned int x;
  int n, p;

  scanf("%u %d %d", &x, &p, &n);

  printf("%u\n", my_getbits(x,p,n));
}
