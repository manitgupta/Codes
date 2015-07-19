#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
 
// Maximum stack size
#define MAX_SIZE 100
 
// A tree node

// 1) Create an empty stack Stack and push root node to stack.
// 2) Do following while Stack is not empty.
// ….a) Pop an item from stack and print it.
// ….b) Push right child of popped item to stack
// ….c) Push left child of popped item to stack

// Right child is pushed before left child to make sure that left subtree is processed first.

// An iterative function to do post order traversal of a given binary tree
void preOrderIterative(struct Node* root)
{
    struct Stack* S = createStack(10);
    Push(S,root);
    while(!isEmpty(S))
    {
        struct Node* temp = Pop(S);
        printf(" %d ",temp->data);
        if(temp->right)
            Push(S,temp->right);
        if(temp->left)
            Push(S,temp->left);
    }
}
 
// Driver program to test above functions
int main()
{
    // Let us construct the tree shown in above figure

    /* Constructed binary tree is
            1
          /   \
        2      3
      /  \    / \
    4     5  6   7
  */
    struct Node* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    preOrderIterative(root);
    printf("\n");
    return 0;
}