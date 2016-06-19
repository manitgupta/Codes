#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

int coinChange(int S[], int m, int n)
{
	if (n == 0)
		return 1;
	else if (n < 0)	//since n has become 0, exact sum to n couldnt be reached, hence no solution
		return 0;
	else if (n > 0 && m == 0) 	//coins have finished but n is not zero
		return 0;
	else
		return coinChange(S, m-1, n) + coinChange(S, m, n - S[m-1]);

}

int coinChange_dp(int S[], int m, int n)
{
	int dp[m+1][n+1]; //2D array to store solutions for m coins and n total value
	for (int i = 0; i <= n; ++i)
	{
		dp[0][i] = 0;		//if there are 0 coins, no solution for any value except when n is 0 
		dp[i][0] = 1;		//if total value is 0, one solution exists for "i" coins by not taking any of them
	}
	for (int i = 1; i <= m; ++i)	//i is the num of coints
	{
		for (int j = 1; j <= n; ++j) 		//j is the total value
		{
			int x = (j - S[i-1] >= 0)? dp[i][j-S[i-1]] : 0;
			int y = (i >=1)? dp[i-1][j]:0; 
			dp[i][j] = x + y;
		}
	}
	return dp[m-1][n];
}

int main()
{
	int i, j;
    int S[] = {1, 2, 3};
    int m = sizeof(S)/sizeof(S[0]);
    printf("%d ", coinChange_dp(S, m, 4));
    return 0;
}