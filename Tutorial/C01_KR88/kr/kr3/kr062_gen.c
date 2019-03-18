/* Author: Beat Hirsbrunner, University of Fribourg, 28 December 2007 */

#include <stdio.h>
#include <stdlib.h> // rand, srand

// Simple generator of a ramdom list of integers
main(){
    int i=0, n;
    unsigned int seed=1;
    
    scanf("%d", &n); // Number of integers to generate
    // scanf("%u", &seed); // useful for future more exhautive tests
	
    srand(seed); // initialization of the pseudo-random generator rand()
    for (i=0; i<n; ++i) {
        printf("%d\n", rand()); // Generate a random list of integers
    }
}
