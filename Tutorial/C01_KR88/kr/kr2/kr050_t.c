/* Author:  Fulvio Frapolli, University of Fribourg, July 2007 */

#include <stdio.h>


/* bitcount: counts 1 bits in x  ---  kr50 */
int bitcount(unsigned x)
{
  int b;

  for (b = 0; x != 0 ; x >>= 1)
    if (x & 01)
	b++;
  return b;
}


main(){
  
  unsigned x;
  
  scanf("%u", &x);
  printf("%d\n",bitcount(x));
}
