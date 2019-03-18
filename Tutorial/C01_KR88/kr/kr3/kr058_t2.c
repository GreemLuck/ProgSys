/* Author: Beat Hirsbrunner and Fulvio Frappolli, University of Fribourg, July 2007 */

#include <stdio.h>
#define MAX 10000


/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1]  ---  kr58 */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else	/* found match */
            return mid;
    }
    return -1;	/* no match */
}


main(int argc,char *argv[]){ // main's arguments are explained in chap. 5.10
    int x, max=0;  int array[MAX];
    
    x = atoi(argv[1]);
    while (max < MAX && scanf("%d", &array[max]) != EOF) ++max;
	
    printf("The output of binsearch is: %d\n", binsearch(x, array, max));
}
