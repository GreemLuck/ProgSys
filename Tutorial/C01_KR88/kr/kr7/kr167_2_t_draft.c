// Fulvio Frapolli and Beat Hirsbrunner, University of Fribourg, Jan. 2008


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define DIM 10
#define MAX 1000000

void print_usage()
//----------------
{
	printf("\n--- The following commands should be used with a performance tool like 'vmstat' ot 'top'.\n"
	       "Under Mac OS X 10.3 or later, one can also use the graphical tool 'Activity Monitor'.---\n"
		   "Hit CTRL-C to stop the program before crashing your machine!!!\n");
	printf("malloc/calloc/free usage:  M)Fill Memory with malloc F)Verify memory deallocation (malloc/free) C)Fill memory with calloc\n");
	printf("Test program usage: H)Help  Q)Quit\n");
}

main() /* Test program for the alloc/afree functions */
{

	long li, grain = 1048576; // 2 ** 20
	char c;
	int k;
	char *prompt = ">";
	int *i,*j[MAX];
	print_usage();
	printf("%s", prompt);

	/*---------------------------
	 Main loop of the test program
	 ---------------------------*/
	while (c = getchar()) {
		switch (c) {

		case 'M': // Fill the memory with malloc
			li=0;
			while (TRUE) {
				i = (int *) malloc(sizeof(int));
				if ( !(++li % grain))
					printf("%d\n", li/grain);
			}
			break;

		case 'F': //Verify memory deallocation  malloc/free
			li=0;
			for (k=0;k<MAX;k++)
				j[k]= (int *) malloc(MAX * sizeof(int));
			for (k=0;k<MAX;k++)
				free(j[k]);
			break;

		case 'C': // Fill the memory with calloc
			li=0;
			while (TRUE) {
				i = (int *) calloc(DIM,sizeof(int));
				if ( !(++li % grain))
					printf("%d\n", li/grain);
			}
			break;

		case 'H': // Help
			print_usage();
			break;

		case 'Q': // Quit
			return 0;

		default:
			print_usage();
			break;
		}
		while (getchar() != '\n') {
		} /* skip end of line */
		printf("%s", prompt);
	}
	/*--------------------------------------
	 End of the main loop of the test program
	 --------------------------------------*/
}
