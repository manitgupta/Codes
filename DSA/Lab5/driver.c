#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "MazeOps.h"
#include "Maze.h"
int main()
{
	Maze pm;
	int matrixSize = createMaze(pm,"input.txt");
	return 0;
}