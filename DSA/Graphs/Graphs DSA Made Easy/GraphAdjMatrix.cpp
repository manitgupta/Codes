#include <stdio.h>
#include <stdlib.h>
struct Graph
{
	int V;
	int E;
	int **Adj; 	//for the 2-D Adj Matrix
};

struct Graph *adjMatrixOfGraph()
{
	int u,v;
	struct Graph *G = (struct Graph*)malloc(sizeof(struct Graph));
	if (!G)
	{
		printf("Memory Error\n");
		return NULL;
	}
	printf("Number of Vertices and Number of Edges \n");
	scanf("%d %d",&G->V,&G->E);
	
	G->Adj = (int**)malloc(G->V * sizeof(int *));	//create a row of pointers to integerss
	for (int i = 0; i < G->V; ++i)
	{
		G->Adj[i] = (int*)malloc(G->V * sizeof(int));	//for each row, allocate G->V * sizeof(int) space for the integers.
	}

	for (int i = 0; i < G->V; ++i)
	{
		for (int j = 0; j < G->V; ++j)
		{
			G->Adj[i][j] = 0;
		}
	}
	printf("Matrix Initialized!\n");
	
	for (int i = 0; i < G->E; ++i)
	{
		// printf("Enter Edge:\n");
		scanf("%d %d",&u,&v);
		G->Adj[u][v] = 1;
		G->Adj[v][u] = 1;
	}
	return G;
}

void printAdjMatrix(struct Graph *G)
{
	for (int i = 0; i < G->V; ++i)
	{
		for (int j = 0; j < G->V; ++j)
		{
			printf("%d ",G->Adj[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	struct Graph *G1 = adjMatrixOfGraph();
	printAdjMatrix(G1);
	return 0;
}
