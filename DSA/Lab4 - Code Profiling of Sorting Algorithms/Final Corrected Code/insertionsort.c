#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "insertionsort.h"
void insertion_sort(int *a, int N)
{
	int i,j;
	for (j = 1; j < N; ++j)
	{
		int key = a[j];
		i = j-1;
		while(i >=0 && key <= a[i])
		{
			a[i+1] = a[i];
			i--;
		}
		a[i+1] = key;
	}
}