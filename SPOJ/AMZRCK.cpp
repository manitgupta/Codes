#include <iostream>

using namespace std;

int main()
{
	long long int n,t;
	long long int f[44],ans;   // WA on spoj
	f[0]=1;
	f[1]=1;
	cin>>t;
	for(long long int j=0;j<t;j++)
	{
		ans=2;
		cin>>n;
		for(long long int i=2;i<=n;i++)
		{
			f[i]=0;
			for(long long int j=0;j<=i-2;j++)
			{
				f[i]+=f[j];
			}
			ans+=f[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}