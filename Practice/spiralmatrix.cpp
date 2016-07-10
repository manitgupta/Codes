#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

void printmatrix(int mat[][100], int N, int M, int x, int y)
{
	if (N <=0 || M <= 0)
	{
		return;
	}
	if (N == 1 && M == 1)
	{
		cout<<mat[x][y]<<" ";
		return;
	}
	for (int i = 0; i < M-1; ++i)	//first line
	{
		cout<<mat[x][y++]<<" ";
	}
	for (int i = 0; i < N-1; ++i)
	{
		cout<<mat[x++][y]<<" ";
	}
	if (N > 1)
	{
		for(int i = 0; i < M-1; i++)
		{
			cout<<mat[x][y--]<<" ";
		}	
	}
	if ( M > 1)	
	{
		for(int i = 0; i < N-1; i++)
		{
			cout<<mat[x--][y]<<" ";
		}	
	}
	if (N == 1 || M == 1)
		printmatrix(mat,1,1,x,y);
	else	
		printmatrix(mat, N-2, M-2, x+1,y+1);
	//cout<<endl<<"Call = "<<N-2<<" "<<M-2<<" "<<x+1<<" "<<y+1<<endl;		
}

int main()
{
	int N,M;
	freopen("input.txt", "r", stdin);
	cin>>N>>M;
	//cout<<N<<M<<endl;
	int mat[100][100];
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin>>mat[i][j];
	//		cout<<mat[i][j]<<" ";
		}
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	printmatrix(mat,N,M,0,0);
	return 0;
}