#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "BinaryTreeNode.h"

#define _DEBUG

using namespace std;


void PreOrder(binarytreenode *root)
{
	if(root)
	{
		printf(" %d ",root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
#ifdef _DEBUG
int main()
{
  /* Constructed binary tree is
          10
        /   \
      8      6
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
#endif