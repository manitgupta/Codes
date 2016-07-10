#include <cmath>
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>


#define N 8

using namespace std;

int solveKTUtil(int i, int j, int moveNum, int sol[][N], int xMove[], int yMove[])
{
	
	if(moveNum == N*N)
		return 1;

	int new_x,new_y;
	for (int k = 0; k < 8; ++k)
	{
		new_x = i + xMove[k];
		new_y = j + yMove[k];
		if (new_x >= 0 && new_x < N && new_y >=0 && new_y < N && sol[new_x][new_y] == -1)
		{
			sol[new_x][new_y] = moveNum;
			if (solveKTUtil(new_x, new_y, moveNum+1,sol,xMove,yMove) == 1)
				return 1;
			else
				sol[new_x][new_y] = -1;
		}
	}
	return 0;
}

void solveKT()
{
	int sol[N][N];
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
				sol[i][j] = -1;
		}
	}
	
	//int xMove[8] = {-2, -2, 2,  2, -1, -1, 1, 1 };
	//int yMove[8] = { 1, -1, 1, -1,  2, -2, 2, -2 };

	int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
	sol[0][0] = 0;
	if(solveKTUtil(0,0,1,sol,xMove,yMove) == 0)
	{
		cout<<"Solution does not exist"<<endl;
		return;
	}
	else
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cout<<sol[i][j]<<" ";
			}
			cout<<endl;
		}
	}
}


int main()
{
	solveKT();
	return 0;
}