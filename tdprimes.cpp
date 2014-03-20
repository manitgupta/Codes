#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int flag;
	long int count=0;
	for(long int i=2;i<100000000;i++)
	{
		flag=0;
		for(long int j=2;j<=sqrt(i);j++)
		{
			if(i%j==0)
			{
				flag++;
			}
		}
		if(flag==0)
		{	
			count++;
			if(count%100==1)
			{
				cout<<i<<endl;
			}
		}
	}
return 0;
}