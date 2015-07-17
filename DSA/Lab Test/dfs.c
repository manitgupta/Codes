int visited[NUM_NODE + 1];
void dfs(Node * current){
        if(!current) return;
 
        visited[current->value] = true;
        printf("%d ", current->value);
        Node *temp = current->next;
        while(temp){
                if(visited[temp->value] != true){
                        dfs(graph[temp->value]);
                }
                temp = temp->next;
        }
}
int main(){
 
        int i;
        for(i=1; i<=NUM_NODE; i++){
                graph[i] = create_node(i);
        }
        add_edge_1(1,2);
        add_edge_1(1,5);
        add_edge_1(2,3);
        add_edge_1(2,4);
        add_edge_1(3,4);
        add_edge_1(4,6);
        add_edge_1(5,4);
        add_edge_1(5,6);
 
        for(i=1; i<=NUM_NODE; i++){
                visited[i] = false;
        }
 
        dfs(graph[1]);
 
        return 0;
}