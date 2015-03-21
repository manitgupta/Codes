#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	double r1,r2,r3,r4,ra,rb;

	int t;
	cin>>t;
	for (int i = 0; i < t; i++)
	{
		cin>>r1>>r2>>r3;
		ra = (r1*r2*r3)/(r1*r2 + r2*r3 + r3*r1 + 2*sqrt((r1*r2*r3)*(r1+r2+r3)));
		rb = (r1*r2*r3)/(r1*r2 + r2*r3 + r3*r1 - 2*sqrt((r1*r2*r3)*(r1+r2+r3)));
		if((ra<r1)&&(ra<r1)&&(ra<r2)&&(ra<r3)&&(ra>0))
		{
			cout<<setprecision(6)<<fixed<<ra<<endl;
		}
		else if((rb<r1)&&(rb<r1)&&(rb<r2)&&(rb<r3)&&(rb>0))
		{
			cout<<setprecision(6)<<fixed<<rb<<endl;
		}
	}
}