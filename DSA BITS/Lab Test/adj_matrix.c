//**************Adj matrix****************
#include<stdio.h>
#include<stdlib.h>
 
#define NUM_NODE 6
#define true 1
 
void add_edge(int i, int j, int adj_mat[NUM_NODE][NUM_NODE]){
        adj_mat[i][j] = true;
}
// int main(){
 
//         int adj_mat[NUM_NODE][NUM_NODE];
 
//         int i,j;
//         add_edge(1,4, adj_mat);
//         add_edge(2,1,adj_mat);
//         add_edge(2,6,adj_mat);
//         add_edge(4,3, adj_mat);
//         add_edge(3,6, adj_mat);
//         add_edge(3,5, adj_mat);
//         add_edge(5,6, adj_mat);
 
//         // Adjancancy matrix based representation       
//         for(i=1; i<=NUM_NODE; i++){
//                 printf("Nodes adjacent to %d : ", i);
//                 for(j=1; j<=NUM_NODE; j++){
//                         if(adj_mat[i][j] == true){
//                                 printf("%d ", j);
//                         }
//                 }
//                 printf("\n");
//         }
 
//         return 0;
// }