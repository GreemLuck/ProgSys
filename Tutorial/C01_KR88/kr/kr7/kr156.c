/* Variable-length Argument Lists - KR chap. 7.3 */

/* Kathrin Meyer, University of Fribourg, July 2006 */
/* revised by Beat Hirsbrunner, University of Fribourg, January 2008 */

#include <stdarg.h>
#include <stdio.h>

#define MAX 100

void minprintf(char *fmt, ...);

main(){
	
	int i; float r; char str[MAX];
	
	printf("> Insert resp. an integer, float and word: ");
	scanf("%d %f %s", &i, &r, str);
	
	minprintf("%d", i);
	minprintf(" %f %s\n", r, str);
}


/* minprintf: minimal printf with variable argument list --- kr156 */
void minprintf(char *fmt, ...)
{
    va_list ap;	/* points to each unnamed arg in turn */
    char *p, *sval;
    int ival;
    double dval;
	
    va_start(ap, fmt);	/* make ap point to 1st unnamed arg */
    for (p = fmt; *p; p++) {
	    if (*p != '%') {
	        putchar(*p);
	        continue;
	    }
	    switch (*++p) {
	    case 'd':
		    ival = va_arg(ap, int);
		    printf("%d", ival);
		    break;
	    case 'f':
		    dval = va_arg(ap, double);
		    printf("%f", dval);
		    break;
	    case 's':
		    for(sval = va_arg(ap, char *); *sval; sval++)
		        putchar(*sval);
		    break;
	    default:
		    putchar(*p);
		    break;
	    }
    }
    va_end(ap);	/* clean up when done */
}


