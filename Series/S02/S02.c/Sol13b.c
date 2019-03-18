#include <stdio.h>

void main(){
    char c; int i; char str[10]; float f;
    scanf("%c %i %s %f", &c, &i, str, &f);
    printf("%c %i %s %f\n", c, i, str, f);
}