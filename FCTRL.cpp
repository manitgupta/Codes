#include <iostream>
using namespace std;

int main()
{
	long long int t,n,k;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		k=0;
		cin>>n;
		while(n>0)
		{
			k+=(n/5);
			n/=5;
		}
		cout<<k<<endl;
	}
	return 0;
}