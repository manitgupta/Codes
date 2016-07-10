#include <iostream>
#include <vector>
#include <cstdio>
#include <string>

using namespace std;



bool safeRow(int sudoku[9][9], int row, int col, int num)
{
	for (int i = 0; i < 9; ++i)
	{
		if(sudoku[row][i] == num)
			return false;
	}
	return true;
}

bool safeCol(int sudoku[9][9], int row, int col, int num)
{
	for (int i = 0; i < 9; ++i)
	{
		if(sudoku[i][col] == num)
			return false;
	}
	return true;	
}

bool safeBox(int sudoku[9][9], int row, int col, int num, int boxI, int boxJ)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if(sudoku[i+boxI][j+boxJ] == num)
				return false;
		}
	}
	return true;
}

bool isSafe(int sudoku[9][9], int row, int col, int num)
{
	if(safeRow(sudoku,row,col,num) && safeCol(sudoku,row,col,num) && safeBox(sudoku,row,col,num,row - row%3, col - col%3))
		return true;
	return false;
}

bool findloc(int sudoku[9][9], int &row, int &col)
{
	for (row = 0; row < 9; ++row)
	{
		for (col = 0; col < 9; ++col)
		{
			if(sudoku[row][col] == 0)
			{
				// cout<<"Found"<<endl;
				return true;
			}	
		}
	}
	return false;
}


bool fillSudoku(int sudoku[9][9])
{
	int row,col;
	//get loc of empty cell
	if(!findloc(sudoku, row, col))
		return true;
	// cout<<row<<" "<<col<<endl;
	//check for numbers 0 t0 9
	for (int i = 1; i <= 9; ++i)
	{
		if(isSafe(sudoku, row, col, i))	//check for uniqueness in row,column and 3X3 box
		{
			sudoku[row][col] = i;
			if(fillSudoku(sudoku) == true)
				return true;
			sudoku[row][col] = 0;
		}
	}
	return false;
}

void printSudoku(int sudoku[9][9])
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cout<<sudoku[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int sudoku[9][9];
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cin>>sudoku[i][j];
		}
	}
	// printSudoku(sudoku);
	fillSudoku(sudoku);
	printSudoku(sudoku);	
	return 0;
}