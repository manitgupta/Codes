#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

void printMat(vector<string>& board)
{
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[i].size(); ++j)
		{
			cout<<board[i][j];
		}
		cout<<endl;
	}
}

bool isSafe(vector<string>&board, int row, int col, vector<vector<int> >& visited)
{
	if(row >= 0 && row < board[0].size() && col >=0 && col < board.size() && board[row][col] == '.' && !visited[row][col])
		return true;
	return false;
}

void putChessMan(vector<string>& board, int row, int col, vector<vector<int> >&visited, bool colorFlag)
{
	visited[row][col] = 1;
	if(colorFlag)
		board[row][col] = 'B';
	else
		board[row][col] = 'W';
	if(isSafe(board, row, col+1,visited))
	{
		putChessMan(board, row, col+1, visited, !colorFlag);
	}
	if(isSafe(board, row-1, col,visited))
	{
		putChessMan(board, row-1, col, visited, !colorFlag);
	}
	if(isSafe(board, row, col-1,visited))
	{
		putChessMan(board, row, col-1, visited, !colorFlag);
	}
	if(isSafe(board, row+1, col,visited))
	{
		putChessMan(board, row+1, col, visited, !colorFlag);
	}
}

int main()
{	
	int n,m;
	char inp;
	freopen("input.txt","r",stdin);
	cin>>n>>m;
	vector<string> board(n);
	vector<vector<int> > visited(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin>>inp;
			board[i].push_back(inp);
			visited[i][j] = 0;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(!visited[i][j] && board[i][j] == '.')
			{
				putChessMan(board, i, j, visited, true);
			}
		}
	}
	printMat(board);

	return 0;
}