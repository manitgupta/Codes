#include <iostream>
#include <cstdlib>

using namespace std;

int compare (const void * a, const void * b)
	{
  		return ( *(int*)a - *(int*)b );
	}
int main()
{
	int n,t,sum;
	int men[1001],women[1001];
	cin>>t;
	for(int i=0;i<t;i++)
	{
		sum=0;
		cin>>n;
		for (int j = 0; j<n;j++)
		{
			cin>>men[j];
		}
		for(int j=0;j<n;j++)
		{
			cin>>women[j];
		}
		qsort(men,n,sizeof(int),compare);
		qsort(women,n,sizeof(int),compare);
		for(int j=0;j<n;j++)
		{
			sum+=men[j]*women[j];
		}
		cout<<sum<<endl;
	}
}