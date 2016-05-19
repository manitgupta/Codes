#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define _DEBUG

#define Inf 2147483647
#define Max(a, b)  (a < b ? b : a)
#define Min(a, b)  (a > b ? b : a)
#define INT_MIN -99999999

//A struct for Node of an Adjacency List
struct AdjListNode
{
	int dest;	//
	struct AdjListNode *next;
};

//A struct for the adjacency list of nodes.
struct AdjList
{
	struct AdjListNode *head;	//pointer to head of a linked list.
};

//A struct to represent a Graph. A Graph is an array of linked lists.
//Size of array is V = No. of Vertices in the graph.
struct Graph
{
	int V;
	struct AdjList *array;
};	

struct AdjListNode* newAdjListNode(int dest)
{
	struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
	newNode->dest = dest;
	newNode->next = NULL;
	return newNode;
}

//Function to create a Graph.
struct Graph* createGraph(int V)
{
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->V = V;
	//Allocate Memory to array of Linked Lists, remember memory only
	//for the head pointers of each List is allocated right now.
	graph->array = (struct AdjList*)malloc(V*sizeof(struct AdjList));
	int i;
	//Intialize the Graph with all heads being NULL.
	for (int i = 0; i < V; ++i)
		graph->array[i].head = NULL;
	return graph;
}

void addEdge(struct Graph *graph,int src,int dest)
{
	//Add an Edge from src to dest. A new node is
	//added to the adjacency list of src. The node is added
	//at the beginning.
	struct AdjListNode *newNode = newAdjListNode(dest);
	//Add the Node at the beginning.
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;

	//Since graph is undirected, add an edge from dest to src as well.
	newNode = newAdjListNode(src);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;
}

// A utility function to print the adjacenncy list representation of graph
void printGraph(struct Graph* graph)
{
	int v;
	for (v = 0; v < graph->V; ++v)
	{
	    struct AdjListNode* pCrawl = graph->array[v].head;
	    printf("\n Adjacency list of vertex %d\n head ", v);
	    while (pCrawl)
	    {
	        printf("-> %d", pCrawl->dest);
	        pCrawl = pCrawl->next;
	    }
	    printf("\n");
	}
}

int main()
{
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