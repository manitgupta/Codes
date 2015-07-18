#include <stdio.h>
#include <stdlib.h>

#include "mergesort.h"


int main()
{
	int arr[SIZE];
	int i,n;
	printf("Enter Size of Array:");
	scanf("%d",&n);
	printf("Enter the elements:\n");
	for(i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("The Given Array is:\n");
	display(arr,n);
	printf("The Sorted Array is:\n");
	mergeSort(arr,0,n-1);
	display(arr,n);
	return 0;
}