#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "BinaryTreeNode.h"
#define _DEBUG

using namespace std;

void PostOrder(binarytreenode *root)
{
	if(root)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		printf(" %d ",root->data);
	}
}

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
  PostOrder(root);
  printf("\n");
  return 0;
}