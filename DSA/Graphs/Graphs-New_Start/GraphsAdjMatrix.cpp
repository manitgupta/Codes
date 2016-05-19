#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define _DEBUG

#define Inf 2147483647
#define Max(a, b)  (a < b ? b : a)
#define Min(a, b)  (a > b ? b : a)
#define INT_MIN -99999999


struct Graph
{
	int V;
	int E;
	int **Adj;		//Since we need a two dimensional matrix.
};

struct Graph* adjMatrix()
{
	int i,u,v;
	struct Graph *G = (struct Graph*)malloc(sizeof(struct Graph));
	if(!G)
	{
		printf("Memory Error\n");
		exit(0);
	}
	scanf("Number of Vertices:%d  Number of Edges:%d",&G->V,&G->E);
	//Allocate Memory
	G->Adj = (int*)malloc(sizeof(G->E*G->V));
	//Initialize Matrix
	for (u = 0; u < G->V; ++u)
		for (v = 0; v < G->V; ++v)
			Adj[u][v] = 0;
	for (i = 0; i < G->E; ++i)
	{
		scanf("Reading Edge: %d %d",&u,&v);
		//For Undirected Graphs
		G->Adj[u][v] = 1;
		G->Adj[v][u] = 1;
	}
	return G;
}

int main()
{
	return 0;
}