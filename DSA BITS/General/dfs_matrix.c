 #include<stdio.h>

void DFS(int);
int G[10][10],visited[10],n;    //n is no of vertices and graph is stored in array G[10][10]

void main()
{
    int i,j;
    FILE *fp;
    fp = fopen("input.txt","r+");
    printf("Enter number of vertices:");
    scanf("%d",&n);

    //read the adjecency matrix
    //printf("\nEnter adjecency matrix of the graph:");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            fscanf(fp,"%d",&G[i][j]);
    //visited is initialized to zero
    for(i=0;i<n;i++)
        visited[i]=0;

    DFS(0);
}

void DFS(int i)
{
    int j;
    printf("%d ",i);
    visited[i]=1;
    for(j=0;j<n;j++)
        if(!visited[j]&&G[i][j]==1)
            DFS(j);
}