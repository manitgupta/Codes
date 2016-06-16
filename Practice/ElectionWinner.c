#include <stdio.h>

//Problem in Sorting in DSA Made Easy

// O(n) Algorithm which assumes max(ID) <= n
int findElectionWinner(int A[], int n)
{
	int i,j,max;
	int CandidateArr[n];
	for (i = 0; i < n; ++i)
	{
		CandidateArr[i] = 0;
	}
	//Assumes Candidate ID < n
	for (i = 0; i < n; ++i)
	{
		CandidateArr[A[i]]++;
	}
	max = CandidateArr[0];
	for (i = 0; i < n; ++i)
	{
		if (CandidateArr[i] > max)
			max = CandidateArr[i];
	}
	return max;
}
// O(nlogn) Algorithm which sorts and finds

void QuickSort(int A[], int low, int high)
{
	if (high > low)
	{
		int partition_index = Partition(A, low, high);
		printf("partition_index = %d\n",partition_index);
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
	printf("Pivot = %d\n",pivot);
	int Wall = low -1;
	int j;
	for (j = low; j < high; ++j)
	{
		if (A[j] < pivot)
		{
			printf("A[j] = %d and Pivot = %d\n",A[j],pivot);
			Wall++;
			// printf("Wall = %d\n",Wall);
			swap(&A[Wall],&A[j]);	//swap element next to the wall with the smaller element.
		}
	}
	swap(&A[Wall+1],&A[high]); 	//swap the pivot with element to the right of the wall.
	return (Wall+1); 			//after swaping Wall+1 will be the location of the pivot.
}
int findElectionWinnerSorting(int A[], int n)
{
	//sort the list
	QuickSort(A,0,n-1);
	int i, currentCounter=1, maxCounter=1;
	int currentCandidate, maxCandidate;
	currentCandidate = maxCandidate = A[0];
	for (i = 1; i < n; ++i)
	{
		if (A[i] == currentCandidate)
			currentCandidate++;
		else
		{
			//Make new candidate and reset counter
			currentCandidate = A[i];
			currentCounter = 1;
		}
		if (currentCounter > maxCounter)
		{
			maxCandidate = currentCandidate;
			maxCounter = currentCounter;
		}
	}
	return currentCandidate;
}
void main()
{
	int A[] = {10,7,8,9,1,5,5,5,9,9,9,9,9};
	int n = sizeof(A)/sizeof(A[0]);
	int i;
	int winner = findElectionWinnerSorting(A,n);
	// for (i = 0; i < n; ++i)
	// {
	// 	printf("%d ",A[i]);
	// }
	printf("The winner is Candidate with ID = %d\n",winner);
}