#include <stdio.h>
#include <math.h>

int main()
{
    FILE *fp;
    char ch;
    fp = fopen("matrix.txt","r");
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
    printf("v= %i\n",v);

    /*reopen the file to reset the pointer*/
    fclose(fp);
    
    fp = fopen("matrix.txt","r");
    v = v/2;
    printf("v= %i\n",v);
    int m[v][v];
    int n[v][v];

    /*Load file into array*/
    int i,j;
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            fscanf( fp, "%d", &(m[i][j]));
        }
        //fscanf(fp, "\n", NULL);
    }

    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            fscanf( fp, "%d", &(n[i][j]));
        }
        //fscanf(fp, "\n", NULL);
    }

    /*print out stored matrix*/
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n\n");

    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            printf("%d ",n[i][j]);
        }
        printf("\n");
    }
    printf("%d\n",n[0][0]);
    printf("%d\n",m[1][1]);
    return 0;
}