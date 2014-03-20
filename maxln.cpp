#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int t;
	float r;
	cin>>t;
	for (int i = 0; i <t; i++)
	{
		cin>>r;
		float ans = (4*r*r+0.25);
		cout<<"Case "<<i+1<<": "<<setprecision(2)<<fixed<<ans<<endl;
	}
	return 0;
}