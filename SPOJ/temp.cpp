#include <iostream>

using namespace std;

int main()
{
	int t,n,portal;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		for(int j=0;j<n;j++)
		{
			cin>>portal;
			if(portal>=0)
			{
				int test = portal;
				while(test>=0)
				{
					if((test%3==0)||(test%4==0))
					{
						test = -4;
						break;
					}
					else if(((test-4>=0)&&((test-4)%3==0))||((test-3>=0)&&((test-3)%4==0)))
					{
						test = -4;
						break;
					}
					else
					{
						test = test-4;
					}
				}
				cout<<test<<' ';				
			}
			else
			{
				cout<<portal<<' ';
			}
		}
		cout<<endl;
	}
	return 0;
}