#include <stdio.h>
#include <stdlib.h>

/* 
	Author: Manit Gupta
	Program: Merge Sort Implementation on Integers.
*/
#ifndef SIZE
#define SIZE 100



void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[],int l,int r); 		// l = left index, m = (l+r)/2 middle index, r = right index

#endif


void merge(int arr[],int l,int m, int r)
{
	int i,j,k;
	int n1 = m-l+1; //Find length of the Left Sorted Array.
	int n2 = r-m;	//Find length of the Right Sorted Array.
	int Left[n1],Right[n2]; //Declare Temp Arrays and copy data over in the them.
	for(i = 0; i < n1; i++)
	{
		Left[i] = arr[l+i];
	}
	for (j = 0; j < n2; ++j)
	{
		Right[j] = arr[m+1+j];
	}
	i = 0; 	//Pointer/Marker to Left Array
	j = 0;	//Pointer/Marker to Right Array
	k = l; 	//We MUST modify the part of the arr which is given to the merge function.
	while(i < n1 && j < n2)
	{
		if(Left[i] <= Right[j])
		{
			arr[k++] = Left[i++];
		}
		else if(Left[i] > Right[j])
		{
			arr[k++] = Right[j++];
		}
	}
	while(i < n1) //Copy over remaining elmments, if any (This happens when one array (Right or Left) gets exhausted while more than 1 element remains in the other.
	{
		arr[k++] = Left[i++];
	}
	while(j < n2)
	{
		arr[k++] = Right[j++];
	}
}

void mergeSort(int arr[], int l, int r)
{	
	if (l < r) //Exit Condition!! This is very important. When l becomes equal to r it means the broken down array has only one 1 element.
	{
		int m = (l+r)/2;
		mergeSort(arr,l,m);	
		mergeSort(arr,m+1,r);
		merge(arr,l,m,r);	
	}
	
}

void display(int arr[],int size)
{
	int i;
	for (i = 0; i < size; ++i)
	{
		printf("%d ",*(arr+i));
		//printf("%d\n",arr[i]);
	}
	printf("\n");
}


















