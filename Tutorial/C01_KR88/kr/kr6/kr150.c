/* Author: Beat Hirsbrunner and Fulvio Frapolli, University of Fribourg, January 2008 */

#include <stdio.h>

main(){ 
	
	struct { /* --- kr150 : bit-field */
		unsigned int is_keyword : 1;
		unsigned int is_extern : 1;
		unsigned int is_static : 1;
	} flags = {1, 0, 0};
	
	unsigned int i;
	
	struct { // classical structure
		unsigned int is_keyword;
		unsigned int is_extern;
		unsigned int is_static;
	} int_flags;

	
	// Size
	printf("\n");
	printf("Size of flags:        %d\n", sizeof(flags));
	printf("Size of unsigned int: %d\n", sizeof(i));
	printf("Size of int_flags:    %d\n", sizeof(int_flags));
	
	// bit-field usage
	printf("\nflags' bit-fields: %u %u %u\n", flags.is_keyword, flags.is_extern, flags.is_static);

	// Assignments
	flags.is_extern = flags.is_static = 1; // turns on is_extern and is_static bits in flags
	printf("\nflags' bit-fields: %u %u %u\n", flags.is_keyword, flags.is_extern, flags.is_static);
		
	flags.is_extern = flags.is_static = 0 ; // turns off is_extern and is_static bits in flags
	printf("\nflags' bit-fields: %u %u %u\n", flags.is_keyword, flags.is_extern, flags.is_static);
	printf("\n");
}
