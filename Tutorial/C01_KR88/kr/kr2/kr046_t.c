/* Authors: Beat Hirsbruner and Fulvio Frapolli, University of Fribourg, July 2007 */

#include <stdio.h>
#include <ctype.h>

unsigned long int next = 1;

/* rand: return pseudo-random integer on 0..32767 --- kr46 */
int my_rand(void)
{
  next = next * 1103515245 + 12345;
  return (unsigned int) (next / 65536) % 32768;
}


/* srand: set seed for rand --- kr46 */
void my_srand(unsigned int seed)
{
  next = seed;
}


main() {
  unsigned int seed;
  int i, n;
  
  scanf("%u %i", &seed, &n);
  
  my_srand(seed);
  
  for (i=0; i<n; ++i)
     printf("%i\n", my_rand());
}
