#include <iostream>

using namespace std;

#define max(a,b) ((a>b)? a:b)
#define min(a,b) ((a>b)? b:a)

int main()
{
	int b,r,g,high2,low;
	cin>>b>>r>>g;
	int highest = max(max(b,g),r);
	int lowest = min(min(b,g),r);
	int other  = ((b+g+r) - (highest + lowest));
	cout<<highest+other+1;
	return 0;


}