#include <stdio.h>

void main()
{
	int A[] = {0,0,0,0,0,1,1,2,2,2,1,1,0,0,0,0};
	int zeroCount=0, oneCount=0, twoCount=0;
	int i;
	int n = sizeof(A)/sizeof(A[0]);
	for (i = 0; i < n; ++i)
	{
		if(A[i] == 0)
			zeroCount++;
		else if(A[i] == 1)
			oneCount++;
		else if(A[i] == 2)
			twoCount++;
	}
	printf("%d,%d,%d\n",zeroCount,oneCount,twoCount);
	i=0;
	while(i < zeroCount)
		A[i++] = 0;
	while(i < zeroCount + oneCount)
		A[i++] = 1;
	while(i < zeroCount + oneCount + twoCount)
		A[i++] = 2;

	for (i = 0; i < n; ++i)
	{
		printf("%d ",A[i]);
	}
	printf("\n");
}