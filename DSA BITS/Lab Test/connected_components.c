//**************TO find the number of connected componenets in the graph.*************
int visited[NUM_NODE + 1];
 
void dfs_1(Node * current){
    if(!current) return;
    visited[current->value] = true;
    Node *temp = current->next;
    while(temp){
        if(visited[temp->value] != true){
            dfs_1(graph[temp->value]);
        }
        temp = temp->next;
    }
}
 
void connected_component(Node * graph[]){
    int i, count =0;
    Node * current = NULL;
    for(i=0; i< NUM_NODE; i++){
        current  = graph[i];
        if(current && visited[current->value] == false){
            dfs_1(current);
            count++;
        }
    }
    printf("\n Number of connected component : %d", count);
}
//Driver program
int main(){
    int i;
    for(i=1; i<=NUM_NODE; i++){
        graph[i] = create_node(i);
    }
    add_edge_1(1,2);
    add_edge_1(2,3);
    add_edge_1(3,4);
    add_edge_1(5,6);
    for(i=1; i<=NUM_NODE; i++){
        visited[i] = false;
    }
 
    connected_component(graph);
}