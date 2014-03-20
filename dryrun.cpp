#include <iostream>

using namespace std;

int lsearch(int arr[100001], int n, int t)
{
	int i;
	for(i=0;i<t;i++)
	{
		if(arr[i]==n)
			break;
	}
	return i+1;
}
int main()
{
	int t,perm[100001],revperm[100001];
	for(;(cin>>t)!=0;)
	{
		for(int i=0;i<t;i++)
		{
			cin>>perm[i];
		}
		for(int i=0;i<t;i++)
		{
			revperm[i] = lsearch(perm,i+1,t);
			cout<<revperm[i]<<' ';
		}
		cout<<endl;
	}
}