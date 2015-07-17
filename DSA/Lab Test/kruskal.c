#include<stdio.h>
#include<stdlib.h>
 
#define NUM_NODE 5
#define true 1
#define false 0
 
//Definition of node in adjacency list formation
typedef struct node{
    int value;
    int wt;
    struct node *next;
}Node;
 
//Edge definition for sorting and storing minimum spanning tree
typedef struct edge{
    int start;
    int end;
    int wt;
}Edge;
 
Node *graph[NUM_NODE + 1];
 
//This function creates a node in adjancency list representation with weight 
Node * create_node_1(int j, int wt){
 
    Node * new_node = (Node *)malloc(sizeof(Node));
    if(new_node){
        new_node->value = j;
        new_node->next = NULL;
        new_node->wt = wt;
    }
    else{
        printf("\n Node cannot be allocated");
    }
    return new_node;
}
//Adds edge in graph
void add_edge_2(int i, int j, int wt){
 
    Node * temp = graph[i];
    if(temp == NULL){
        graph[i] = create_node_1(j, wt);
    }
    else{
        while(temp->next){
            temp = temp->next;
        }
        temp->next = create_node_1(j, wt);
    }
}
 
//Below functions are used for Union and Find method on disjoint set
int find(int rep[], int value){
    if(rep[value] == -1)
        return value;
    else find(rep, rep[value]);
}
 
void union_1(int rep[], int x, int y){
 
    int xroot = find(rep, x);
    int yroot = find(rep, y);
 
    rep[xroot] = yroot;
}
 
void make_set(int rep[]){
    int i;
    for(i=0; i<= NUM_NODE; i++){
        rep[i] = -1;
    }
}
//This copies all edges to array so as to sort them on weight
void copy_edges(Edge edges[], Node *graph[]){
    int i, count =0;
 
    for(i=1; i<= NUM_NODE; i++){
        Node * u = graph[i];
        if(u){
            Node * v = u->next;
            while(v){
                edges[count].start =  u->value;
                edges[count].end =v->value;
                edges[count].wt = v->wt;
                count++;
                v = v->next;
            }
        }
    }
}
 
//Implementation of quick sort
void swap(Edge edges[], int i, int j){
    int temp_start = edges[i].start;
    int temp_end = edges[i].end;
    int wt = edges[i].wt;
 
    edges[i].start  = edges[j].start ;
    edges[i].end  = edges[j].end ;
    edges[i].wt  = edges[j].wt;
 
    edges[j].start  = temp_start;
    edges[j].end  = temp_end ;
    edges[j].wt  = wt;
}
void quicksort(Edge edges[], int start, int nEdges){
 
        if(start >=nEdges) return;
        int pivot = partition(edges, start, nEdges);
 
        quicksort(edges, start, pivot);
        quicksort(edges, pivot+1, nEdges);
 
}
int partition(Edge edges[], int start, int nEdges){
    int i,j;
 
    int pivot =  edges[start].wt;
    i = start+1;
    j = nEdges;
    while(i<=j){
        while(i<=nEdges && edges[i].wt < pivot)
            i++;
        while(j>start && edges[j].wt >= pivot)
            j--;
 
        if(i<j){
            swap(edges, i, j);
        }
    }
    if(j>start)
        swap(edges,start, j);
    
    return j;
}
 
//Real implementation of krutskal algorithm
void krutskal(Node * graph[], int num_edges){
 
    int i, count =0, wt=0;
 
    Edge edges[num_edges];
 
    Edge mst[num_edges];
 
    copy_edges(edges, graph);
 
    quicksort(edges, 0, num_edges-1);
 
    int rep[NUM_NODE + 1];
 
    make_set(rep);
    for(i=0; i<num_edges; i++){
        //Check if edge creates cycle in the tree, If not add that to tree
        if(find(rep, edges[i].start) != find(rep, edges[i].end)){
            union_1(rep, edges[i].start, edges[i].end);
            mst[count++] = edges[i];
            wt += edges[i].wt;
        }
    }
    // Print the minimum spanning tree
    for(i=0; i<count; i++){
        printf("(%d, %d)\n", mst[i].start, mst[i].end);
    }
}
//Driver program
int main(){
 
    int i;
    for(i=1; i<=NUM_NODE; i++){
        graph[i] = create_node_1(i,0);
    }
    add_edge_2(1,3,10);
    add_edge_2(1,4,7);
    add_edge_2(3,4,9);
    add_edge_2(4,2,32);
    add_edge_2(4,5,23);
 
    krutskal(graph, 5);
 
    return 0;
}
