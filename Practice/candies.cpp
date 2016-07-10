#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//https://www.hackerrank.com/challenges/candies
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n;
	cin>>n;
	int left[n];
	int right[n];
	int rating[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>rating[i];
	}
	left[0] = 1;	//first pass left to right, give 1 candy to leftmost child
	for (int i = 1; i < n; ++i)
	{
		if (rating[i] > rating[i-1])
			left[i] = left[i-1] + 1;
		else
			left[i] = 1;
	}
	right[n-1] = 1;	//second pass right to left, give 1 candy to rightmost child
	for (int i = n-2; i >= 0; i--)
	{
		if(rating[i] > rating[i+1])
			right[i] = right[i+1] + 1;
		else
			right[i] = 1;
	}
	int candies = 0;
	for (int i = 0; i < n; ++i)
	{
		candies += max(left[i],right[i]);
	}
	cout<<candies<<endl;
    return 0;
}
