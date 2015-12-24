#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//-----------------HEADER FILE ONLY INITIALIZES THE GRAPH, IT DOES-----------
//-----------------ALLOCATE ANY MEMORY FOR IT, DO THAT IN MAIN-------------

#define MAXV 1000	//Max number of vertices

typedef struct edgenode{
	int y;			
	int weight;		//edge weight
	struct edgenode *next;	//Next node in adjacency list.
}edgenode;

typedef struct graph{
	edgenode *edges[MAXV+1];	//An adjacency list for each of the vertices,basically the head pointer.
	int degree[MAXV+1];	//outdegree of each vertex
	int nvertices;	//no. of vertices
	int nedges;		//no. of edges
	bool directed;	//is graph directed?
}graph;

void initialize_graph(graph *g,bool directed)
{
	int i;
	g->nvertices=0;
	g->nedges=0;
	g->directed=directed;
	for (i = 1; i <= MAXV; i++)
	{
		g->degree[i] = 0;
		g->edges[i] = NULL;
	}
}

void insert_edge(graph *g,int x, int y, bool directed)
{
	//Insert y at the head of x's adjacency list!
	edgenode *p;
	p = (edgenode*)malloc(sizeof(edgenode));
	p->weight = 0;
	p->y = y;
	p->next = g->edges[x]; //since y is to be inserted at the head;
	g->edges[x] = p; //change the position of the head to start again.
	g->degree[x]++;
	if(directed == false)	//if the graph is undirected then recursively insert the reverse edge as well
		insert_edge(g,y,x,true);	//the directed flag must now be TRUE, it is the exit condition for recursion.
	else
		g->nedges++;		//This is why we did not set this in read_graph, since the graph can be directed or undirected.
}

void read_graph(graph *g, bool directed)
{
	int i,m; //counter,no. of edges
	int x,y; //vertices in edge(x,y); means y is in x's adjacency list

	initialize_graph(g,directed);
	
	scanf("%d %d",&(g->nvertices),&m);	//Input no. of vertices and edges.
	
	for(i=1; i<=m; i++)
	{
		scanf("%d %d",&x,&y);
		insert_edge(g,x,y,directed);
	}
}

void print_graph(graph *g)
{
	int i; //counter
	edgenode *p;	//temp pointer to run through graph

	for(i=1; i<=g->nvertices;i++)
	{
		printf("%d: ",i);
		p = g->edges[i]; //Points to head of the ith adjacency list
		while (p!= NULL) //standard traversal through LL
		{
			printf(" %d",p->y);
			p = p->next;
		}
		printf("\n");
	}
}
