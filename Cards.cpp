#include <iostream>

using namespace std;

int main()
{
	long long int n,t;
	long long int tcards;				//lol. Spoj problem!
	cin>>t;
	for(int i=0;i<t;i++)
	{
		tcards=0;
		cin>>n;
		tcards= (n*(3*n+1))/2;
		cout<<tcards%1000007<<endl;
	}
	return 0;
}