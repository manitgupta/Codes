#include <iostream>

using namespace std;

void prime(long int a[],long int b[], int t)
{
	int flag;
	for(int i=0;i<t;i++)
	{
		for(long int j=a[i];j<=b[i];j++)
		{	
			flag=0;
			for(long int k=1;k<=j;k++)
			{
				if(j%k==0)
				{
					flag++;
				}
			}
			if(flag==2)
				cout<<j<<endl;	
		}
		cout<<endl;
	}
}
int main()
{
		int t;
		long int m[10],n[10];
		cin>>t;
		cout<<endl;
		for(int i=0;i<t;i++)
		{
			cin>>m[i]>>n[i];
		}
		prime(m,n,t);
return 0;
}

