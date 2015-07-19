#include <iostream>
#include <cstdlib>
#include <cstdio>

#define _DEBUG

using namespace std;

struct BinaryTreeNode
{
	int data;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
};

typedef struct BinaryTreeNode binarytreenode;

binarytreenode* newNode(int data)
{
    binarytreenode *node = (binarytreenode*)malloc(sizeof(binarytreenode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

void PreOrder(binarytreenode *root)
{
	if(root)
	{
		printf(" %d ",root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
int main()
{

    /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
  binarytreenode *root = newNode(10);
  root->left        = newNode(8);
  root->right       = newNode(6);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left = newNode(2);
  PreOrder(root);
  printf("\n");
  return 0;
}