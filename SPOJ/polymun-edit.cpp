#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int t,n,sum;				//TLE on spoj.
	scanf("%d",&t);
	for (int i = 0; i < t; i++)
	{
		int p1[10002] = {0}; 
		int p2[10002] = {0};
		int product[20012] = {0};
		sum=0;
		scanf("%d",&n);
		for (int j = 0; j <= n; j++)
		{
			scanf("%d",&p1[j]);
		}
		for (int j = 0; j <= n; j++)
		{
			scanf("%d",&p2[j]);
		}
		for(int power=0;power<=2*n;power++)
		{
			for(int j=0;j<=power;j++)
			{
				sum+=p1[j]*p2[power-j];
			}
			product[power] = sum;
			sum=0;
		}
		for(int j=0;j<=2*n;j++)
		{
			printf("%d ",product[j]);
		}
		printf("\n");
	}
	return 0;
}