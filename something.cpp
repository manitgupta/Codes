#include <iostream>
using namespae std;

int checkpalin(int k[100001])
{
	 unsigned int length;
	 for(length=0;k[length]!='\0';length++);  //find the length
	 for(int c=0;(c<length/2)&&(k[c]==k[length-c-1]);c++);
	 return (c==length/2)? 1:0;
}
int main()
{
	long int t,p;
	char num[100001];
	int k[100001];
	cin>>t;
	for (int i = 0; i <t; i++)
	{
		cin>>num;
		p=strlen(num);
		for(int j=0;j<p;j++)
		{
			k[j]=num[j]-'0';
		}
		while(true)
		{
			
		}


	}

}