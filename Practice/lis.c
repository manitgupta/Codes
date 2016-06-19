#include <stdio.h>


int lis(int arr[], int n)
{
	int len[n];
	len[0] = 1;
	int i,j;
	int max = -1;
	//set length of all equal to 1
	for(i = 0; i < n; i++)
		len[i] = 1;
	for(i = 1; i < n; i++)
	{
		for(j = 0; j < i; j++)
		{
			if(arr[i] > arr[j] && len[i] < len[j] + 1)
				len[i] = len[j] + 1;
		}
	}
	for(i = 0; i < n; i++)
	{
		if (max < len[i])
			max = len[i];
	}
	return max;
}

int main()
{

    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = lis(arr, n);
    printf("ans = %d\n",ans);
	return 0;
}