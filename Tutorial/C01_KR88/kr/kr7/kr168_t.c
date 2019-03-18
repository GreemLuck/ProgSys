// Fulvio Frapolli and Beat Hirsbrunner, University of Fribourg, Jan. 2008

#include <stdio.h>
#include <stdlib.h>  // rand, srand, RAND_MAX

#define frand()  (rand() / ((double)RAND_MAX + 1))

/*---
The book (page 168) proposes:

   #define frand()  ((double) rand() / (RAND_MAX+1))
 
but this can result in negatives numbers (integer overflow), as we have in most
modern C environments : RAND_MAX = INT_MAX = LONG_MAX = 2147483647
---*/  

/*--- 
If your library already provides a fuction for floating-point randm numbers, it 
is likely to have better statistical properties than this one --- kr168
---*/



main() {
	unsigned int seed;
	int i, n;

	scanf("%u %i", &seed, &n);

	srand(seed);

	for (i=0; i<n; ++i)
		printf("%lf\n", frand());

}

