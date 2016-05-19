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
	void TopologicalSortUtil(int v, bool visited[], stack<int> &Stack);	
	//pass by reference is since we don't want the stack to get copied.
	//infact, we will be modifying (or creating) the stack contents in this function, hence pass by reference.
public:
	Graph(int V);	//Constructor which sets the number of vertices in the Graph.
	void addEdge(int src, int dest);
	void printGraph();
	#ifdef CONNECTED_GRAPH
	void TopologicalSort();
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

void Graph::TopologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
	//Mark current vertex as visited
	visited[v] = true;
	//For all its adjacent vertices, visit them in DFS fashion, but store the result in a stack
	//Topological sort is almost same as DFS, we are only delaying the printing time of a vertex
	//to a time after the vertex with a directed edge to it is printed. (thats why we use stack)
	list<int>::iterator i;
	for(i = adj[v].begin(); i != adj[v].end(); i++)
	{
			if(!visited[*i]) //has not been visited before
				TopologicalSortUtil(*i, visited, Stack);
	}
	Stack.push(v);
}

void Graph::TopologicalSort()
{
	stack<int> Stack;
	bool *visited = new bool[V];
	for (int i = 0; i < V; ++i)
	{
		visited[i] = false;
	}
	for (int i = 0; i < V; ++i)
	{
		if(visited[i] == false)
			TopologicalSortUtil(i, visited, Stack);
	}
	//The Topological Sorted Order is in Stack by now.
	while(!Stack.empty())
	{
		cout<<Stack.top()<<" ";
		Stack.pop();
	}
}

#endif
int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    // g.printGraph();
    
    #ifdef CONNECTED_GRAPH
    cout<<"Topological Sort Order is:"<<endl;
    g.TopologicalSort();
    #endif
 	cout<<endl;
    return 0;
}