#include <iostream>

using namespace std;

int main()
{
	unsigned long long int t,n,i,j,rem;
	unsigned long long int candy[100000];
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n;						//good question. We can reduce the memory required for the program by finding the remainders and summing them up.
											
		rem=0;
		for(j=0;j<n;j++)
		{
			cin>>candy[j];
			rem+=candy[j]%n;
		}
		if(rem%n==0)
		{
			cout<<"YES"<<endl;
		}
		else
			cout<<"NO"<<endl;
	}
	return 0;
}