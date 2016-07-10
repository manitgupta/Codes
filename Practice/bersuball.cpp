#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

//http://www.codeforces.com/problemset/problem/489/B
int main()
{
	//freopen("input.txt", "r",stdin);
	int n,m,b,g;
	int result = 0;
	vector<int> boys, girls;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>b;
		boys.push_back(b);
	}
	cin>>m;
	for (int i = 0; i < m; ++i)
	{
		cin>>g;
		girls.push_back(g);
	}
	sort(boys.begin(), boys.end());
	sort(girls.begin(), girls.end());
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(abs(boys[i] - girls[j]) <= 1)
			{
				girls[j] = INT_MAX;
				result++;
				break;
			}
		}
	}
	cout<<result<<endl;
	return 0;
}