#include <iostream>
using namespace std;

int checkpalin(unsigned long long int k)
{
	unsigned long long int dig,num,sample;
	sample=k;							//code won't work on spoj. Input too large.Requires use of strings.
	num=0;
	while(sample>0)
	{
		dig=sample%10;
		num=num*10+dig;
		sample/=10;
	}
	if(num==k)
	{
		return 1;
	}
	else
		return 0;
}
int main()
{
	unsigned long long int t,k,i;
	cin>>t;
	for (i = 0; i < t;i++)
	{
		cin>>k;
		while(true)
		{
			k++;
			int ans=checkpalin(k);
			if(ans==1)
			{
				cout<<k<<e;
				break;
			}
		}
	}
}