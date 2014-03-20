#include <iostream>

using namespace std;

int main()
{
	int t;
	long long int n,m;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n>>m;
		if(m==0){cout<<1<<endl;}
		if((n%10==1)&&(m>0)){cout<<1<<endl;}
		if(n%5==0&&m>0){cout<<5<<endl;}
		if((n%10==2)&&(m>0))
		{
			if((m-1)%4==0{cout<<2<<endl;}
			if((m-1)%4==0){cout<<2<<endl;}
			if((m-2)%4==0){cout<<4<<endl;}
			if((m-3)%4==0){cout<<8<<endl;}
			if(m%4==0){cout<<6<<endl;}
		}
		if((n%10==3)&&(m>0))
		{
			if((m-1)%4==0){cout<<3<<endl;}
			if((m-2)%4==0){cout<<9<<endl;}
			if((m-3)%4==0){cout<<7<<endl;}
			if(m%4==0){cout<<1<<endl;}
		}
		if((n%10==4)&&(m>0))
		{
			if((m-1)%2==0){cout<<4<<endl;}
			if(m%2==0){cout<<6<<endl;}		
		}
		if((n%10==6)&&(m>0)){cout<<6<<endl;}
		if((n%10==0)&&(m>0))
		{cout<<0<<endl;
		}
		if((n%10==7)&&(m>0))
		{
			if((m-1)%4==0){cout<<7<<endl;}
			if((m-2)%4==0){cout<<9<<endl;}
			if((m-3)%4==0){cout<<3<<endl;}
			if(m%4==0){cout<<1<<endl;}
		}
		if((n%10==8)&&(m>0))
		{
			if((m-1)%4==0){cout<<8<<endl;}
			if((m-2)%4==0){cout<<4<<endl;}
			if((m-3)%4==0){cout<<2<<endl;}
			if(m%4==0){cout<<6<<endl;}
		}
		if((n%10==9)&&(m>0))
		{
			if((m-1)%2==0){cout<<9<<endl;}
			if(m%2==0){cout<<1<<endl;}
		}
	}
	return 0;
}