/* Author: Fulvio Frapolli and Beat Hirsbrunner, University of Fribourg, January 2008 */

#include <stdio.h>

/*structure declaration of a point --- kr128 */
struct point {
	int x;
	int y;
};


main() { /* --- kr131 */
	struct point origin, *pp;
	
	printf("> Coordinates of origin point: ");
	scanf("%i %i", &origin.x, &origin.y);
	
	pp = &origin;

	printf("origin is (%d,%d)\n", (*pp).x, (*pp).y);
}
