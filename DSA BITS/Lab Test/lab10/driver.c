#include "graph.h"
#include "llist.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
	if(argc < 2)
	{
		printf("USAGE ./%s <FILENAME>\n", argv[0]);
		return -1;
	}
	FILE *fp = fopen(argv[1], "r");
	int size;
	fscanf(fp, "%d", &size);
	int grid[size][size];
	int i,j;
	for (i = 0; i < size; ++i)
		for (j = 0; j < size; ++j)
			fscanf(fp, "%d", &grid[i][j]);
	llist list[size];
	for (i = 0; i < size; ++i)
		list[i] = createLList();
	for (i = 0; i < size; ++i)
	{
		for (j = 0; j < size; ++j)
		{
			if(grid[i][j] != 0)
			{
				vertex temp;
				temp.pos = j;
				temp.cost = grid[i][j];
				push_back(temp, &list[i]);
			}
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
	printVisitable(0, 2, size, list);
	// printMinCost(0, size, grid);
	fclose(fp);
	return 0;
}