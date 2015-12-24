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
#define MAXN 500 //Max number in series.

int fibo_dyn(int n)
{
	int fibresult[MAXN];
	fibresult[0] = 1;
	fibresult[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		fibresult[i] = fibresult[i-1] + fibresult[i-2];
	}
	return fibresult[n];
}

//DIFFERENCE STARTS BECOMING APPRECIABLE AT 40 TERMS.

int main()
{
	int x;
	cout<<"Dyanmic Programming Solution"<<endl;
	cout<<"Enter no. of terms:";
	cin>>x;
	for (int i = 0; i < x; ++i)
	{
		cout<<fibo_dyn(i)<<" ";
	}
	cout<<endl;
	return 0;
}