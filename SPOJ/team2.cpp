#include <iostream>

using namespace std;
#define max(a,b) ((a>b)?a:b)

int main()
{
	unsigned long long int a,b,c,d,high1,high2,length,i=0;
	while(((cin>>a)>0)&&((cin>>b)>0)&&((cin>>c)>0)&&((cin>>d)>0))
	{	
		i++;
		high1=max(max(a,b),max(c,d));				//solved and submitted.
		if(high1==d)
		{
			high2=max(max(a,b),c);

		}
		if(high1==c)
		{
			high2=max(max(a,b),d);

		}
		if(high1==b)
		{
			high2=max(max(a,c),d);

		}
		if(high1==a)
		{
			high2=max(max(c,b),d);

		}
		length=high1+high2;
		cout<<"Case "<<i<<": "<<length<<endl;
	}
	return 0;
}