/* Line Input and Output - KR chap. 7.7 */

/* Fulvio Frapolli and Beat Hirsbrunner, University of Fribourg, January 2008 */

#include <stdio.h>
#include <string.h>

char *fgets(char *s, int n, FILE *fp);
int fputs(const char *s, FILE *iop);

#define MAX 10

main(int argc, char *argv[]) {
	char line[MAX];
	FILE *f_in;
	FILE *f_out;

	if (argc == 3) {
		f_in = fopen(argv[1], "r");  // open input file f_in in read mode
		f_out = fopen(argv[2], "a"); // open output file f_out in append mode
		
		while (fgets(line, MAX, f_in) != NULL) {
			fputs(line, f_out);
		}

		fclose(f_in);
		fclose(f_out);
	} else {
		printf("Usage: %s InputFile OutputFile\n", argv[0]);
    }
}


/* fgets: get at most n chars from iop  ---  kr165 */
char *fgets(char *s, int n, FILE *iop) {
	register int c;
	register char *cs;

	cs = s;
	while (--n > 0 && (c = getc(iop)) != EOF)
		if ((*cs++ = c) == '\n')
			break;
	*cs = '\0';
	return (c == EOF && cs == s) ? NULL : s;
}

/* fputs: put string s on file iop  ---  kr165 */
int fputs(const char *s, FILE *iop) {
	int c;

	while (c = *s++)
		putc(c, iop);
	return ferror(iop) ? EOF : 0;
}
