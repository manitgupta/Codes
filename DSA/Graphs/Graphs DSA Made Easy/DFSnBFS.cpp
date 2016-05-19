#include<iostream>
#include<list>

using namespace std;

// #define UNDIRECTED


// CONNECTED_GRAPH if graph is connected
// DISCONNECTED_GRAPH if graph as disjoint component
//Don't enable both at once.

#define CONNECTED_GRAPH		
//#define DISCONNECTED_GRAPH

class Graph
{
	int V;
	list<int> *adj;	//Pointer to array containing adjacency lists
	void DFSUtil(int v, bool visited[]);	//private since this will never be directly called.
public:
	Graph(int V);	//Constructor which sets the number of vertices in the Graph.
	void addEdge(int src, int dest);

	#ifdef CONNECTED_GRAPH
	void DFS(int v); //DFS traversal of the vertices reachable from v.	//def in connected graph case
	void BFS(int s); //BFS traversal of the vertices reachable from s.
	#endif
	#ifdef DISCONNECTED_GRAPH
	void DFS();
	#endif
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int> [V];
}

void Graph::addEdge(int src, int dest)
{
	adj[src].push_back(dest);
	
	#ifdef UNDIRECTED
	adj[dest].push_back(src);
	#endif
}

void Graph::DFSUtil(int v, bool visited[])
{
	visited[v] = true; //Mark the current vertex as visited.
	cout<<v<<" ";
	//all the vertex adjacent to this vertex are already in its adjacency list!
	list<int>::iterator i;
	for(i = adj[v].begin(); i != adj[v].end(); i++)
	{
		if(!visited[*i])
		{
			DFSUtil(*i, visited);
		}
	}
}

#ifdef CONNECTED_GRAPH
void Graph::DFS(int v)
{
	//Mark all the vertices as not visited.
	bool *visited = new bool[V];
	for (int i = 0; i < V; ++i)
	{
		visited[i] = false;
	}
	//Assumes connected Graph
	DFSUtil(v, visited);	//recursive function to print DFS traversal.
	//This functions performs Depth First Searching and backtrack when a "dead end" is reached.
}

void Graph::BFS(int s)
{
	bool *visited = new bool[V];
	for (int i = 0; i < V; ++i)
	{
		visited[i] = false;
	}
	list<int> queue;
	//Mark current node as visited and enqueue it.
	visited[s] = true;
	queue.push_back(s);
	list<int>::iterator i;

	//iterator i is used to get adjacent vertices of a vertex.
	while (!queue.empty())
	{
		s = queue.front();
		cout<<s<<" ";
		queue.pop_front();
		for(i = adj[s].begin(); i != adj[s].end(); i++)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);		//if the vertex is not visited, then enqueue it and mark it visited.
			}
		}
	}
}

#endif

#ifdef DISCONNECTED_GRAPH
void Graph::DFS()
{
	//Mark all the vertices as not visited.
	bool *visited = new bool[V];
	for (int i = 0; i < V; ++i)
	{
		visited[i] = false;
	}
	
	//Assumes connected Graph

	//DFSUtil(v, visited);	//recursive function to print DFS traversal.
	//This functions performs Depth First Searching and backtrack when a "dead end" is reached.

	//Works on Disconnected Graph as well, since if a vertex is disconnected (another connected component) its visited value 
	// will remain false after DFS of one connected component 
	for (int i = 0; i < V; ++i)
	{
		if(visited[i] == false)
			DFSUtil(i, visited);
	}
}
#endif

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    
    #ifdef CONNECTED_GRAPH
    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.DFS(2);
    cout<<endl;
    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.BFS(2);
    #endif

    #ifdef DISCONNECTED_GRAPH
    g.DFS();
    #endif
 	cout<<endl;
    return 0;
}