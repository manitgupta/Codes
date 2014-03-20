#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;				//spoj ptime. Working.
int main()
{
	int i,j,n,num[50001],primes[50001];
	int times[50001]={0};
	scanf("%d",&n);
	for(i=0;i<=n;i++)
	{
		num[i]=i+2;
	}
	for(i=0;i<=n;i++)
	{
		if(num[i]!=-1)
		{
			for(j=2*num[i]-2;j<=n;j+=num[i])
			{
				num[j]=-1;
			}
		}
	}
	j=0;
	for(i=0;i<=n;i++)
	{
		if(num[i]!=-1)
		{
			primes[j++]=num[i];
		}
	} 
	for(int l=0;l<j;l++)
	{
		int p  = primes[l];
		int q =1;
		while(n/p > 0)
		{
			times[l] += n/p;
			q++;
			p  = pow(primes[l],q);
		}
	}
	printf("%d^%d",primes[0],times[0]);
	for(int l=1;l<j;l++)
	{
		if(primes[l] < n)
		{
			printf(" * %d^%d",primes[l],times[l]);
		}
	}
	return 0;
}