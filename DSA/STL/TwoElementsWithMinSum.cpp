#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

#define INT_MIN -999999
#define INT_MAX 999999

//Find two elements from an array with both +ve and -ve numbers whose sum is closest to zero

int TwoElementsWithMinSum(vector<int>& A, int n)
{
	// i should point to First Element and j to Last Element
	int i=0, j=n-1, positiveClosest = INT_MAX, negativeClosest = INT_MIN, temp;
	sort(A.begin(), A.end());
	for (int i = 0; i < A.size(); ++i)
	{
		cout<<A[i]<<" ";
	}
	while( i < j)
	{
		temp = A[i] + A[j]; //sum of first and last elements.
		if (temp > 0)		//if sum is +ve then try to reduce boundary for positiveClosest
		{
			if (temp < positiveClosest)
				positiveClosest = temp;
			j--;
		}
		else if(temp < 0)		//temp is -ve, try to increase negativeClosest and move it closer to Zero.
		{
			if(temp > negativeClosest)
				negativeClosest = temp;
			i++;
		}
		else
		{
			printf("\nClosest sum is of %d and %d\n",A[i],A[j]);
		}
		//After reducing boundaries of negativeClosest and positiveClosest, find which is closer to 0 among them
	}
	return 	((abs(negativeClosest) > positiveClosest)?positiveClosest:negativeClosest);

}

int main()
{
	vector<int> A(10);
	cout<<A.size()<<endl;
	for (int i = 0; i < A.size(); ++i)
	{
		A[i] = (rand()%100) - 50;
	}
	cout<<"Closest Sum:"<<TwoElementsWithMinSum(A,10);
	return 0;
}