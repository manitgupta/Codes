#include <iostream>

using namespace std;

int main()
{
	long int t,n;
	long int r[1002];
	long int R[1002];
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		for(int j=0;j<n;j++)
		{
			cin>>r[j]>>R[j];
		}
		long int index=0,large=r[0]; //ring of largest internal radius.
		for (int j = 1; j <n; j++)
		{
			if(large<r[j])
			{
				large=r[j];
				index=j;
			}
		}
		long int count=1;
		for (int j = 0; j <n; ++j)
		{
			if(index!=j)
			{
				if(large>R[j])
				{
					count++;
				}
			}
		}
		if(count==n)
		{
			cout<<index+1;
		}
		else
			cout<<-1;
		cout<<endl;
	}
	return 0;
}