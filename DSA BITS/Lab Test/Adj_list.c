//**************Adj List Representation****************
#include<stdio.h>
#include<stdlib.h>
 
#define NUM_NODE 6
#define true 1
typedef struct node{
        int value;
        struct node *next;
}Node;
 
Node *graph[NUM_NODE];
 
Node * create_node(int j){
 
        Node * new_node = (Node *)malloc(sizeof(Node));
        if(new_node){
                new_node->value = j;
                new_node->next = NULL;
        }
        else{
                printf("\n Node cannot be allocated");
        }
        return new_node;
}
void add_edge_1(int i, int j){
 
        Node * temp = graph[i];
        if(temp == NULL){
                graph[i] = create_node(j);
        }
        else{
                while(temp->next){
                        temp = temp->next;
                }
                temp->next = create_node(j);
        }
}
// int main(){
 
//         int i;
//         add_edge_1(1,4);
//         add_edge_1(2,1);
//         add_edge_1(2,6);
//         add_edge_1(4,3);
//         add_edge_1(3,6);
//         add_edge_1(3,5);
//         add_edge_1(5,6);
 
//         // Adjancancy list based representation       
//         for(i=1; i<=NUM_NODE; i++){
//                 printf("Nodes adjacent to %d : ", i);
 
//                 Node * current  = graph[i];
//                 while(current){
//                         printf("%d ", current->value);
//                         current = current->next;
//                 }
//                 printf("\n");
//         }
 
//         return 0;
// }