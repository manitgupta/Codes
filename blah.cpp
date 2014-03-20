#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t,j,l;
	char str[10001];
	char words[100][100];
	cin>>t;
	for(int i=0;i<t;i++)
	{
		l =1;
		getline(cin, str);
		for(j=0;str[j]!='\0';j++)
		{
			if(str[j]==' ')
			{
				l++;
			}
			else
			{
				words[l-1][j] = str[j];
			}
		}
		for(int r=0;r<l;r++)
		{
			for(int c=0;c<j;c++)
			{
				cout<<words[r][c];
			}
			cout<<endl;
		}

	}
	return 0;
}