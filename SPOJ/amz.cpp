#include<iostream>

using namespace std;

int calcfac(int n)
{
	unsigned int fac=1;
	if(n==0)
	{
		fac=1;
	}
	for(int j=1;j<=n;j++)
	{
		fac*=j;
	}
	return fac;
}
int main()
{
	unsigned long int t,n;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		calcfac(n);
		cout>>n;
	}
}