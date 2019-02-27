#include <stdio.h>
main(){
enum {FALSE, TRUE} b; // declaration of variable b, without tag
b = TRUE;
printf("%i %i\n", b, FALSE);
enum color_tag {RED, GREEN, BLUE}; // enum declaration,
 // with tag 'color_tag'
enum color_tag c1, c2, c3; // declaration of variables ci
c1 = RED; c2 = c1+1; c3 = BLUE;
printf("%i %i %i\n", c1, c2, c3);


}