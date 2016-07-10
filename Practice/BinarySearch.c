#include <stdio.h>

//find a in A and b in B such that a + b = K
// K is input by user

int BinarySearch(int A[], int low, int high, int key)
{
	if (high >= low)
	{
		int mid = (low + high)/2;
		if (key < A[mid])
			{
				// printf("(A,%d,%d)\n",low,mid-1);
				return BinarySearch(A,low,mid-1,key);
			}
		else if (key > A[mid])
		{
			// printf("(A,%d,%d)\n",mid+1,high);
			return BinarySearch(A,mid+1,high,key);
		}
		else
		{
			return mid;
		}	
	}
	return -1;
}

void QuickSort(int A[], int low, int high)
{
	if (high > low)
	{
		int partition_index = Partition(A, low, high);
		//printf("partition_index = %d\n",partition_index);
		QuickSort(A, low, partition_index-1);
		QuickSort(A, partition_index+1, high);
	}
}
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int Partition(int A[], int low, int high)
{
	int pivot = A[high];
	// printf("Pivot = %d\n",pivot);
	int Wall = low -1;
	int j;
	for (j = low; j < high; ++j)
	{
		if (A[j] < pivot)
		{
			//printf("A[j] = %d and Pivot = %d\n",A[j],pivot);
			Wall++;
			// printf("Wall = %d\n",Wall);
			swap(&A[Wall],&A[j]);	//swap element next to the wall with the smaller element.
		}
	}
	swap(&A[Wall+1],&A[high]); 	//swap the pivot with element to the right of the wall.
	return (Wall+1); 			//after swaping Wall+1 will be the location of the pivot.
}

void findIfSumIsK(int A[], int B[], int n, int K)
{
	//Sort A
	QuickSort(A,0,n-1);		// O(nlogn)
	int i,res,c;
	for (i = 0; i < n; ++i) // O(n)
	{
		c = K - B[i];
		res = BinarySearch(A,0,n-1,c); 	//O(logn) , A was sorted, search in A
		if (res != -1)
		{
			printf("a = %d and b = %d exist\n",c,B[i]);
			break;
		}
	}
	if (res == -1)
		printf("a and b do not exist\n");
	//Algo is -> nlogn + n*logn = O(nlogn)
}

void main()
{
	int A[] = {3,5,6,8,12,57,80,150,65,13,2};
	int B[] = {6,8,9,45,79,43,147,89,90,76};
	int key = 78;
	int n = sizeof(A)/sizeof(A[0]);
	findIfSumIsK(A,B,n,key);
}