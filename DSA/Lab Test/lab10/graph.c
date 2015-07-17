#include "graph.h"
#include "stack.h"
#include "queue.h"
#include <stdio.h>

#define INF 100007

void printVisitable(int source, int amount, int size, llist list[5])
{
	int visited[size];
	int i;
	for (i = 0; i < size; ++i)
		visited[i] = INF;
	vertex src;
	src.pos = source;
	src.cost = 0;
	queue q;
	q = createQueue();
	pushQueue(src, &q);
	visited[source] = 0;
	while(isEmptyQueue(&q) == false)
	{
		vertex top = popQueue(&q);
		int j;
		for (j = 0; j < list[top.pos].size; ++j)
		{
			vertex l = pop_front(&list[top.pos]);
			// if(l == NULL)
				// continue;
			// push_front(l, &list[top.pos]);
			vertex temp;
			temp.pos = l.pos;
			temp.cost = top.cost + l.cost;
			// printf("%d\n", l.cost);
			if(l.cost == 0)
				continue;
			if(temp.cost > amount)
				continue;
			if(visited[temp.pos] <= temp.cost)
				continue;
			visited[temp.pos] = temp.cost;
			pushQueue(temp, &q);
		}
	}
	printf("Jetties that can be reached are ");
	for (i = 0; i < size; ++i)
	{
		if(visited[i] != INF)
			printf("%d ", i);
	}
	printf(".\n");
}

void printMinCost(int source, int size, int grid[][5])
{
	// int ii,jj;
	// for (ii = 0; ii < size; ++ii)
	// {
	// 	for (jj = 0; jj < size; ++jj)
	// 		printf("%d ", grid[ii][jj]);
	// 	printf("\n");
	// }
	int visited[size];
	int i;
	for (i = 0; i < size; ++i)
		visited[i] = INF;
	vertex src;
	src.pos = source;
	src.cost = 0;
	stack s;
	s = createStack();
	pushStack(src, &s);
	visited[source] = 0;
	int minCost = INF;
	while(isEmptyStack(&s) == false)
	{
		vertex top = popStack(&s);
		// printf("%d %d\n", top.pos, top.cost);
		int j;
		for (j = 0; j < size; ++j)
		{
			if(grid[top.pos][j] == 0)
				continue;
			vertex temp;
			temp.pos = j;
			temp.cost = top.cost + grid[top.pos][j];
			if(visited[temp.pos] <= temp.cost)
				continue;
			visited[temp.pos] = temp.cost;
			// printf("top: %d pos: %d cost: %d tot_cost: %d\n", top.pos, temp.pos, grid[top.pos][j], temp.cost);
			pushStack(temp, &s);
		}
	}
	for (i = 0; i < size; ++i)
		printf("The minimum cost to reach point %d from %d is %d.\n", i, source, visited[i]);
	// printf("The minimum cost to reach point %d from %d is %d.\n", dest, source, minCost);
}

