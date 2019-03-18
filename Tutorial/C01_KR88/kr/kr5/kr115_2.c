#include <stdio.h>

/* echo command-line arguments; 2nd version --- kr115 */
main(int argc, char *argv[])
{
	while (--argc > 0)
		printf("%s%s", *++argv, (argc > 1) ? " " : "");
	printf("\n");
	return 0;
}

