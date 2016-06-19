#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long int coinChange_dp(int S[], long long int m, long long int n)
{
	long long int dp[m+1][n+1]; //2D array to store solutions for m coins and n total value
	for (int i = 1; i <= n; ++i)
	{
		dp[0][i] = 0;		//if there are 0 coins, no solution for any value except when n is 0 
	}
    for(int i =0 ; i <=m ; i++)
    {
        dp[i][0] = 1;
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
	return dp[m][n];
}

int main() {
    
    long long int m, n;
    cin >> n>>m;
    int arr[n];
    for(int i = 0; i < m; i++)
        cin>>arr[i];
    cout<<coinChange_dp(arr, m, n);
    return 0;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
}