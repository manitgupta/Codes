#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
	return ( a > b) ? a:b;
}
//Finds the length of the longest common subsequence.
int lcs(char X[], char Y[], int m, int n)
{
	if (m == 0 || n == 0)
		return 0;
	if(X[m-1] == Y[n-1])
	{
		printf("Match!\n");
		return 1 + lcs(X,Y,m-1,n-1);	// Call LCS(X[0....m-2], Y[0....n-2])
	}
	else
		return max(lcs(X,Y,m-1,n), lcs(X,Y,m,n-1));
}



int lcs_dp(char X[], char Y[], int m, int n)
{
	int L[m+1][n+1];
	//L[i][j] contains the length of LCS from X[0...i-1] and Y[0.....j-1]
	int i,j;
	//base case: when either has length 0 then LCS length is 0.
	for(i = 0; i < m; i++)
	{
		L[i][0] = 0;
		L[0][i] = 0;
	}
	for (i = 1; i <= m; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			if (X[i] == Y[j])
				L[i][j] = 1 + L[i-1][j-1];
			else
				L[i][j] = max(L[i-1][j], L[i][j-1]);
		}
	}
	return L[m][n];
}

int main()
{
	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";

	int m = strlen(X);
	int n = strlen(Y);
	int ans = lcs_dp(X,Y,m,n);
	printf("Length = %d\n", ans);
	return 0;
}