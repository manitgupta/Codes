#include <iostream>

using namespace std;


void solveMaze(int maze[][N],int x, int y, int sol[][N])
{
	if (x == N-1 && y == N-1)
	{
		sol[x][y] = 1;
		return;
	}
}


int main()
{
	int maze[N][N]  =  { {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    int sol[N][N] = { {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    solveMaze(maze,0,0, sol);
 	



	return 0;

}