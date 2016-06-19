#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

#define R 3
#define C 3

int min(int x, int y, int z)
{
   if (x < y)
      return (x < z)? x : z;
   else
      return (y < z)? y : z;
}

int minCost(int cost[R][C], int m, int n)
{
	int ans[R][C];
	/* Initialize first column of total cost(tc) array */
    ans[0][0] = cost[0][0]; 
     for (int i = 1; i <= m; i++)
        ans[i][0] = ans[i-1][0] + cost[i][0];
 
     /* Initialize first row of ans array */
     for (int j = 1; j <= n; j++)
        ans[0][j] = ans[0][j-1] + cost[0][j];
	for (int i = 1; i < R; ++i)
	{
		for (int j = 1; j < C; ++j)
		{
			ans[i][j] = min(cost[i][j] + ans[i-1][j-1], cost[i][j] + ans[i-1][j], cost[i][j] + ans[i][j-1]);
		}
	}
	return ans[m][n];
}
int main()
{
	int cost[R][C] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
    
    printf(" %d ", minCost(cost, 2, 2));
   	return 0;
}