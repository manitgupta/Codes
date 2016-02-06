#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define _DEBUG

#define Inf 2147483647
#define Max(a, b)  (a < b ? b : a)
#define Min(a, b)  (a > b ? b : a)
#define INT_MIN -99999999

//Naive Recursive Implementation
//Uses only the recurrence relation.
//Exponential Time

int MatrixChainOrder(int p[], int i, int j)
{
	int min = Inf;
	int count;
	if(i==j)
		return 0;
	else
	{
		for (int k = i; k < j; ++k)
		{
			count = MatrixChainOrder(p,i,k) + MatrixChainOrder(p,k+1,j) + p[i-1]*p[k]*p[j];
			if (count < min)
				min = count;
		}
	}
	return min;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Minimum number of multiplications is %d \n", MatrixChainOrder(arr, 1, n-1));
    return 0;
}