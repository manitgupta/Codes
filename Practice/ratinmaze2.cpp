#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

#define N 4

int isAllowed(int x, int y, int maze[][N])
{
	if (x >=0 && x<N && y>=0 && y<N && maze[x][y] == 1)	//boundary conditions are met and (x,y) is not blocked
		return 1;
	return 0;
}

int findPath(int x, int y, int maze[][N], int sol[][N])
{
	if(x == N-1 && y == N-1)	//base case, reached bottomleft corner
		return 1;

	if(isAllowed(x,y+1,maze))
	{
		sol[x][y+1] = 1;
		//cout<<x<<" "<<y+1<<endl;
		if( findPath(x,y+1,maze,sol) == 1)
			return 1;
		else
			sol[x][y+1] = 0;
	}
	if(isAllowed(x+1,y,maze))
	{
		sol[x+1][y] = 1;
		//cout<<x+1<<" "<<y<<endl;
		if (findPath(x+1,y,maze,sol) == 1)
			return 1;
		else
			sol[x+1][y] = 0;
	}
	return 0;
}

int main()
{
	int maze[N][N] = { {1,1,1,1},
						{1,0,0,0},
						{1,1,1,1},
						{0,0,0,1}
	};

	int sol[N][N];
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			sol[i][j] = 0;
		}
	}
	sol[0][0] = 1;
	findPath(0,0,maze,sol);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout<<sol[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}