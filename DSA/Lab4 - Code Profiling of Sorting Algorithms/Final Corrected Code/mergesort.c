#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "mergesort.h"


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