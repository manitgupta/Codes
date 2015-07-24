#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

#define _DEBUG

#define Max(a, b)  (a < b ? b : a)
#define Min(a, b)  (a > b ? b : a)
#define INT_MIN -999999

//Reference for Theory: http://www.geeksforgeeks.org/avl-tree-set-1-insertion/

struct Node
{
	int data;
	int height;
	struct Node* left;
	struct Node* right;
};

int Height(struct Node *root)
{
	if(!root)
		return -1;
	else
		return root->height;
}

struct Node* SingleRotateLeft(struct Node* X)		//X is the node which has height imbalance //Left-Left Case,same as RotateRight(z) on GeeksforGeeks
{
	struct Node* W = X->left;
	X->left = W->right;
	W->right = X;
	X->height = Max(Height(X->left),Height(X->right))+1;
	W->height = Max(Height(W->left),X->height))+1;
	return W;
}

struct Node* SingleRotateRight(struct Node* X) //Right-Right Case, same as RotateLeft(z) on GeeksforGeeks.
{
	struct Node* W = X->right;
	X->right = W->left;
	W->left = X;
	X->height = Max(Height(X->left),Height(X->right))+1;
	W->height = Max(Height(W->right),X->height)+1;
	return W;
}

int main()
{
	return 0;
}