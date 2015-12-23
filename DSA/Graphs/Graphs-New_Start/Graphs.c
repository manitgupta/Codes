#define MAXV 1000	//Max number of vertices

typedef struct {
	int y;			
	int weight;		//edge weight
	struct edgenode *next;	//Next node in adjacency list.
}edgenode;

typedef struct {
	edgenode *edges[MAXV+1];	//An adjacency list for each of the vertices,basically the head pointer.
	int degree[MAXV+1];	//outdegree of each vertex
	int nvertices;	//no. of vertices
	int nedges;		//no. of edges
	bool directed;	//is graph directed?
} graph;

initialize_graph(graph *g,bool directed)
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

read_graph(graph *g, bool directed)
{
	int i,m; //counter,no. of edges
	int x,y //vertices in edge(x,y); means y is in x's adjacency list

	initialize_graph(g,directed);
	
	scanf("%d %d",&(g->nvertices),&m);	//Input no. of vertices and edges.
	
	for(i=1; i<=m; i++)
	{
		scanf("%d %d",&x,&y);
		insert_edge(g,x,y,directed);
	}
}

insert_edge(graph *g,int x, int y, bool directed)
{
	//Insert y at the head of x's adjacency list!
	edgenode *p;
	p = (edgenode*)malloc(sizeof(edgenode));
	p->weight = NULL;
	p->y = y;
	p->next = g->edges[x]; //since y is to be inserted at the head;
	g->edges[x] = p; //change the position of the head to start again.
	g->degree[x]++;
	if(directed == FALSE)	//if the graph is undirected then recursively insert the reverse edge as well
		insert_edge(g,y,x,TRUE);	//the directed flag must now be TRUE, it is the exit condition for recursion.
	else
		g->nedges++;		//This is why we did not set this in read_graph, since the graph can be directed or undirected.
}