/* Formatted Output - printf - KR chap. 7.2 */

/* Fulvio Frapolli, University of Fribourg, January 2008 */

#include <stdio.h>

/* A variety of specifications in printing "hello, world" (12 characters) ---  kr154 */
main(){
		
    char *s = "hello, world";
     
    printf(":%s:\n",s);
    printf(":%10s:\n",s);
    printf(":%.10s:\n",s);
    printf(":%-10s:\n",s);
    printf(":%.15s:\n",s);
    printf(":%-15s:\n",s);
    printf(":%15.10s:\n",s);
    printf(":%-15.10s:\n",s);
}
