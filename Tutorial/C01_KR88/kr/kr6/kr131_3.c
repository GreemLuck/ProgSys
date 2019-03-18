/* Author: Fulvio Frapolli and Beat Hirsbrunner, University of Fribourg, January 2008 */

#include <stdio.h>

/*structure declaration of a point --- kr128 */
struct point {
	int x;
	int y;
};

/*structure declaration of a rectangle --- kr129 */
struct rect {
	struct point pt1;
	struct point pt2;
};

main() { /* --- kr131 */
	struct rect r, *rp = &r;
	
	printf("> Coordinates of point pt1: ");
	scanf("%i %i", &r.pt1.x, &r.pt1.y);
	
	printf("pt1 is (%d,%d)\n", r.pt1.x, r.pt1.y);
	printf("pt1 is (%d,%d)\n", rp->pt1.x, rp->pt1.y);
	printf("pt1 is (%d,%d)\n", (r.pt1).x, (r.pt1).y);
	printf("pt1 is (%d,%d)\n", (rp->pt1).x, (rp->pt1).y);
}
