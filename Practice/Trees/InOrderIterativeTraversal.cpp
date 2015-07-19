#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
 
// Maximum stack size
#define MAX_SIZE 100
 
// A tree node


void InOrderIterative(struct Node* root)
{
    struct Stack* S = createStack(10);
    while(1)
    {
        while(root)
        {
            Push(S,root);
            root = root->left;
        }
        if(isEmpty(S))
            break;
        root = Pop(S);
        printf(" %d ",root->data);
        root = root->right;
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
    InOrderIterative(root);
    printf("\n");
    return 0;
}