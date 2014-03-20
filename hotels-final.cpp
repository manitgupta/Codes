#include <iostream>
#include <cstdlib>
using namespace std;

int compare (const void * a, const void * b)
	{
  		return ( *(int*)a - *(int*)b );
	}

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
			for(;sum[i]<=m;j++)						//solved and submitted.
			{
				sum[i]+=value[j];
			}
			sum[i]=sum[i]-value[--j];
		}
	}
	//for(int i=0;i<n;i++)
	//{
	//	cout<<sum[i]<<endl;
	//}
	//qsort (sum,n, sizeof(int), compare);
  	//cout<<sum[n-1];
  	int max=sum[0];
	for(int i=0;i<n;i++)
	{
		if(sum[i]>max)
		{
			max=sum[i];
		}
	}
	cout<<max;
	return 0;
}