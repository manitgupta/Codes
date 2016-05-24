#include <stdio.h>
#include <limits.h>

#define V 9

//Function to find minimum distance vertex from the set of vertices
//which are not this shortest path tree set (sptSet)
int minDistance(int dist[], bool sptSet[])
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


void printPath(int parent[], int j)
{
	if (parent[j] == -1)
		return;
	printPath(parent, parent[j]);

	printf("%d ", j);
}

//Helper function to print output
int printSolution(int src, int dist[], int parent[])
{
	printf("Vertex Distance from Source\n");
	for (int i = 0; i < V; ++i)
	{
		printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i], src);
        printPath(parent, i);	
    }
    printf("\n");
}

void dijkstra(int graph[V][V], int src)
{
	int dist[V]; //Ouput array, dist[i] is shortest distance to vertex i from src.
	bool sptSet[V]; //sptSet[i] is true if vertex is included in shortest path tree, that is, its
					//shortest distance from src is finalized.

	int parent[V]; //parent array is used to store the shortest path

	//INITALIZATION
	for (int i = 0; i < V; ++i)
	{
		sptSet[i] = false;		//Initally None is in the sptSet
		dist[i] = INT_MAX;		//Initalize distance of all to INF
	}
	dist[src] = 0;				//Make dist of src as 0 so it selected first.
	parent[src] = -1;

	//run this V-1 times to find shortest path to all V-1 vertices
	//Book says,"After k iterations, we have distances to k vertices closest to the source"
	for (int count = 0; count < V-1; ++count)	
	{
		int u = minDistance(dist, sptSet);	//returns the min. distance vertex, it will be root initally
		sptSet[u] = true;	//include in sptSet

		//Now update distance value of all vertices adjacent to select vertex (u)
		//For every adjacent vertex v, if sum of distance value of u (from source) and weight of 
		//edge u-v, is less than the distance value of v, then update the distance value of v.
		for (int i = 0; i < V; ++i)
		{
			//'i' must not be in sptSet
			// Adj Matrix must have non-zero value to indicate an edge to an adjacent vertex
			// New distance must be less than previous
			if(!sptSet[i] && graph[u][i] != 0 && ((graph[u][i] + dist[u]) < dist[i]))
			{
				parent[i] = u;
				dist[i] = graph[u][i] + dist[u];
			}
		}
	}

	printSolution(src, dist, parent);
	
}

int main()
{
   /* Let us create the example graph discussed above */
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
 
    dijkstra(graph, 3);
 
    return 0;
}