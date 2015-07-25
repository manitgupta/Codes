#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <queue>

#define _DEBUG

using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data)
{
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
 

void PostOrderIterative(struct Node* root)
{
	if(!root)
		return;
	stack <struct Node*> S;
	struct Node *previous = NULL;
	S.push(root);
	while(!S.empty())
	{
		struct Node *current = S.top();
		// #ifdef _DEBUG
		// printf(" %d ",current->data);
		// #endif
		if (previous == NULL || previous->left == current || previous->right == current)		//1st Case : Current is root or doing downwards in the tree.S
		{
			if(current->left)
				S.push(current->left);
			else if(current->right)
				S.push(current->right);
			else
			{
				printf(" %d ",current->data);
				S.pop();
			}
		}
		else if(current->left == previous)				//traversing up from the left subtree. For Postorder, push right subtree first and if not there, 
		{												//then pop current.
			if(current->right)
				S.push(current->right);
			else
			{
				printf(" %d ",current->data);
				S.pop();
			}
		}
		else
		{
			printf(" %d ",current->data);				//traversing up from right subtree, means we are through with left and right both, 
			S.pop();									//then pop and process current.
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