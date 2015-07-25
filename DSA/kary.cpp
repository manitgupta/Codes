#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;							//Generate strings on length n from k bit set.

int A[5];

void kary(int n, int k)
{
	if (n < 1)
	{
		for (int i = 0; i < 5; ++i)
		{
			printf("%d",A[i]);
		}
		printf("\n");
	}
	else
	{
		for (int j = 0; j < k; ++j)
		{
			A[n-1] = j;
			kary(n-1,k);
		}
	}
}

int main()
{
	kary(5,3);
	return 0;
}