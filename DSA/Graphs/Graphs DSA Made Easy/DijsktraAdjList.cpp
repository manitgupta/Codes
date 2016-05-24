#include<iostream>
#include<list>
#include<stack>
#include<vector>
#define INT_MAX 9999999

//Use this basic graph struct for solving graph problems with Weighted Graphs

using namespace std;

//for an undirected graph, (adj list with both edges is created)
// #define UNDIRECTED


// CONNECTED_GRAPH if graph is connected
// DISCONNECTED_GRAPH if graph as disjoint component
//Don't enable both at once!!

#define CONNECTED_GRAPH		
//#define DISCONNECTED_GRAPH

//the algorithm also works for Directed Graphs, only negative weights are not allowed.
#define UNDIRECTED 	


class Graph
{
	int V;
	list< pair<int, int> >*adj;	//Pointer to array containing adjacency lists
									//first is for the dest and second is for the weight from src to dest edge.
public:
	Graph(int V);	//Constructor which sets the number of vertices in the Graph.
	void addEdge(int src, int dest, int weight);
	void printGraph();
	void dijkstra(int src);
	int printSolution(int dist[]);
	int minDistance(int dist[], bool sptSet[]);
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
//Function to find minimum distance vertex from the set of vertices
//which are not this shortest path tree set (sptSet)
int Graph::minDistance(int dist[], bool sptSet[])
{
	int min = INT_MAX, min_index;
	for (int i = 0; i < V; ++i)
	{
		if(sptSet[i] == false && dist[i] <= min)
		{
			min = dist[i];
			min_index = i;
		}
	}
	//Return the index of the min. distance vertex.
	return min_index;
}

//Helper function to print output
int Graph::printSolution(int dist[])
{
	cout<<"Vertex Distance from Source\n";
	for (int i = 0; i < V; ++i)
	{
		cout<<i<<" is "<<dist[i]<<" units away\n";
	}
}

void Graph::dijkstra(int src)
{
	int dist[V]; //Ouput array, dist[i] is shortest distance to vertex i from src.
	bool sptSet[V]; //sptSet[i] is true if vertex is included in shortest path tree, that is, its
					//shortest distance from src is finalized.

	//INITALIZATION
	for (int i = 0; i < V; ++i)
	{
		sptSet[i] = false;		//Initally None is in the sptSet
		dist[i] = INT_MAX;		//Initalize distance of all to INF
	}
	dist[src] = 0;				//Make dist of src as 0 so it selected first.


	//run this V-1 times to find shortest path to all V-1 vertices
	//Book says,"After k iterations, we have distances to k vertices closest to the source"
	for (int count = 0; count < V-1; ++count)	
	{
		int u = minDistance(dist, sptSet);	//returns the min. distance vertex, it will be root initally
		sptSet[u] = true;	//include in sptSet

		//Now update distance value of all vertices adjacent to selected vertex (u)
		//For every adjacent vertex v, if sum of distance value of u (from source) and weight of 
		//edge u-v, is less than the distance value of v, then update the distance value of v.
		list< pair<int, int> > ::iterator iter;
		for( iter = adj[u].begin(); iter != adj[u].end(); iter++)
		{
			if(!sptSet[(*iter).first] && (( (*iter).second + dist[u]) < dist[(*iter).first]))
			{
				dist[(*iter).first] = (*iter).second + dist[u];
			}
		}
	}

	printSolution(dist);
	
}
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
    g.dijkstra(0);	
    #endif
 	cout<<endl;
    return 0;
}