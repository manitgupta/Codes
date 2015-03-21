#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#define gc getchar_unlocked

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

using namespace std;


int main()
{
	int n,c,mess;
	vector<int> v,w,count,single;
	scanint(n);
	scanint(c);
	for (int i = 0; i < n; ++i)
	{
		scanint(mess);
		v.push_back(mess);
		w.push_back(mess);
	}
	sort(w.begin(),w.end());
	for (int i = 0; i < n; ++i)
	{
		if(w[i]!=w[i+1])
		{
			single.push_back(w[i]);
		}
	}
	for(int i=0;i!=single.size();i++)
	{
		cout<<single[i]<<' ';
	}

	return 0;
}