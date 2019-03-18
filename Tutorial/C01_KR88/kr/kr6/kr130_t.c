/* Author: Fulvio Frapolli and Beat Hirsbrunner, University of Fribourg, January 2008 */

#include <stdio.h>

/* structure declaration of a point --- kr128 */
struct point {
	int x;
	int y;
};

/* structure declaration of a rectangle --- kr129 */
struct rect {
	struct point pt1;
	struct point pt2;
};

/* makepoint: make a point from x and y components --- kr130 */
struct point makepoint(int x, int y) {
	struct point temp;

	temp.x = x;
	temp.y = y;
	return temp;
}

/* addpoint: add two points --- kr130 */
struct point addpoint(struct point p1, struct point p2) {
	p1.x += p2.x;
	p1.y += p2.y;
	return p1;
}

/* ptinrect: return 1 if p in r, 0 if not --- kr130 */
int ptinrect(struct point p, struct rect r) {
	return p.x >= r.pt1.x && p.x < r.pt2.x && 
	       p.y >= r.pt1.y && p.y < r.pt2.y;
}

main() {
	struct rect screen;
	struct point middle, pt;
	int x1, y1, x2, y2;

	//reads two points 
	printf("> Coordinates of point one: ");
	scanf("%i %i", &x1, &y1);
	printf("> Coordinates of point two: ");
	scanf("%i %i", &x2, &y2);

	// makepoint - set the diagonnally opposite corners of a rectangle
	screen.pt1 = makepoint(x1, y1);
	screen.pt2 = makepoint(x2, y2);

	// calculate the coordinates of the point in the middle of a rectangle
	middle = makepoint((screen.pt1.x + screen.pt2.x)/2,
	                   (screen.pt1.y + screen.pt2.y)/2);
	printf("The middle of the two points is: %d, %d\n", middle.x, middle.y);
	
	// addpoint - add two points
	pt = addpoint(screen.pt1, screen.pt2);
	printf("The sum of the two points is: %d, %d\n", pt.x, pt.y);

	// test wether a point is inside a rectangle
	printf("> Insert a point p1 in order to test if it is inside the rectangle: ");
	scanf("%i %i", &pt.x, &pt.y);
	printf("Point p1 is in rectangle (1 for yes, 0 for no): %d\n", ptinrect(pt, screen));
	
	printf("> Insert a point p2 in order to test if it is inside the rectangle: ");
	scanf("%i %i", &pt.x, &pt.y);
	printf("Point p2 is in rectangle (1 for yes, 0 for no): %d\n", ptinrect(pt, screen));

}
