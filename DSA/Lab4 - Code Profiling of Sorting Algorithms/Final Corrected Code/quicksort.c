#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "quicksort.h"

void quicksort(int *a, int p, int r)
{
	int temp,q,j,x,i;				//x is the pivot, make it equal to the last element.
	if (p < r)
	{
		x = a[r];	//Define the pivot
		i = p-1;	//Define the Wall			// 'i' is the wall as described in CS 50 Lecture
		for (j = p; j < r; ++j)					// 'j' refers to the current element as described in CS 50 Lecture
		{
			if (a[j] < x)
			{
				i=i+1;
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
		temp = a[i+1];
		a[i+1] = a[r];
		a[r] = temp;
		q = i+1;
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
}
