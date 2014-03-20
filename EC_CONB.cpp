#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long int t,n;
	long int bin[1000000];
	cin>>t;
	for (int i = 0; i <t; i++)
	{
			long int newnum=0,j=0;
			cin>>n;
			if(n%2==0)
			{
				while(n>0)
				{
					bin[j]=n%2;
					n/=2;
					j++;
				};
				for(long int l=0,k=j-1;k>=0;k--,l++)
				{
					newnum+=bin[k]*pow(2,l;)
				}
				cout<<newnum<<endl;
			}
			else
			{
				cout<<n<<endl;
			}
	}
}