#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

bool isSafe(int x, int y, int grid[8][8])
{
	if(x >= 0 && x < 8 && y >= 0 && y < 8 && grid[x][y] == -1)	//-1 means position is available
		return true;
	return false;
}

bool SolveKT(int x, int y, int moveCount, int grid[8][8], int xMove[], int yMove[])
{
	if(moveCount ==  64)
		return true;
	for (int i = 0; i < 8; ++i)
	{
		if(isSafe(x + xMove[i], y + yMove[i], grid))	//means move is valid
		{
			x = x + xMove[i];
			y = y + yMove[i];
			grid[x][y] = moveCount;
			if(SolveKT(x, y, moveCount+1, grid, xMove, yMove) == true)
				return true;
			grid[x][y] = -1;
			//returned false, means backtrack reqd
		}
	}
	return false;
}

int main()
{
	int grid[8][8];
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			grid[i][j] = -1;
		}
	}

	int xMove[8] = {2, 1,-1,-2,-2,-1, 1, 2};
	int yMove[8] = {1, 2, 2, 1,-1,-2,-2,-1};

	grid[0][0] = 0;
	if(SolveKT(0,0,1,grid,xMove,yMove) == true)
	{
		cout<<"Solution is:"<<endl;
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				cout<<grid[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	else
	{
		cout<<"No Solution";
	}
	return 0;
}