#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int BinarySearch(const vector<int>& A, int n, int data)
{
	int low = 0;
	int high = n-1;
	while(low <=high)
	{
		int mid = (low+high)/2;
		if(A[mid] == data)
			return mid;
		else if(A[mid] < data)
			low = mid+1;
		else
			high = mid-1;
	}
	return -1;
}

int main()
{
	vector<int> A(10);
	cout<<A.size()<<endl;
	for (int i = 0; i < A.size(); ++i)
	{
		A[i] = rand()%100;
	}
	sort(A.begin(), A.end());
	for (int i = 0; i < A.size(); ++i)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
	int data = 86;
	int index = BinarySearch(A,10,data);
	if(index != -1)
	{
		cout<<"Data "<<data<<" present at index "<<index<<endl;
	}
	else
		cout<<"Not Found"<<endl;
	return 0;
}