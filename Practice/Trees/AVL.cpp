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

struct Node* newNode(int data)
{
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    node->height = 0;			//Node is initially added as a leaf, whose height is defined 0.
    return node;
}

int Height(struct Node *root)
{
	if(!root)
		return -1;
	else
		return root->height;
}

int getBalance(struct Node* N)		//Get the Balance factor of a Tree Node N
{
	if(!N)
		return -1;
	else
		return (Height(N->left) - Height(N->right));
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
	//Perform Rotations.
	struct Node* Y = Z->left;
	Z->left = Y->right;
	Y->right = Z;
	//Update Heights
	Z->height = Max(Height(Z->left),Height(Z->right))+1;
	Y->height = Max(Height(Y->left),Height(Y->right))+1;			//Optimization : Y->height = Max(Height(Y->left),Z->height)+1;
	//New Root must be returned.
	return Y;
}
//Right-Right Case, same as RotateLeft(z) on GeeksforGeeks.
struct Node* SingleRotateRight(struct Node* Z) 
{
	//Perform Rotation.
	struct Node* Y = Z->right;
	Z->right = Y->left;
	Y->left = Z;
	//Update Heights
	Z->height = Max(Height(Z->left),Height(Z->right))+1;
	Y->height = Max(Height(Y->left),Height(Y->right))+1;
	//New Root Must be returned.
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

struct Node* Insert(struct Node *root,int data)
{
	if(root == NULL)
		return newNode(data);
	else if(data < root->data)
	{
		root->left = Insert(root->left,data);			//Recursively move to insert in Left Subtree. Same as BST.
		if(getBalance(root) == 2)
		{
			if(data < root->left->data)
				root = SingleRotateLeft(root);				//Case 1: Left-Left Case. Remember SingleRotateLeft returns the new root.
			else
				root = DoubleRotateLeftRight(root);			//Case 2: Left-Right Case.	
		}
		
	}
	else if(data > root->data)
	{
		root->right = Insert(root->right,data); 		//Recursively move to insert in Right Subtree. Same as BST.
		if(getBalance(root) == 2)
		{
			if (data > root->right->data)
				root = SingleRotateRight(root);				//Case 3 : Right-Right Case.
			else
				root = DoubleRotateRightLeft(root);			//Case 4 : Right-Left Case.	
		}		
	}
	//After Insertion, update/increase the height of the root, all others are updated via calls to Rotation functions.
	root->height = Max(Height(root->left),Height(root->right))+1;
	return root;
}
void InOrder(struct Node *root)
{
	if(root)
	{
		InOrder(root->left);
		printf(" %d ",root->data);
		InOrder(root->right);
	}
}
int main()
{
	struct Node *root = NULL;
 
  	/* Constructing tree given in the above figure */
  	root = Insert(root, 10);
  	root = Insert(root, 20);
  	root = Insert(root, 30);
  	root = Insert(root, 40);
  	root = Insert(root, 50);
  	root = Insert(root, 25);
 
  	/* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50
  	*/
 
  	printf("In order traversal of the constructed AVL tree is \n");
  	InOrder(root);
 
  	return 0;
}