#define MAXV 1000	//Max number of vertices

typedef struct {
	int y;
	int weight;		//edge weight
	struct edgenode *next;	//Next node in adjacency list.
}edgenode;

typedef struct {
	edgenode *edges[MAXV+1];	//An adjacency list for each of the vertices
	int degree[MAXV+1];	//outdegree of each vertex
	int nvertices;
	int nedges;
	bool directed;
} graph;

