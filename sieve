#include <iostream>

using namespace std;

int main()
{
	int i,j;
	int num[1000],prime[1000];
	int lb,ub;
	cin>>lb>>ub;
	for(i=0;i<=ub;i++)
	{
		num[i]=i+2;
	}
	for(i=0;i<=ub;i++)
	{
		if(num[i]!=-1)
		{
			for(j=2*num[i]-2;j<=ub;j+=num[i])
			{
				num[j]=-1;
			}
		}
	}
	j=0;
	for(i=0;i<=ub;i++)
	{
		if(num[i]!=-1)
		{
			prime[j++]=num[i];
		}
	}
	for(int k=0;k<j;k++)
	{
		cout<<prime[k]<<endl;
	}
	return 0;
}
