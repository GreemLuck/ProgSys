/* Author: Beat Hirsbrunner, University of Fribourg, 27 December 2007 */

#include <stdio.h>

// Simple generator of an ordered list of integers
main(){
    int i=0, max;
    
    scanf("%d", &max); // Read the number of integers to generate
    printf("\n");
    for (i=0; i<max; ++i) {
        printf("%d ", 2*i); // Generate an ordered list of pair integers
        if (i%10 == 0) printf("\n");  // Nice pagination
    }
    printf("\n");
}
