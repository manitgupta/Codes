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


int fib(int n)
{
	if (n < 2)
		return n;
	else
		return (fib(n-1) + fib(n-2));
}

int main()
{
	int x;
	cout<<"Pure Recursion Fibonacci"<<endl;
	cout<<"Enter no. of terms:";
	cin>>x;
	for (int i = 1; i <= x; ++i)
	{
		cout<<fib(i)<<" ";
	}
	return 0;
}