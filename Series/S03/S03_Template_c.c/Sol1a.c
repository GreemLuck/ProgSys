/*--------------------------------------------------------------------------
Replace a while loop with a for loop (Series 3, exercise 1a)

Usage: Sol1a  ## test with n = 5, 0

Beat Hirsbrunner, 15 Sept. 2011, rev 10 Jan. 2015 --- template
NN, <date> --- implementation of a for loop
--------------------------------------------------------------------------*/
#include <stdio.h>
int main()
{
   int low, high, n;
   
   printf("> n = ");   
   scanf("%i", &n);

   low = 0;
   high = n-1;   
/*----------   while loop     ----------*/
   while (low <= high) {
      printf("%i\n", low);
      ++low;
   } 
/*----------   /while loop     ----------*/

   printf("low_final = %i\n", low);
   printf("\n");

/*----------   for loop     ----------*/
   printf("Not yet implemented\n");                           //¥¥¥-------------
/*----------   /for loop     ----------*/

   printf("low_final = %i\n", low);
}