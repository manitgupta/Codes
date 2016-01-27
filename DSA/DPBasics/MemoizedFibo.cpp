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

#define N 1000
#define NIL -1

//Memoized Version to find the Nth Fibonacci Number
//This is Top Down DP, ie A Recursive Solution with lookup

std::vector<int> lookup(N,NIL);

// void initialize()
// {
// 	for (int i = 0; i < N; ++i)
// 	{
// 		lookup[i] = NIL;
// 	}
// }
int fib(int n)
{
	if(lookup[n] == NIL)
	{	if (n <=1)
			lookup.at(n) = n;
		else
			lookup.at(n) = fib(n-1) + fib(n-2);
	}
	return lookup.at(n);
}


int main(int argc, char* argv[])
{
	if (argc == 2)
		cout<<fib(atoi(argv[1]))<<endl;
	else
		cout<<"Incorrect Usage"<<endl;
	return 0;
}