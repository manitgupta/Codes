#include <stdio.h>
#include <math.h>

void entermatrix(int v,int graph[][11])
{
	int i,j;
	for (i = 0; i < v; ++i)
	{
 		for (j = 0; j < v; ++j)
 		{
 			scanf("%d",&graph[i][j]);
 		}
 	}
}

void printmatrix(int v, int graph[][11])
{	
	int i,j;
	printf("The matrix is: \n");
	for (i = 0; i < v; ++i)
	{
 		for (j = 0; j < v; ++j)
 		{
 			printf("%d ",graph[i][j]);
 		}
 		printf("\n");
 	}

}

int checktree(int v,int graph[][11])
{	
	int edges =0;
	int checkednode[v];
	int i,j;
	for (i = 0; i < v; ++i)
	{
		checkednode[i] = -1;
	}
	for (i = 0; i < v; ++i)
	{
		for (j = i+1; j < v; ++j)
		{
			if(graph[i][j] == 1)
			{
				edges++;
				if(checkednode[i] == 1 && checkednode[j] == 1)
				{
					return 0;

				}
				checkednode[i] = 1;
				checkednode[j] = 1;
			}	
		}
	}
	if(v== edges+1)
	{
		return 1;
	}
	else
		return 0;
}

int edgesaresubset(int v1,int v2, int graph1[][11], int graph2[][11])
{
	int i,j;
	if(v1!=v2)
	{
		//printf("Not a spanning tree\n");
		return 0;
	}
	else
	{
		for (i = 0; i < v1; ++i)
		{
			for (j = i+1; j < v1; ++j)
			{
				if(graph1[i][j] == 1)
				{
					if(graph2[i][j] != 1)
					{
						return 0;
					}
				}
			}
		}
		return 1;
	}
}

int main()
 {
 	int v1,v2;
 	int g1[11][11];
 	int g2[11][11];
 	printf("Enter the no. of vertices of Graph G1:");
 	scanf("%d",&v1);
 	entermatrix(v1,g1);1
 	//printmatrix(v1,g1);
 	printf("Enter the no. of vertices of Graph G2:");
 	scanf("%d",&v2);
 	entermatrix(v2,g2);
 	//printmatrix(v2,g2);
 	int k = checktree(v1,g1);
 	int p = edgesaresubset(v1,v2,g1,g2);

 	if ( k ==1 && p ==1)
 	{
 		printf("G1 is a spanning tree of G2\n");
 	}
 	else
 	{
 		printf("G1 is a not spanning tree of G2\n");

 	}
 	return 0;
 }

