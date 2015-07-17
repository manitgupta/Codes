typedef struct queue{
        Node *front;
        Node *rear;
}Queue;
 
int is_empty(Queue *q){
        if(q->front == NULL && q->rear == NULL) return true;
        return false;
}
 
void enqueue(Queue *q, int value){
        Node * temp = (Node *)malloc(sizeof(Node));
        temp->value = value;
        if(is_empty(q)){
                q->front = temp;
                q->rear = temp;
        }
        else{
                if(q->rear){
                        q->rear->next = temp;
                        q->rear = temp;
                }
                else{
                        printf("\n Error ");
                }
        }
}
 
int dequeue(Queue *q){
        if(!is_empty(q)){
                int temp = q->front->value;
                Node * curr = q->front;
                if(q->front == q->rear){
                        q->rear = NULL;
                        q->front = NULL;
                }
                else{
                        q->front = curr->next;
                }
                free(curr);
                return temp;
        }
}
void init_queue(Queue **q){
        *q = (Queue *)malloc(sizeof(Queue));
        (*q)->front = NULL;
        (*q)->rear = NULL;
}
void bfs(Node * current){
 
        Queue *q = NULL;
 
        init_queue(&q);
 
        if(!current) return;
 
        enqueue(q, current->value);
        while(!is_empty(q)){
                int index = dequeue(q);
                printf("\n%d ", index);
                visited[index] = true;
                Node *temp = graph[index]->next;
                while(temp){
                        if(visited[temp->value] == false){
                                visited[temp->value] = true;
                                enqueue(q, temp->value);
                        }
                        temp = temp->next;
                }
        }
 
}

int main(){
 
//      int adj_mat[NUM_NODE][NUM_NODE];
 
        int i,j;
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
 
        bfs(graph[1]);
 
        return 0;
}
