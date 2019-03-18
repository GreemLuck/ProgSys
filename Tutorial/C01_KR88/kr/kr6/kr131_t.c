/* Author: Fulvio Frapolli and Beat Hirsbrunner, University of Fribourg, January 2008 */

#include <stdio.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

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

/* canonrect: canonicalize coordinates of rectangle --- kr131 */
struct rect canonrect(struct rect r) {
	struct rect temp;

	temp.pt1.x = min(r.pt1.x, r.pt2.x);
	temp.pt1.y = min(r.pt1.y, r.pt2.y);
	temp.pt2.x = max(r.pt1.x, r.pt2.x);
	temp.pt2.y = max(r.pt1.y, r.pt2.y);
	return temp;
}

main() {
	struct rect rectangle;
	struct rect result;

	printf("> Insert the first point: ");
	scanf("%i %i", &rectangle.pt1.x, &rectangle.pt1.y);
	printf("> Insert the second point: ");
	scanf("%i %i", &rectangle.pt2.x, &rectangle.pt2.y);

	result = canonrect(rectangle);
	printf("Lower-left: %d, %d\nUpper-right: %d, %d\n", result.pt1.x,
	       result.pt1.y, result.pt2.x, result.pt2.y);
}
