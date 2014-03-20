#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char m[100001],n[100001];
	int a[100001],b[100001],c[100001];
	cin>>m>>n;
	long int i,j,k=0;
	i=strlen(m)-1;
	j=strlen(n)-1;
	for(int p=0;p<=i;p++)
	{
		a[p]=m[p]-'0';
	}
	for(int q=0;q<=j;q++)
	{
		b[q]=n[q]-'0';
	}
	c[0]=0;
	while(i>=0)
	{
		if(((c[k]+a[i]+n[j])>=10)&&(j>=0))
		{
			c[k]+=(m[i--]+n[j--])%10;
			c[++k]=1;
		}
		else if(((c[k]+m[i]+n[j])<=10)&&(j>=0))
		{
			c[k]+=m[i--]+n[j--];
			c[++k]=0;
		}
		else
		{
			c[k++]=m[i++];
		}	
	}
	for(int i=0;i<2;i++)
	{
		cout<<c[i];
	}
	return 0;
}