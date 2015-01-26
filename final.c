#include <stdio.h>
#include <math.h>


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

int edgesaresubset(int v,int graph1[][11], int graph2[][11])
{
	int i,j;
	for (i = 0; i < v; ++i)
	{
		for (j = i+1; j < v; ++j)
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

int main(int argc, char* argv[])
 {
 	int g1[11][11];
 	int g2[11][11];
 	
 	FILE *fp;
    char ch;
    fp = fopen(argv[1],"r");
    if ( fp == NULL )
    {
        puts ( "Cannot open source file");
    }

    /*count the number of vertices*/
    int v=0;
    char c;
    while((c = fgetc(fp)) != EOF)
    {
        if(c == '\n')
            v++;

    }
    /*reopen the file to reset the pointer*/
    fclose(fp);
    
    fp = fopen(argv[1],"r");
    v = v/2;

    /*Load file into array*/
    int i,j;
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            fscanf( fp, "%d", &(g1[i][j]));
        }
        //fscanf(fp, "\n", NULL);
    }

    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            fscanf( fp, "%d", &(g2[i][j]));
        }
        //fscanf(fp, "\n", NULL);
    }

 	
 	int k = checktree(v,g1);
 	int p = edgesaresubset(v,g1,g2);

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

