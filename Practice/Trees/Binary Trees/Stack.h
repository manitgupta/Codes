struct Node
{
    int data;
    struct Node *left, *right;
};
 
// Stack type
struct Stack                            //We have to create a stack which pointers to struct Node as it's elements. As in the case of integers, wehere a pointer to an
{                                       //integer (int *array) is used to store elemennts of the stack, a pointer to pointer to struct Node will be used. Memory
    int size;                           //equal to the number of elements is allocated to it and it points to the first block of this memory. Each block is memory
    int top;                            //occupied by a pointer to struct Node.
    struct Node **array;
};
 
// A utility function to create a new tree node
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
 
// A utility function to create a stack of given size
struct Stack* createStack(int size)
{
    struct Stack* stack =
            (struct Stack*) malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->array =
           (struct Node**) malloc(stack->size * sizeof(struct Node*));
    return stack;
}
 
// BASIC OPERATIONS OF STACK
int isFull(struct Stack* stack)
{  return stack->top - 1 == stack->size; }
 
int isEmpty(struct Stack* stack)
{  return stack->top == -1;  }
 
void Push(struct Stack* stack, struct Node* node)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = node;
}
 
struct Node* Pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}

struct Node* Top(struct Stack* stack)
{
    return stack->array[stack->top];
}
 