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

// Nodes:
// W : Newly Inserted Node.
// Z : First Node where height imbalance occurs while traveling up from W.
// Y : Child of Z present on the path from W to Z.
// X : Grandchlid of Z present on the path from W to Z.
// 
//a) Left Left Case
// T1, T2, T3 and T4 are subtrees.
//          z                                      y 
//         / \                                   /   \	
//        y   T4      Right Rotate (z)          x      z
//       / \          - - - - - - - - ->      /  \    /  \ 
//      x   T3        SingleRotateLeft(Z)    T1  T2  T3  T4
//     / \				
//   T1   T2
// b) Left Right Case

//      z                               z                           x
//     / \                            /   \                        /  \ 
//    y   T4  Left Rotate (y)        x    T4  Right Rotate(z)    y      z
//   / \      - - - - - - - - ->    /  \      - - - - - - - ->  / \    / \	
// T1   x                          y    T3                    T1  T2 T3  T4
//     / \                        / \	
//   T2   T3                    T1   T2
// c) Right Right Case

//   z                               			   y
//  /  \                            			 /   \ 
// T1   y     Left Rotate(z)       				z      x
//     /  \   - - - - - - - ->    			   / \    / \	
//    T2   x    SingleRotateRight(Z)         T1  T2 T3  T4
//        / \	
//      T3  T4
// d) Right Left Case

//    z                            z                            x
//   / \                          / \                          /  \ 
// T1   y   Right Rotate (y)    T1   x      Left Rotate(z)   z      y
//     / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \    / \	
//    x   T4                      T2   y                  T1  T2  T3  T4
//   / \                              /  \	
// T2   T3                           T3   T4


//Left-Left Case,same as RotateRight(z) on GeeksforGeeks
struct Node* SingleRotateLeft(struct Node* Z)		 
{
	struct Node* Y = Z->left;
	Z->left = Y->right;
	Y->right = Z;
	Z->height = Max(Height(Z->left),Height(Z->right))+1;
	Y->height = Max(Height(Y->left),Z->height)+1;
	return Y;
}
//Right-Right Case, same as RotateLeft(z) on GeeksforGeeks.
struct Node* SingleRotateRight(struct Node* Z) 
{
	struct Node* Y = Z->right;
	Z->right = Y->left;
	Y->left = Z;
	Z->height = Max(Height(Z->left),Height(Z->right))+1;
	Y->height = Max(Height(Y->right),Z->height)+1;
	return Y;
}
//Left-Right Case, i.e. Node is inserted in the right subtree of the left child.
struct Node* DoubleRotateLeftRight(struct Node *Z) 
{
	struct Node* Y = Z->left;
	Y = SingleRotateRight(Y);
	Z = SingleRotateLeft(Z);
	return Z;
}

struct Node* DoubleRotateRightLeft(struct Node *Z)
{
	struct Node* Y = Z->right;
	Y = SingleRotateLeft(Y);
	Z = SingleRotateRight(Z);
	return Z;
}

int main()
{
	return 0;
}