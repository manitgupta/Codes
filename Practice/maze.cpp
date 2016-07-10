#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;
//http://www.codeforces.com/problemset/problem/377/A

void printMat(vector<string>& maze)
{
	for (int i = 0; i < maze.size(); ++i)
	{
		cout<<maze[i]<<endl;
	}
}

bool isSafe(vector<string>& maze,int n, int m, int x, int y, vector<vector<bool> >& visited)
{
	if(x>=0 && x < n && y >= 0 && y < m && maze[x][y] != '#' && !visited[x][y])
		return true;
	return false;
}

void DFS(vector<string>& maze,int n, int m, int x, int y, int &oppK, vector<vector<bool> >& visited)
{
	// cout<<"oppK="<<oppK<<endl;
	if(oppK <= 0)
		return;
	visited[x][y] = true;
	if(isSafe(maze,n,m,x,y+1,visited))
	{
		if(oppK > 0)
		{
			//maze[x][y+1] = 'Q';
			oppK = oppK-1;
			DFS(maze,n,m,x,y+1,oppK,visited);
		}
		else
			return;
	}
	if(isSafe(maze,n,m,x-1,y,visited))
	{
		if(oppK > 0)
		{
			//maze[x-1][y] = 'Q';
			oppK = oppK-1;
			DFS(maze,n,m,x-1,y,oppK,visited);
		}
		else
			return;
	}
	if(isSafe(maze,n,m,x,y-1,visited))
	{
		if(oppK > 0)
		{
			//maze[x][y-1] = 'Q';
			oppK = oppK-1;
			DFS(maze,n,m,x,y-1,oppK,visited);
		}
		else
			return;
	}
	if(isSafe(maze,n,m,x+1,y,visited))
	{
		if(oppK > 0)
		{
			//maze[x+1][y] = 'Q';
			oppK = oppK-1;
			DFS(maze,n,m,x+1,y,oppK,visited);
		}
		else
			return;
	}
}

int main()
{	int n,m,k;
	int emptyCounter = 0;
	char temp;
	// freopen("input.txt","r", stdin);
	cin>>n>>m>>k;
	vector<string> maze(n);
	vector<vector<bool> >visited(n, vector<bool>(m));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin>>temp;
			if(temp == '.')
				emptyCounter++;
			maze[i].push_back(temp);
			visited[i][j] = false;
		}
	}
	// printMat(maze);
	int val = emptyCounter-k;
	// cout<<"emptyCounter = "<<emptyCounter<<"k = "<<k<<endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(!visited[i][j] && maze[i][j] == '.')
				DFS(maze,n,m,i,j,val,visited);
		}
	}
	// printMat(maze);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(!visited[i][j] && maze[i][j] == '.')
				maze[i][j] = 'X';
		}
	}
	printMat(maze);
	return 0;
}