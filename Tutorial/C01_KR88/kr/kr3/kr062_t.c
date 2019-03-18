/* Author: Fulvio Frapolli, University of Fribourg, July 2007 */

#include <stdio.h>
#define MAX 10000

/* shellsort: sort v[0], ... v[n-1] into increasing order ---- kr62 */
void my_shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap)
	    {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
}

main()
{
    int max,i;
    int array[MAX];
    
	for (max=0; 
	     max < MAX && scanf("%i",&array[max]) != EOF;
		 max++)
	   ;
    
	my_shellsort(array,max);
        
    printf("Sorted integers: \n");
	for (i=0; i < max; i++) printf("%d\n", array[i]);
	
}
