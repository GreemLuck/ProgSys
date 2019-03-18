/* A Simple Example of an Union nested in a Structure --- kr147-148 */

/* Author: Fulvio Frapolli & Beat Hirsbrunner, University of Fribourg, January 2008 */
/* Preliminary version by Kathrin Meyer, University of Fribourg, July 2006 */

#include <stdio.h>
#define MAX 100

/* Union in a structure --- kr148 */
struct {
	char *name;
	int flags;
	int utype;
	union {
		char cval; // added by BH
		float fval;
		int ival;
		char *sval;
	} u;
} symtab;

main() {

	char msg[MAX];

	printf("> Insert resp. a character, integer, float and word: ");

	scanf("%c", &symtab.u.cval);
	printf("%X, %d Byte,  %c\n", &symtab.u.cval, sizeof(symtab.u.cval),
			symtab.u.cval);

	scanf("%i", &symtab.u.ival);
	printf("%X, %d Bytes, %d\n", &symtab.u.ival, sizeof(symtab.u.ival),
			symtab.u.ival);

	scanf("%f", &symtab.u.fval);
	printf("%X, %d Bytes, %f\n", &symtab.u.fval, sizeof(symtab.u.fval),
			symtab.u.fval);

	scanf("%s", msg);
	symtab.u.sval = msg;
	printf("%X, %d Bytes, %s, address of the word: %X\n", &symtab.u.sval,
			sizeof(symtab.u.sval), symtab.u.sval, &msg);

}
