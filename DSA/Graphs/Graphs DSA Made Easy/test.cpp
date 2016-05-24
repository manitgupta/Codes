#include<iostream>
#include<list>
#include<stack>
#include<vector>
#include<utility>

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
	list< pair<int, int> > *adj;	//Pointer to array containing adjacency lists
public:
	Graph(int V);	//Constructor which sets the number of vertices in the Graph.
	void addEdge(int src, int dest, int weight);
	void printGraph();
	#ifdef CONNECTED_GRAPH
	//define function prototypes here.
	#endif
};

//Constructor 
Graph::Graph(int V)
{
	this->V = V;
	adj = new list< pair<int, int> >[V];	//Create V number of lists of integers.
}

//Helper Function to insert edge
void Graph::addEdge(int src, int dest, int weight)
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

#endif
int main()
{
    // Create a graph given in the above diagram
    Graph g(8);
    g.addEdge(7, 0);
    g.addEdge(7, 5);
    g.addEdge(7, 6);
    g.addEdge(3, 7);
    g.addEdge(3, 4);
    g.addEdge(2, 7);
    g.addEdge(1, 4);
    g.addEdge(1, 6);
    g.addEdge(4, 5);

    g.printGraph();
    
    #ifdef CONNECTED_GRAPH
    #endif
 	cout<<endl;
    return 0;
}