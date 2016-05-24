#include<iostream>
#include<list>
#include<stack>
#include<vector>

//Use this basic graph struct for solving graph problems

using namespace std;

//for an undirected graph, (adj list with both edges is created)
// #define UNDIRECTED


// CONNECTED_GRAPH if graph is connected
// DISCONNECTED_GRAPH if graph as disjoint component
//Don't enable both at once!!

#define CONNECTED_GRAPH		
//#define DISCONNECTED_GRAPH

class Graph
{
	int V;
	list<int> *adj;	//Pointer to array containing adjacency lists
public:
	Graph(int V);	//Constructor which sets the number of vertices in the Graph.
	void addEdge(int src, int dest);
	void printGraph();
	#ifdef CONNECTED_GRAPH
	void SimplePath(int src, int dest);
	int SimplePathUtil(int src, int dest, bool visited[]);
	//define function prototypes here.
	#endif
};

//Constructor 
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int> [V];	//Create V number of lists of integers.
}

//Helper Function to insert edge
void Graph::addEdge(int src, int dest)
{
	adj[src].push_back(dest);
	
	#ifdef UNDIRECTED
	adj[dest].push_back(src);
	#endif
}
//Helper Function to print Graph
void Graph::printGraph()
{
	for (int i = 0; i < V; ++i)
	{
		list<int>::iterator iter;
		cout<<"Adj List for Vertex "<<i<<":"<<endl;
		for(iter = adj[i].begin(); iter != adj[i].end(); iter++)
		{
			cout<<"-> "<<*iter;
		}
		cout<<endl;
	}
}


#ifdef CONNECTED_GRAPH
//define function definitions here.

int Graph::SimplePathUtil(int src, int dest, bool visited[])
{
	visited[src] = true;
	if (src == dest)
	{
		cout<<"Success"<<endl;
		return 1;
	}
	list<int>::iterator iter;
	for(iter = adj[src].begin(); iter != adj[src].end(); iter++)
	{
		if(!visited[*iter])
			{
				cout<<"iter = "<<*iter<<endl;
				if(SimplePathUtil(*iter,dest,visited))	//if-else is essential to make '1' travel
					return 1;							//up the levels of recursion.
			}
	}
	return 0;
}

void Graph::SimplePath(int src, int dest)
{
	bool *visited = new bool[V];
	for (int i = 0; i < V; ++i)
	{
		visited[i] = false;
	}
	if (SimplePathUtil(src, dest, visited))
		cout<<"Simple Path Exists"<<endl;
	else
		cout<<"No Simple Path!"<<endl;
}
#endif
int main()
{
    // Create a graph given in the above diagram
   	Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);

    g.printGraph();
    
    #ifdef CONNECTED_GRAPH
    g.SimplePath(0,2);
    #endif
 	cout<<endl;
    return 0;
}