#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void quicksort(int *a, int p, int r)
{
	int temp,q,j,x,i;				//x is the pivot, make it equal to the last element. //a is the input array. 
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

void merge(int *a,int l, int m, int r)
{
	int i,j,k;
	int n1 = m-l+1;
	int n2 = r-m;
	int Left[n1],Right[n2];
	for (i = 0; i < n1; ++i)
	{
		Left[i] = a[l+i];
	}
	for (j = 0; j < n2; ++j)
	{
		Right[j] = a[m+1+j];
	}
	i=0;j=0;k=l;
	while (i < n1 && j < n2)
	{
		if (Left[i] <= Right[j])
		{
			a[k++] = Left[i++];
		}
		if (Left[i] > Right[j])
		{
			a[k++] = Right[j++];
		}
	}
	while(i < n1)
	{
		a[k++] = Left[i++];
	}
	while(j < n2)
	{
		a[k++] = Right[j++];
	}
}
void mergesort(int *a,int l,int r)
{
	if (l < r)
	{
		int m = (l+r)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,r);
		merge(a,l,m,r);
	}
}