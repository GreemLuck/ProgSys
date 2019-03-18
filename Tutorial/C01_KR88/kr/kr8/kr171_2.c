/* Kathrin Meyer, University of Fribourg, July 2006 */

#include <stdio.h>
#undef getchar

/* getchar: unbuffered single character input --- kr 171 */
int getchar(void){
  char c;
  return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}

main() /* copy input to output; 2nd version --- kr017 */
{
    int c;

    while ((c = getchar()) != EOF)
       putchar(c);
}
