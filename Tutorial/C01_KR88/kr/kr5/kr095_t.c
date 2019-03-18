/* Author: Beat Hirsbrunner, University of Fribourg, July 2007 */

#include <stdio.h>

void swap(int x, int y)  /* WRONG --- kr95 */
{
  int temp;

  temp = x;
  x = y;
  y = temp;
}

main()
{
  int x, y;

  scanf("%d %d", &x, &y);
  printf("Before: x = %d, y = %d\n", x, y);
  swap(x, y);
  printf("After:  x = %d, y = %d\n", x, y);
}
