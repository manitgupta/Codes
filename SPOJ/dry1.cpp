#include <iostream>
#include <cstdlib>

using namespace std;

int compare (const void * a, const void * b)
	{
  		return ( *(int*)a - *(int*)b );
	}

int main()
{
	int t,n,k,arr[101],sum,count;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		count = 0;
		sum =0;
		cin>>n>>k;
		for(int j=0;j<n;j++)
		{
			cin>>arr[j];
		}
		for(int j=0;(j<n)&&(count<k);j++)
		{
			if(arr[j]<0)
			{
				arr[j]*=-1;
				count++;
			}		
		}
		if(count<k)
		{
			qsort(arr,n,sizeof(int),compare);
		}
		for(int j =0;j<(k-count);j++)
		{
			arr[0]*=-1;
		}
		for(int j=0;j<n;j++)
		{
			sum+=arr[j];
		}
		cout<<sum<<endl;
	}
}