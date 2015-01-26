#include<iostream>
#include<cstdlib>
using namespace std;

struct Graph
{
int V;
int E;
int **Matrix;
};

Graph *Create(Graph *G)     //Graph G creates the adjacency matrix.
{
int u,v;
G->Matrix=new int*[G->V];
for(int i=0;i<G->V;i++)
G->Matrix[i]=new int[G->V];
for(int i=0;i<G->E;i++)
{
    cin>>u>>v;
    G->Matrix[u-1][v-1]=1;
    G->Matrix[v-1][u-1]=1;
}
return G;
}

int DFS(Graph *G,int u,int *Visited)
{
    if(Visited[u]!=-1)
    return 0;
    Visited[u]=1;
for(int v=0;v<G->V;v++)
{
    if(G->Matrix[u][v])
       DFS(G,v,Visited);
}
return 1;  
}

int main(void)
{   int *Visited=NULL;
    Graph *G=new Graph;
    cin>>G->V>>G->E;
    G->Matrix=NULL;
    G=Create(G);
    Visited=new int[G->V]; //Array Declaration
    cout<<*Visited<<G->V;
    for(int i=0;i<G->V;i++)
    Visited[i]=-1; //Initializing all element of visited to -1.
  int k=DFS(G,0,Visited); // calling the DFS function, starting with the first vertex (u=0)
  if(k==0)
  cout<<"NO";
  else
  {
      for(int v=0;v<G->V;v++)
      {
          if(Visited[v]==-1)
          {cout<<"NO"; return 0;}
      }
  cout<<"YES";
  }
}