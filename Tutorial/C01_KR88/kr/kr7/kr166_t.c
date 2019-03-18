// Beat Hirsbrunner and Fulvio Frapolli, University of Fribourg, Jan. 2008

#include <stdio.h>
#include <stdlib.h> // getc, ungetc


/* --------------------------------------*/
/* Test progam for getc/ungetc functions */
/* --------------------------------------*/

void print_usage() 
{
	printf("getc/ungetc usage:  g)getc()  u)ungetc(c) \n");
	printf("Test program usage: H)Help  Q)Quit\n");
}


int main(int argc, char *argv[]) {

	FILE *f_in;
	char c;
	char *prompt = ">";

	if (argc!=2) { // error treatment
		printf("Usage: %s inputFILE \n", argv[0]);
		return -1;
	}

	f_in = fopen(argv[1], "r");  // open argv[1] in read mode
	
	print_usage();
	printf("%s", prompt);

	while (c = getchar()) {  // main loop
		switch (c) {
			
			case 'g': // getc
				c = getc(f_in);  // read the next character from f_in
				printf("character readed by getc: %c\n", c);
				break;

			case 'u': // ungetc
				c = getchar();  // read the character to be pushed back
				c = ungetc(c, f_in);
				printf("character pushed back by ungetc: %c\n", c);
				break;

			case 'H': // Help
				print_usage();
				break;

			case 'Q': // Quit
				return 0;

			default:
				print_usage();
				break;
		} // end switch
		
		while (getchar() != '\n') {} /* skip end of line */
		printf("%s", prompt);
		
	} // end main loop

	fclose(f_in);
}

