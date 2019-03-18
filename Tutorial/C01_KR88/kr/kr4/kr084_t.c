/* Author: Beat Hirsbrunner, University of Fribourg, July 2007 */

#include <stdio.h>

main()
{
   int n;
   scanf("%d", &n);
	
   if (n > 0) {
      int i; /* declare a new i */

      for (i = 0; i < n; i++)
         printf("%d ", i);
   }
   printf("\n");	     
}
