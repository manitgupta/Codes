#include <iostream>

using namespace std;

int main()
{
	int n;
	while(true)
	{	
		cin>>n;
		if(n!=0)
		{

			int sum=0;
			for(int j=1;j<=n;j++)
			{
				sum+=j*j;
			}
			cout<<sum<<endl;
		}
		else if(n==0)
			{
				break;
			}	
	}
	return 0;
}