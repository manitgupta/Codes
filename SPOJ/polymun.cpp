#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int t,n,cof1,cof2,sum;
	vector<int> p1;
	vector<int> p2;
	vector<int> product;
	scanf("%d",&t);
	for (int i = 0; i < t; ++i)
	{
		sum=0;
		scanf("%d",&n);
		for (int j = 0; j <= n; ++j)
		{
			scanf("%d",&cof1);
			p1.push_back(cof1);
		}
		for (int j = 0; j <= n; ++j)
		{
			scanf("%d",&cof2);
			p2.push_back(cof2);
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
		for(int j=0;j!=product.size();j++)
		{
			cout<<product[j]<<' ';
		}
		cout<<endl;
		return 0;	
	}
}