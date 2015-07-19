#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
 
// Maximum stack size
#define MAX_SIZE 100
 
// An iterative function to do post order traversal of a given binary tree
void postOrderIterative(struct Node* root)
{
    // Create two stacks
    struct Stack* s1 = createStack(MAX_SIZE);
    struct Stack* s2 = createStack(MAX_SIZE);
 
    // Push root to first stack
    Push(s1, root);
    struct Node* node;
 
    // Run while first stack is not empty
    while (!isEmpty(s1))
    {
        // Pop an item from s1 and Push it to s2
        node = Pop(s1);
        Push(s2, node);
 
        // Push left and right children of removed item to s1
        if (node->left)
            Push(s1, node->left);
        if (node->right)
            Push(s1, node->right);
    }
 
    // Print all elements of second stack
    while (!isEmpty(s2))
    {
        node = Pop(s2);
        printf("%d ", node->data);
    }
}
 
// Driver program to test above functions
int main()
{
    // Let us construct the tree shown in above figure
    struct Node* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
 
    postOrderIterative(root);
 
    return 0;
}