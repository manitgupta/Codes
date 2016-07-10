#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define N 4
#define INF 99999

int min(int a, int b)
{
	return (a < b)? a:b;
}

int minCost(int dest, int src, int cost[][N])
{
	if (src == dest || src+1 == dest)
		return cost[src][dest];

	int min_val = cost[src][dest];
	for (int i = src+1; i <= dest; ++i)
	{
		for (int j = src+1; j <= i; ++j)
		{
			min_val = min(min_val, cost[src][j] + minCost(i,j,cost) + cost[i][dest]);
			//cout<<min_val<<endl;
		}
	}
	return min_val;
}

int minCost_dp(int dest, int src, int cost[][N])
{
	int minCost[N+1][N+1]; 		//minCost[src][dest] is the minvalue from src to dest

	for (int i = 0; i < N; ++i)	//base conditions
	{
		minCost[i][i] = cost[i][i];
		minCost[i][i+1] = cost[i][i+1];
	}

	for(int i = 0; i <N; i++)
	{
		for (int j = 0; j <=i; ++j)
		{
			minCost[i][j] = cost[i][j];
			for (int p = j+1; p <= i; ++p)
			{
				for (int q = j+1; q <= p; ++q)
				{
					minCost[i][j] = min(minCost[i][j], cost[j][q] + minCost[p][q] + cost[p][i]);
			//cout<<min_val<<endl;
				}
			}
			/* code */
		}
	}
	return minCost[dest][src];
}

int main()
{
	int cost[N][N] = { {0, 15, 80, 90},
              {INF, 0, 40, 50},
              {INF, INF, 0, 70},
              {INF, INF, INF, 0}
             };
    cout<<minCost_dp(N-1,0,cost)<<endl;
}