#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "MazeOps.h"

int createMaze(Maze pm,char mazefilename[])
{
	FILE *fp;
	fp = fopen("input.txt","r+");
	int n = 0; //To get the size of matrix.
	char c;
	while ((c = fgetc(fp))!= EOF)
	{
		if( c == '\n')
		{
			n++;
		}
	}
	fclose(fp);
	fp = fopen("input.txt","r+");
	int i,j;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			fscanf(fp,"%d",&pm[i][j]);
		}
	}
	// for (i = 0; i < n; ++i)
	// {
	// 	for (j = 0; j < n; ++j)
	// 	{
	// 		printf("%d ",pm[i][j]);
	// 	}
	// 	printf("\n");
	// }
	fclose(fp);
	return n;
}
// int main()
// {
// 	Maze pm;
// 	createMaze(pm,"input.txt");
// 	return 0;
// }	