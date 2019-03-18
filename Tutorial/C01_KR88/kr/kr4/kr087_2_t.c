/* Author: Beat Hirsbrunner, University of Fribourg, July 2007 */

#include <stdio.h>

#define MAX 7

void my_qsort(int v[], int left, int right);
void swap(int v[], int i, int j);

main()
{
    int array[MAX];
    int i, max, res;

    /* read input */
    for (max=0;
         max < MAX && (res = scanf("%i",&array[max])) != EOF && res != 0;
         max++)
        ;
	
    my_qsort(array, 0, max-1);
	
    printf("Sorted integers: \n");
    for (i=0; i < max; i++) printf("%d\n", array[i]);
}


/* my_qsort: sort v[left]...v[right] into increasing order --- kr87 */
void my_qsort(int v[], int left, int right)
{
    int i, last;
    void swap(int v[], int i, int j);

    if (left >= right)   /* do nothing if array contains */
        return;          /* fewer than two elements      */
    swap(v, left, (left + right)/2);   /* move partition elem */
    last = left;                       /* to v[0]             */
    for (i = left+1; i <= right; i++)    /* partition */
        if (v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);   /* restore partition elem */
    my_qsort(v, left, last-1);
    my_qsort(v, last+1, right);
}


/* swap: interhange v[i] and v[j] --- kr88 */
void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
