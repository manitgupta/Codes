#include  <iostream>

using namespace std;

int main()
{
	int n,a[12];
	int f[12],largest=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for (int i = 0; i < n; i++)
	{
		f[i]=1;
		for(int j=0;j<i;j++)
		{
			if((a[i]>a[j])&&(f[i]<=f[j]))
			{
				f[i]=f[j]+1;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(largest<f[i])
		{
			largest=f[i];
		}
	}
	cout<<largest;
	return 0;
}