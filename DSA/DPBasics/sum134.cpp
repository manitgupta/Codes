#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define _DEBUG

#define Inf 2147483647
#define Max(a, b)  (a < b ? b : a)
#define Min(a, b)  (a > b ? b : a)
#define INT_MIN -99999999

#define MAXN 500


//PROBLEM
//Let us say that you are given a number N, you've to find the 
//number of different ways to write it as the sum of 1, 3 and 4.

//SOLUTION
// LET N = x1 + x2 +x3 .... +xn, be the problem denoted by DP(n) (for all xn belonging to (0,1,3,4))
//Now, if the last "xn" variables equals 1, then sum of rest is N-1
// Hence for variables x1 + x2 + x3.... x(n-1), the problem becomes
//"GIVEN A NUMBER N-1, FIND NUMBER OF DIFFERENT WAYS TO WRITE IT AS SUM OF 1,3 AND 4"
// This is nothing but the problem DP(n-1)
//Similarly if it ends with 3 or 4, We have the solution

// DP(n) = DP(n-1) + DP(n-3) + DP(n-4)
//Also base cases, DP(0) = 1, DP(1) = 1, DP(2) = 1, DP(3) = 2...we will see if we need more.//

int breakups_recur(int n)
{
	if (n <= 2)
		return 1;
	if (n == 3)
		return 2;
	else
		return (breakups_recur(n-1) + breakups_recur(n-3) + breakups_recur(n-4));
}

int breakups_dyn(int n)
{
	int dp[MAXN];
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;
	for (int i = 4; i <= n; ++i)
	{
		dp[i] = dp[i-1] + dp[i-3] + dp[i-4];
		cout<<"dp["<<i<<"] ="<<dp[i]<<endl;
	}
	return dp[n];
}

int main()
{
	cout<<breakups_dyn(50)<<endl;
	return 0;
}