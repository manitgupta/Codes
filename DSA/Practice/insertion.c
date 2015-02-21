#include <stdio.h>
#include <stdlib.h>

// Insertion Sort practice
#define MAX 100

int* insertion_sort(int Arr[], int n)
{
	int i,j;
	int key;
	for (j = 1; j < n; ++j)
	{
		key = Arr[j];
		for(i=j-1; i >=0; i--)
		{
			if (Arr[i] > key)
			{
				Arr[i+1] = Arr[i];
			}
			else
			{
				break;
			}
		}
		Arr[i+1] = key;
	}
	return Arr; //returns the address of the first element of the Array.
}

int main()
{
	int Arr[MAX];
	int *ptr;
	int i,n;
	printf("Enter no. of Elements\n");
	scanf("%d",&n);
	for (i = 0; i < n; ++i)
	{
		scanf("%d",&Arr[i]);
	}
	printf("Elements of array: \n");
	for (i = 0; i < n; ++i)
	{
		printf("%d ",Arr[i]);
	}
	printf("\nSorted array: \n");
	ptr = insertion_sort(Arr,n); //The address of the first element is stored in ptr. Now both the syntax *(ptr+i) or ptr[i] is allowed.
	for(i = 0; i < n; i++)
	{
		printf("%d ", ptr[i]);
	}
	printf("\n");
	return 0;
}


