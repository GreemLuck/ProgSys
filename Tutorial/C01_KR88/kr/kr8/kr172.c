/* Kathrin Meyer, University of Fribourg, July 2006 */

#include "my_stdio.h" // putchar, BUFSIZ
#undef getchar

/* getchar: simple buffered version --- kr172 */
int getchar(void)
{
    static char buf[BUFSIZ];
    static char *bufp = buf;
    static int n = 0;

    if (n == 0) {  /* buffer is empty */
        n = read(0,buf, sizeof buf);
        bufp = buf;
    }
    return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}

main() /* copy input to output; 2nd version --- kr017 */
{
    int c;
    while ((c = getchar()) != EOF)
        putchar(c);
}
