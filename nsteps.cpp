#include <iostream>

using namespace std;

int main()
{
	int x,y,t;
	cin>>t;
	for(int j=0;j<t;j++)
	{
		cin>>x>>y;
		if((x%2==0)&&(y%2==0)&&(x==y))
		{
			cout<<x+y<<endl;
		}
		else if((x%2==1)&&(y%2==1)&&(x==y))
		{
			cout<<x+y-1<<endl;
		}
		else if((x%2==0)&&(y%2==0)&&(y==x-2))
		{
			cout<<x+y<<endl;
		}
		else if((x%2==1)&&(y%2==1)&&(y==x-2))
		{
			cout<<x+y-1<<endl;
		}
		else
		{
			cout<<"No Number"<<endl;
		}
	}
	return 0;
}