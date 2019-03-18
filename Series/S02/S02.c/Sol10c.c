#include <stdio.h>

unsigned long setbit(unsigned long x, int n){
    unsigned long b = 1 << n;
    return x | b;
}

void main(){
    unsigned long x = 5;
    int n = 1;
    printf("%lu \n", setbit(x,n));
}