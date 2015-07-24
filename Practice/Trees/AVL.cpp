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
    node->height = -1;			//Node is initially only allocated, when it is added to the tree, it's height will be updated, hence = -1.
    return node;
}

int Height(struct Node *root)
{
	if(!root)
		return -1;		//Height of NULL NODE is -1
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

void InOrder(struct Node *root)
{
	if(root)
	{
		InOrder(root->left);
		printf(" %d ",root->data);
		InOrder(root->right);
	}
}

struct Node* FindMax(struct Node* root) //Max is the right most element
{
	if(root == NULL)
		return NULL;
	if(root->right == NULL)
		return root;
	else
		FindMax(root->right);
}

struct Node* Insert(struct Node *root,int data)
{
	if(root == NULL)
		{	
			root = newNode(data);
			//printf("%d %d \n",root->height,root->data);
		}
	else if(data < root->data)
	{
		root->left = Insert(root->left,data);			//Recursively move to insert in Left Subtree. Same as BST.
		if(getBalance(root) == 2)						//If Imbalance, then perform rotationss (getBalance(root) > 1) will also work
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
	//printf("%d %d\n",root->height,root->data);
	return root;
}

struct Node* Delete(struct Node* root, int data)
{
    // STEP 1: PERFORM STANDARD BST DELETE
 	struct Node* temp;
    if (root == NULL)
        return root;
 
    // If the data to be deleted is smaller than the root's data,
    // then it lies in left subtree
    if ( data < root->data )
        root->left = Delete(root->left, data);
 
    // If the data to be deleted is greater than the root's data,
    // then it lies in right subtree
    else if( data > root->data )
        root->right = Delete(root->right, data);
 
    // if data is same as root's data, then This is the Node
    // to be deleted
    else
    {
        if(root->left && root->right)	//Case where node to be deleted has both left and right children.
		{
			temp = FindMax(root->left);//InorderPredecessor Function will also work, however it is guarenteed here that InPredecessor will be largest
			root->data = temp->data;	//element of left subtree (since node to be deleted has a left child)
			root->left = Delete(root->left,temp->data);	//Recursively handle deletion of Max element of left subtree.							 
		}
		else	//Case wwhere node to has 1 or 0 child.
		{
			temp = root;
			if(root->left == NULL)		//Node with only right child. Stick the right child to the node's parent.
			{
				root = root->right;
				free(temp);
				return root;
			}	
			if(root->right == NULL)		//Another if to handle 0th child case as well.
			{
				root = root->left;
				free(temp);
				return root;
			}	
		}
    }
    //New Way of writing LOGIC using getBalance() function, Delete() can be written in the same manner as
    //insert as well

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
  /*  root->height = Max(Height(root->left), Height(root->right)) + 1;
 
    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether
    //  this node became unbalanced)
    int balance = getBalance(root);	//Will calculate Balance Factor for root.
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance == 2 && getBalance(root->left) >= 0)		//balance == 2 means left - right == 2 means imbalance in left subtree
        return SingleRotateLeft(root);							//getBalance(root->left)>=0 means left-subtree is as large as or one greater
 															// than right subtree. Hence it must be the left-left case.
    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
        return DoubleRotateLeftRight(root);
 
    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return SingleRotateRight(root);
 
    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
        return DoubleRotateRightLeft(root);
 */
    return root;
}

int main()
{
	struct Node *root = NULL;
 
  	
  /* Constructing tree given in the above figure */
    root = Insert(root, 9);
    root = Insert(root, 5);
    root = Insert(root, 10);
    root = Insert(root, 0);
    root = Insert(root, 6);
    root = Insert(root, 11);
    root = Insert(root, -1);
    root = Insert(root, 1);
    root = Insert(root, 2);
 
    /* The constructed AVL Tree would be
            9
           /  \
          1    10
        /  \     \
       0    5     11
      /    /  \
     -1   2    6
    */
 
  	printf("In order traversal of the constructed AVL tree is \n");
  	InOrder(root);
 
  	root = Delete(root, 10);
 
    /* The AVL Tree after deletion of 10
            1
           /  \
          0    9
        /     /  \
       -1    5     11
           /  \
          2    6
    */
 
    printf("\nPre order traversal after deletion of 10 \n");
    InOrder(root);
 
    return 0;
}