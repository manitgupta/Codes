#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <queue>

#define _DEBUG
// #define _FUNCDG

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

void LevelOrder(struct Node* root)
{
	queue <struct Node*> Q;
	if(!root)
		return;
	Q.push(root);
	while(!Q.empty())
	{
		struct Node* temp = Q.pop();
		printf(" %d ",temp->data);
		if(temp->left)
			Q.push(temp->left);
		if(temp->right)
			Q.push(temp->right);
	}
}

int FindMax(struct Node* root)
{
	int max = -99999;
	int left,right;
	int root_val = -99999;
	if(root != NULL)
	{
		root_val = root->data;
		#ifdef _FUNCDG
		printf("%d Root Value\n",root_val);
		#endif
		left = FindMax(root->left);
		right = FindMax(root->right);
		if(left > right)
		{
			max = left;
			#ifdef _FUNCDG
			printf("%d\n",max);
			#endif
		}	
		else
			{
				max = right;
				#ifdef _FUNCDG
				printf("%d\n",max);
				#endif
			}
		if(root_val > max)
			max = root_val;
	}
	return max;
}
// Driver program to test above functions
#ifdef _DEBUG
int main()
{
    // Let us construct the tree shown in above figure

    /* Constructed binary tree is
            21
          /   \
        2      13
      /  \    / \
    14     5  6   7
    			   \
    			   	34
  */
    struct Node* root = NULL;
    root = newNode(21);
    root->left = newNode(2);
    root->right = newNode(13);
    root->left->left = newNode(14);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->right = newNode(34);
    printf("%d is the Maxmimum Element in tree\n",FindMax(root));
    LevelOrder(root);
    printf("\n");
    return 0;
}
#endif

