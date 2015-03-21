#include <iostream>

using namespace std;

int main()
{
	unsigned long int t,n,obs,popln,count;
	cin>>t;
	for (int i=0;i<t;i++)
	{
		count =0;
		popln =1; 
		cin>>n;
		cin>>obs;
		if(obs<=1)
		{
			count++;
		}
		for(int j=2;j<=n;j++)
		{
			cin>>obs;
			popln*=2;
			if(obs<=popln)
			{
				count++;
			}
		}
		if(count==n)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}