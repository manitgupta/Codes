//************DETECT CYCLE USING DFS***************
int visited[NUM_NODE + 1];
int onStack[NUM_NODE + 1];
 
void dfs(Node * current){
        if(!current) return;
        onStack[current->value] = true;
        visited[current->value] = true;
        Node *temp = current->next;
        while(temp){
                if(onStack[temp->value] == true){
                        printf("\n Cycle detected at node %d", temp->value);
                }
                else if(visited[temp->value] != true){
                        dfs(graph[temp->value]);
                }
                temp = temp->next;
        }
        onStack[current->value] = false;
}
//Driver program
int main(){
 
        int i;
        for(i=1; i<=NUM_NODE; i++){
                graph[i] = create_node(i);
        }
        add_edge_1(1,2);
        add_edge_1(1,5);
        add_edge_1(2,3);
        add_edge_1(2,4);
        add_edge_1(4,1);
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