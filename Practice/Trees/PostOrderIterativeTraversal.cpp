#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "Stack.h"

#define _DEBUG

using namespace std;


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
		if (previous == NULL || previous->left == current || previous->right == current)
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
		else if(current->left == previous)
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
			printf(" %d ",current->data);
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