#include <stdio.h>
#include <stdlib.h>

// #define DIRECTED

//Uncomment line 4 for directed Graph.

//Procedural Design for creating Structs:

// 1)Make structs for whatever you need.
// 2) Encapsulate into different units.

struct AdjListNode	//struct for a node of an Adjacency List
{
	int dest;
	struct AdjListNode *next;
};

struct AdjList 		//struct for Adjacency List for one vertex
{
	struct AdjListNode *head;
};

struct Graph
{
	int V;
	struct AdjList *array;	//This will form the multiple row adjacency List that is actually needed.
};

struct AdjListNode* newAdjListNode(int dest)
{
	struct AdjListNode *newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
	newNode->dest = dest;
	newNode->next = NULL;
	return newNode;
}

struct Graph* createGraph(int V)
{
	struct Graph *G = (struct Graph*)malloc(sizeof(struct Graph));
	G->V = V;
	G->array = (struct AdjList*)malloc(sizeof(struct AdjList)*V);	//since we need 'V' adjacency list
	for (int i = 0; i < V; ++i)
	{
		G->array[i].head = NULL;
	}
	return G;
}

void addEdge(struct Graph* G, int src, int dest)
{
	struct AdjListNode *newNode = newAdjListNode(dest);

	//insert at head of Adj List of src
	newNode->next = G->array[src].head;
	G->array[src].head = newNode;

	//If undirected, then add reverse edge as well

	#ifndef DIRECTED
	newNode = newAdjListNode(src);
	newNode->next = G->array[dest].head;
	G->array[dest].head = newNode;
	#endif
}

void printGraph(struct Graph *G)
{
	for (int i = 0; i < G->V; ++i)
	{
		struct AdjListNode *temp = G->array[i].head;
		printf("Adjacency List of %d vertex\n", i);
		while(temp)
		{
			printf(" -> %d", temp->dest);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main()
{
    // create the graph given in above fugure
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
 
    // print the adjacency list representation of the above graph
    printGraph(graph);
 
    return 0;
}