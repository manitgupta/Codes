#include <iostream>

using namespace std;

int main()
{
	int t,perm[100001],revperm[100001],count,temp;
	while(true)
	{
		cin>>t;
		if(t==0)
		{
			break;
		}
		else
		{
			count =0;
			for (int i = 0; i < t; i++)
			{
				cin>>perm[i];
			}
			for (int i = 0; i < t; i++)
			{
				temp = perm[i];
				revperm[temp-1] = i+1;			
			}
			for(int i=0;i<t;i++)
			{
				if(revperm[i]==perm[i])
					count++;		
			}
			if(count==t)
				cout<<"ambiguous"<<endl;
			else
				cout<<"not ambiguous"<<endl;

		}
	}
}