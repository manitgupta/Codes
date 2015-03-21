#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> quad;
	vector<int> nilo;
	int t,q,n,count=0,p=0,r=0;
	scanf("%d",&t);
	for (int i = 0; i < t; i++)
	{	
		scanf("%d",&q);
		quad.push_back(q);
	}
	for (int i = 0; i < t; i++)
	{
		scanf("%d",&n);
		nilo.push_back(n);
	}
	sort(quad.begin(),quad.end());
	sort(nilo.begin(), nilo.end());
	while(p<t && r<t)
	{
		if(nilo[p]>quad[r])
		{
			count++;
			p++;
			r++;
		}
		else
		{
			p++;
		}
	}
	printf("%d",count);
	return 0;
}