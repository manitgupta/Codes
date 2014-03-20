#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	int t;
	float s,ans;
	cin>>t;
	for (int i = 0; i < t; ++i)
	{
		cin>>s;
		ans = (1 - (1.0/3)*sqrt(2/s));
		cout<<setprecision(6)<<fixed<<ans<<endl;
		
	}
	return 0;
}