#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "Stack.h"

#define _DEBUG

using namespace std;

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

void preOrderIterative(struct Node* root)
{
    struct Stack* S = createStack(10);
    while(1)
    {
        while(root)
        {
            printf(" %d ",root->data);
            Push(S,root);
            root = root->left;
        }
        if(isEmpty(S))
            break;
        root = Pop(S);
        root = root->right;
    }
}

void PostOrderIterative(struct Node* root)
{
	if(!root)
		return;
	struct Stack *S = createStack(10);
	struct Node *previous = NULL;
	Push(S,root);
	while(!isEmpty(S))
	{
		struct Node *current = Pop(S);
		Push(S,current);
		// #ifdef _DEBUG
		// printf(" %d ",current->data);
		// #endif
		if (previous == NULL || previous->left == current || previous->right == current)		//1st Case : Current is root or doing downwards in the tree.S
		{
			if(current->left)
				Push(S,current->left);
			else if(current->right)
				Push(S,current->right);
			else
			{
				printf(" %d ",current->data);
				Pop(S);
			}
		}
		else if(current->left == previous)				//traversing up from the left subtree. For Postorder, push right subtree first and if not there, then pop current.
		{
			if(current->right)
				Push(S,current->right);
			else
			{
				printf(" %d ",current->data);
				Pop(S);
			}
		}
		else
		{
			printf(" %d ",current->data);				//traversing up from right subtree, means we are through with left and right both, then pop and process current.
			Pop(S);
		}
		previous = current;
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
    PostOrderIterative(root);
    printf("\n");
    return 0;
}