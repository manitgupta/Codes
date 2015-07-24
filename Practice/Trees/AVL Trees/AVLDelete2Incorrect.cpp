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

void PreOrder(struct Node *root)
{
	if(root)
	{
		printf(" %d ",root->data);
        PreOrder(root->left);
		PreOrder(root->right);
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

struct Node* Insert(struct Node* root, int data)
{
    /* 1.  Perform the normal BST rotation */
    if (root == NULL)
        return(newNode(data));
 
    if (data < root->data)
        root->left  = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);
 
    /* 2. Update height of this ancestor root */
    root->height = Max(Height(root->left), Height(root->right)) + 1;
 
    /* 3. Get the balance factor of this ancestor root to check whether
       this root became unbalanced */
    int balance = getBalance(root);
 
    // If this root becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && data < root->left->data)
        return SingleRotateLeft(root);
 
    // Right Right Case
    if (balance < -1 && data > root->right->data)
        return SingleRotateRight(root);
 
    // Left Right Case
    if (balance > 1 && data > root->left->data)
    {
        root->left =  SingleRotateRight(root->left);
        return SingleRotateLeft(root);
    }
 
    // Right Left Case
    if (balance < -1 && data < root->right->data)
    {
        root->right = SingleRotateLeft(root->right);
        return SingleRotateRight(root);
    }
 
    /* return the (unchanged) root pointer */
    return root;
}
struct Node* Delete(struct Node* root, int data)
{
// STEP 1: PERFORM STANDARD BST DELETE
 
    struct Node* temp;
    //First Step: Find the node to be deleted.
    if(root == NULL)
    {
        printf("\nElement is NOT Present\n");
    }
    else if(data < root->data)      //less than root, must be in left subtree
        root->left = Delete(root->left,data);
    else if(data > root->data)      //greater than root, must be in right subtree
        root->right = Delete(root->right,data);
    else            //Means node to be deleted has been found
    {
        if(root->left && root->right)   //Case where node to be deleted has both left and right children.
        {
            temp = FindMax(root->left);//InorderPredecessor Function will also work, however it is guarenteed here that InPredecessor will be largest
            root->data = temp->data;    //element of left subtree (since node to be deleted has a left child)
            root->left = Delete(root->left,temp->data); //Recursively handle deletion of Max element of left subtree.                            
        }
        else    //Case wwhere node to has 1 or 0 child.
        {
            temp = root;                //Make temp eqaul to root and then free it up later.
            if(root->left == NULL)      //Node with only right child. Stick the right child to the node's parent.
            {
                root = root->right;     //Stick child.
                free(temp);             //free up the original root.
                return root;
            }   
            if(root->right == NULL)     //Another if to handle 0th child case as well.
            {
                root = root->left;
                free(temp);
                return root;
            }   
        }                               
    }
    // If the tree had only one node then return
    if (root == NULL)
      return root;
 
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = Max(Height(root->left), Height(root->right)) + 1;
 
    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether
    //  this node became unbalanced)
    int balance = getBalance(root);
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return SingleRotateLeft(root);
 
    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  SingleRotateRight(root->left);
        return SingleRotateLeft(root);
    }
 
    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return SingleRotateRight(root);
 
    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = SingleRotateLeft(root->right);
        return SingleRotateRight(root);
    }
 
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
  	PreOrder(root);
 
  	root = Delete(root, 11);
 
    /* The AVL Tree after deletion of 10
            1
           /  \
          0    9
        /     /  \
       -1    5     11
           /  \
          2    6
    */
 
    printf("\nIn order traversal after deletion of 10 \n");
    PreOrder(root);
 
    return 0;
}