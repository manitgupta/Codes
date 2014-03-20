#include <iostream>

using namespace std;

int main()
{
	int n,i,j;
	int l=0;
	int primefactors[10000];
	int primes[1000001];
	int num[1000001];
	cin>>n;
	for(i=0;i<(n-1);i++)
	{
		num[i]=i+2;			//input numbers upto n
	}
	for(i=0;i<(n-1);i++)
	{
		if(num[i]!=-1)
		{
			for(j=2*num[i]-2;j<n;j+=num[i])
			{
				num[j]=-1;
			}
		}
	}
	j=0;
	for(i=0;i<(n-1);i++)
	{
		if(num[i]!=-1)
		{
			primes[j++]=num[i];
		}
	}
	for(int k=0;k<j;k++)
	{
		if(n%primes[k]==0)
		{
			primefactors[l++]=primes[k];
		}
	}
	for(int p=0;p<l;p++)
	{
		cout<<primefactors[p]<<endl;
	}

	return 0;
}