/* Standard Input and Output - KR chap. 7.1 */

#include <stdio.h>
#include <ctype.h>

main()	/* lower: convert input to lower case --- kr153 */
{
    int c;
	
    while ((c = getchar()) != EOF)
      putchar(tolower(c));
    return 0;
}
