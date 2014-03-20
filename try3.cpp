#include <iostream>

using namespace std;

int main()
{
	int i,j,l;
	int primefactors[10000];
	int primes[1000001];
	int num[1000001];
	for(i=0;i<10000;i++)
	{
		num[i]=i+2;			//input numbers upto n
	}
	for(i=0;i<10000;i++)
	{
		if(num[i]!=-1)
		{
			for(j=2*num[i]-2;j<10000;j+=num[i])
			{
				num[j]=-1;
			}
		}
	}
	j=0;
	for(i=0;i<10000;i++)
	{
		if(num[i]!=-1)
		{
			primes[j++]=num[i];
		}
	}//primes in first 10000 numbers.
	for(int k=2;k<=100000;k++)
	{	
		l=0;
		for(int p=0;(p<j)&&(k>=primes[p]);p++)
		{
			if(k%primes[p]==0)
			{
				primefactors[l++]=primes[p]; //prime factors for given k are stored in primefactorss array while k is greater than the prime factor.
			}
		}
		cout<<k<<": ";
		for (int i = 0;i<l;i++)
		{
			cout<<primefactors[i]<<" ";
		}
		cout<<endl;
	}

	return 0;
}