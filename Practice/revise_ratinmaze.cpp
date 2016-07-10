#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

bool isSafe(int x, int y, int maze[][100], int N, int sol[][100])
{
	if(x >= 0 && x < N && y>= 0 && y < N && maze[x][y] != 0 && sol[x][y] != 1)
		return true;
	return false;
}

bool findPath(int maze[][100], int sol[][100], int x, int y, int N)
{
	if(x == N-1 && y == N-1)
		return true;
	if(isSafe(x,y+1,maze,N,sol))
	{
		sol[x][y+1] = 1;
		if(findPath(maze, sol, x,y+1,N) == true)
			return true;
		sol[x][y+1] = 0;
	}
	if(isSafe(x-1,y,maze,N,sol))
	{
		sol[x-1][y] = 1;
		if(findPath(maze, sol, x-1,y,N) == true)
			return true;
		sol[x-1][y] = 0;
	}
	if(isSafe(x,y-1,maze,N,sol))
	{
		sol[x][y-1] = 1;
		if(findPath(maze, sol, x,y-1,N) == true)
			return true;
		sol[x][y-1] = 0;
	}
	if(isSafe(x+1,y,maze,N,sol))
	{
		sol[x+1][y] = 1;
		if(findPath(maze, sol, x+1,y,N) == true)
			return true;
		sol[x+1][y] = 0;
	}
	return false;
}

void printMat(int mat[][100], int N)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{	
	int N;
	int maze[100][100];
	int sol[100][100];
	freopen("input.txt","r",stdin);
	cin>>N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin>>maze[i][j];
			sol[i][j] = 0;
		}
	}

	printMat(maze,N);
	cout<<endl;
	sol[0][0] = 1;
	findPath(maze, sol, 0, 0,N);
	printMat(sol,N);
	return 0;
}