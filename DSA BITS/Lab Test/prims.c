#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
#define NUM_NODE 7
#define NUM_WORDS 10
#define NUM_CHAR 4 
#define true 1
#define false 0
 
#define INFINITE 1000
 
typedef struct node{
        int value;
        int wt;
        struct node *next;
}Node;
 
Node *graph[NUM_NODE + 1];
 
void add_edge_2(int i, int j, int wt);
 
int find_minimum_node(int visited[], int dist[]){
        int min = INFINITE;
        int index = -1;
        int i;
        for(i=1; i<= NUM_NODE; i++){
                if(visited[i] == false && min>dist[i]){
                        min = dist[i];
                        index = i;
                }
        }
        return index;
}
 
void dijstras(Node * graph[], int start, int end ){
    int i;
    int parent[NUM_NODE +1];
    int distance[NUM_NODE+1];
 
    for(i=1; i<=NUM_NODE; i++){
        visited[i] = false;
        distance[i] = INFINITE;
        parent[i] = -1;
    }
   // Mark distance of start as 0.
    distance[start] =0;
    for(i=1; i<=NUM_NODE; i++){
        int index  = find_minimum_node(visited, distance);
        if(index != -1){
            Node * node = graph[index];
            Node * current  = node->next;
 
            while(current){
               /*If neihbour node is not visited and its current distance is 
                more than distance of current node + cost of edge between 
                current node and this node, update the distance */
                if(visited[current->value] == false && distance[current->value] >
                    distance[node->value] + current->wt){
                
                    distance[current->value] = distance[node->value] + current->wt;
                    parent[current->value] = node->value;
                }
                current = current->next;
            }
            visited[node->value] = true;
            if(node->value == end)
                break;
        }
        else{
            break;
        }
    }
 
 
    printf("\nDistance between %d and %d : %d", start , end, distance[end]);
    
    // Printing path in reverse order,using stack, we can print it normal order to.
    printf("\nPath is  (In reverse order): ");
    int cur_parent =0;
    while(cur_parent != -1){
        printf("%d ", end );
        cur_parent = parent[end];
        end = cur_parent;
    }
    printf("\n");
}
 
//driver program
int main(){
 
    int i,j;
    for(i=1; i<=NUM_NODE; i++){
        graph[i] = create_node_1(i,0);
    }
    // creating graph with weighted edges.
    add_edge_2(1,2,4);
    add_edge_2(1,3,8);
    add_edge_2(2,3,9);
    add_edge_2(2,4,9);
    add_edge_2(3,4,2);
    add_edge_2(2,5,10);
    add_edge_2(3,6,1);
    add_edge_2(4,5,7);
    add_edge_2(4,6,9);
    add_edge_2(5,6,6);
    add_edge_2(6,7,2);
    add_edge_2(7,5,5);
 
    // Adjancancy matrix based representation       
    for(i=1; i<=NUM_NODE; i++){
        printf("Nodes adjacent to %d : ", i);
 
        Node * current  = graph[i];
        while(current){
            printf("%d ", current->value);
            current = current->next;
        }
        printf("\n");
    }
    
    dijstras(graph, 1, 6);
    
    return 0;
}
 
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


