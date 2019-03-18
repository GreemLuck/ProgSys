/* Error Handling - stderr and exit - KR chap. 7.6 */

#include <stdio.h>
#include <stdlib.h>

/* cat: concatenate files, version 2 --- kr163 */
main(int argc, char *argv[])
{
    FILE *fp;
    void filecopy(FILE *, FILE *);
    char *prog = argv[0];	/* program name for errors */
	
    if (argc == 1)	/* no args; copy out standard input */
	    filecopy(stdin, stdout);
    else
	    while (--argc > 0)
	        if ((fp = fopen(*++argv, "r")) == NULL) {
		        fprintf(stderr, "%s: can't open %s\n", prog, *argv);
		        exit(1);
	        } else {
		        filecopy(fp, stdout);
		        fclose(fp);
	    }
    if (ferror(stdout)) {
	    fprintf(stderr, "%s: errror writing stdout\n", prog);
	    exit(2);
    }
    exit(0);
}


/* filecopy: copy file ifp to file ofp --- kr162 */
void filecopy (FILE *ifp, FILE *ofp)
{
    int c;
	
    while ((c = getc(ifp)) != EOF)
      putc(c, ofp);
}
