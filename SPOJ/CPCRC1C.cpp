#include <iostream>

using namespace std;

int sumofdigits(int n)
{
	int dig,sum=0;
	while(n>0)
	{
		dig=n%10;
		sum+=dig;
		n/=10;
	}
	return sum;
}
int main()
{
	int a,b,ans;
	while(true)
	{
		ans=0;
		cin>>a>>b;
		if((a==-1)&&(b==-1))
		{
			break;
		}
		for(int i=a;i<=b;i++)
		{
			ans+=sumofdigits(i);
		}
		cout<<ans<<endl;
	}
	return 0;
}