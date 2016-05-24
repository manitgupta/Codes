#include<iostream>
#include<list>
#include<stack>
#include<vector>

//Use this basic graph struct for solving graph problems with Weighted Graphs

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
	list< pair<int, int> >*adj;	//Pointer to array containing adjacency lists
									//first is for the dest and second is for the weight from src to dest edge.
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
	adj = new list<pair <int, int> >[V];	//Create V number of lists of integers.
}

//Helper Function to insert edge
void Graph::addEdge(int src, int dest, int weight)
{
	adj[src].push_back(make_pair(dest,weight));
	#ifdef UNDIRECTED
	adj[dest].push_back(make_pair(src,weight));
	#endif
}
//Helper Function to print Graph
void Graph::printGraph()
{
	cout<<"Output : (vertex, weight)"<<endl;
	for (int i = 0; i < V; ++i)
	{
		list< pair<int, int> >::iterator iter;
		cout<<"Adj List for Vertex "<<i<<":"<<endl;
		for(iter = adj[i].begin(); iter != adj[i].end(); iter++)
		{
			cout<<"-> ("<<(*iter).first<<","<<(*iter).second<<")";
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
    Graph g(9);
    // Graph on: http://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-using-stl-in-c/
   	g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.printGraph();
    
    #ifdef CONNECTED_GRAPH
    #endif
 	cout<<endl;
    return 0;
}