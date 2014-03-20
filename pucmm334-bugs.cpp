#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n,whats[101],wppl=0,bppl=0,error=0,count=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&whats[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		if(whats[i]==0)
		{
			count++;
		}
	}
	if(count==n)
	{
		error = 1;
		cout<<0;
	}
	else
	{
		for(int r=2;r<=n;r++)
		{	
			for(int i=0;i<n;i++)
			{
			if(whats[i]==r-1)
				{
					wppl++;
				}
				else if(whats[i]==r)
				{
					bppl++;
				}
				else
				{
					error = 1;
					cout<<-1;
					break;
				}
				}
			if((wppl==r)&&(bppl==n-r))
			{
				break;
			}	
			else
			{
				wppl=0;
				bppl=0;	
			}
		}
	}
	if(error==0)
	{
		cout<<wppl;
	}
	return 0;
}