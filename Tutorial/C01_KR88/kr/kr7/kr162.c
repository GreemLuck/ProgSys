/* File Access - KR chap. 7.5 */

#include <stdio.h>

/* cat: concatenate files, version 1  --- kr162 */
main(int argc, char *argv[])
{
    FILE *fp;
    void filecopy(FILE *, FILE *);
	
    if (argc == 1)	/* no args; copy out standard input */
	filecopy(stdin, stdout);
    else
	while (--argc > 0)
	    if ((fp = fopen(*++argv, "r")) == NULL) {
		    printf("cat: can't open %s\n", *argv);
		    return 1;
	    } else {
		    filecopy(fp, stdout);
		    fclose(fp);
	    }
    return 0;
}


/* filecopy: copy file ifp to file ofp  ---  kr162 */
void filecopy (FILE *ifp, FILE *ofp)
{
    int c;
	
    while ((c = getc(ifp)) != EOF)
	    putc(c, ofp);
}
