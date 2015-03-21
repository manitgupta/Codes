#include <iostream>
using namespace std;

int main()
{
	unsigned long long int n,m,j=0;
	unsigned long int value[300001];
	unsigned long int sum[300001];
	cin>>n>>m;
	cout<<endl;
	for(unsigned long long int i=0;i<n;i++)
	{
		cin>>value[i];
	}
	for(unsigned long long int i=0;i<n;i++)
	{
		if(i>0)
		{	
			sum[i]=sum[i-1]-value[i-1];
			for(;sum[i]<=m;j++)
			{
				sum[i]+=value[j];
			}
			sum[i]=sum[i]-value[--j];
		}
		if(i==0)
		{
			sum[i]=0;
			for(;sum[i]<=m;j++)
			{
				sum[i]+=value[j];
			}
			sum[i]=sum[i]-value[--j];
		}
	}
	/*
	for(int i=0;i<n;i++)
	{
		sum[i]=0;
		for(j=i;sum[i]<=m;j++)
		{
			sum[i]+=value[j];
		}
		sum[i]=sum[i]-value[--j];
	}
	for(int i=0;i<n;i++)
	{
		cout<<sum[i]<<endl;
	}
	int max=sum[0];
	for(int i=0;i<n;i++)
	{
		if(sum[i]>max)
		{
			max=sum[i];
		}
	}
	cout<<max;
	*/
	return 0;
}