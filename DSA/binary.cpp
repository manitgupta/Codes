#include <iostream>
#include <cstdio>

using namespace std;				//generate binary strings on length n

char A[5];

void Binary(int n)
{
	if(n<1)
	{
		printf("%s\n",A);
	}
	else
	{
		A[n-1] = '0';
		Binary(n-1);
		A[n-1] = '1';
		Binary(n-1);
	}
}

int main()
{
	Binary(5);
	return 0;
}