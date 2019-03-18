/* Author: Fulvio Frapolli and Beat Hirsbrunner, University of Fribourg, January 2008 */

#include <stdio.h>
#include <math.h>  // sqrt

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

main() { 
	struct point pt1, pt2;
	struct rect my_rect;
	double dist, surface;

	printf("> Coordinates of point p1: ");
	scanf("%i %i", &pt1.x, &pt1.y);
	printf("> Coordinates of point p2: ");
	scanf("%i %i", &pt2.x, &pt2.y);

	//define my_rect
	my_rect.pt1 = pt1;
	my_rect.pt2 = pt2;

	//distance between the two corners of my_rect
	dist = sqrt((double)(pt2.x - pt1.x) * (pt2.x - pt1.x) + 
	            (double)(pt2.y - pt1.y) * (pt2.y - pt1.y));
	surface = (double)(my_rect.pt2.x - my_rect.pt1.x) * 
	          (double)(my_rect.pt2.y - my_rect.pt1.y);

	printf("Corner 1 = (%i,%i), Corner2 = (%i,%i) \nDiagonal = %.2f \nSurface = %.2f\n",
	       pt1.x, pt1.y, pt2.x, pt2.y, dist, surface);
}
