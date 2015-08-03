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


void BubbleSort(vector<int>& A,int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n-i-1; ++j)
		{
			if (A[j] > A[j+1])
			{
				int temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}
}

void Selection(vector<int>& A,int n)
{
	int min;
	for (int i = 0; i < n; ++i)
	{
		min = i;
		//find the smallest element in the unsorted subarray(indexes greater than i form the unosrted subarray)
		for (int j = i+1; j < n; ++j)
		{
			if(A[j] < A[min])
				min = j;
		}
		//swap the smallest with ith index.
		int temp = A[i];
		A[i] = A[min];
		A[min] = temp;
		// i increases, sorted subarray is not touched.
	}
}



int main()
{
	std::vector<int> A;
	for (int i = 0; i < 100; ++i)
	{
		A.push_back(rand()%1000);
	}
	//BubbleSort(A,100);
	Selection(A,100);
	for (int i = 0; i < 100; ++i)
	{
		cout<<A[i]<<" ";
	}
	return 0;
}