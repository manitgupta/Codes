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
	void ShortestPath(int s); //Prints shortest path to all vertices from s in unweighted graphs. (application of BFS)

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
void Graph::ShortestPath(int s)
{
	int *distance = new int[V];
	list<int> queue;
	queue.push_back(s);
	for (int i = 0; i < V; ++i)
	{
		distance[i] = -1;
	}
	distance[s] = 0;
	
	list<int>::iterator i;
	while(!queue.empty())
	{
		int v = queue.front();
		queue.pop_front();
		for(i = adj[v].begin(); i != adj[v].end(); i++)
		{
			if(distance[*i] == -1)		//Performs the same functiion as visited array. 
			{
				distance[*i] = distance[v] + 1;//distance upto that vertex plus 1 since it is adjacent.
				//It is the property of BF Traversal to reach target vertex from source with min. number of edges
				//since we span "level-wise", and hence reach as quickly as we can.
				queue.push_back(*i);
			}
		}
	}
	cout<<"Distances from "<<s<<" are:"<<endl;
	for (int i = 0; i < V; ++i)
	{
		cout<<i<<" is "<<distance[i]<<" unit away"<<endl;
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
    g.ShortestPath(0);
    #endif	
 	cout<<endl;
    return 0;
}