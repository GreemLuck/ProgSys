/* Author: Fulvio Frapolli and Beat Hirsbrunner, University of Fribourg, January 2008 */

#include <stdio.h>

main() { // Size of a structure and alignement problem
	
	struct { /* --- kr138 */
		char c;
		int i;
	} align_test;	
	
	printf("Size of a char: %d\n",     sizeof(align_test.c));
	printf("Size of an int: %d\n",     sizeof(align_test.i));
	printf("Size of align_test: %d\n", sizeof(align_test));

}
