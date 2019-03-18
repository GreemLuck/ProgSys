/* Author: Beat Hirsbrunner, University of Fribourg, July 2007 */

#include <stdio.h>

void swap(int *px, int *py)  /* interchange *px and *py  ---  kr96 */
{
  int temp;
	
  temp = *px;
  *px = *py;
  *py = temp;
}

main()
{
  int x = 1, y = 2;

  scanf("%d %d", &x, &y);
  printf("Before: x = %d, y = %d\n", x, y);
  swap(&x, &y);
  printf("After:  x = %d, y = %d\n", x, y);
}
