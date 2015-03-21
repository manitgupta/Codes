#include <iostream>

using namespace std;

int main()
{
	int n,pos,count=0;
	int arr[20002] = {0};
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>pos;
		arr[pos] = 1;
		if(arr[pos-1]==0 && arr[pos+1]==0)
			count++;
		else if(arr[pos-1]==1 && arr[pos+1]==1)
			count--;
		cout<<count<<endl;
	}
	cout<<"Justice"<<endl;
	return 0;
}