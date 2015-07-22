#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <queue>

#define _DEBUG
//#define _FUNCDG

#define INT_MIN -99999

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

struct Node* FindInBST(struct Node* root,int element)
{
	if(root == NULL)		//base case
		return NULL;
	if(root->data == element)
	{	
		return root;
	}					//equal then return.
	else if(root->data > element)		//it is less than root, hence it must be in the left subtree.
	{
		FindInBST(root->left,element);
	}	
	else								//it is greater then root, must be in right subtree.
	{
		FindInBST(root->right,element);
	}	
}

struct Node* FindMin(struct Node* root)
{
	if(root == NULL)		//base case, when no tree.
		return NULL;
	if(root->left == NULL)		//Minimum element is the left-most Node i.e. does not have a left child.
		return root;
	else
		return FindMin(root->left);  //Writing return here does not matter???
}

struct Node* FindMax(struct Node* root)
{
	if(root == NULL)
		return NULL;
	if(root->right == NULL)
		return root;
	else
		FindMax(root->right);
}

struct Node* InOrderSuccessor(struct Node* x, struct Node* root)
{
	struct Node* succ = NULL;
	if(x->right != NULL)		//if has a right subtree, then successor is the min element in right subtree. 
	{	
		return FindMin(x->right);
	}
	else		//use a search like technique, if starting from root, x->data > root->data, then move to right subtree, otherwise go left.
	{
		while(root!=NULL)
		{
			if (x->data > root->data)
			{
				root = root->right;
			}	
			else if(x->data < root->data)		//root is greater than
			{
				succ = root;					//make root the successor and move to left subtree to try and find the even smaller successor.
				root = root->left;
			}			
			else							//when root becomes equal to x, DO NOT update successor, just exit
				break;
		}
	}
	return succ;
}

struct Node* InOrderPredecessor(struct Node* x, struct Node* root)
{
	struct Node* pred = NULL;
	if(x->left != NULL)		//if has a left subtree, then predecessor is the max element in left subtree. 
	{	
		return FindMax(x->left);
	}
	else		//use a search like technique, if starting from root, x->data < root->data, then move to left subtree, otherwise go right.
	{
		while(root!=NULL)
		{
			if (x->data > root->data)
			{
				pred = root;					//make root the predecssor and move to right subtree to try and find the even higher predecessor.
				root = root->right;
			}	
			else if(x->data < root->data)		//root is greater than
			{										
				root = root->left;
			}			
			else							//when root becomes equal to x, DO NOT update successor, just exit
				break;
		}
	}
	return pred;
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

struct Node* Insert(struct Node* root, int data)
{
	if(root == NULL)		//When the Tree is empty
	{
		return newNode(data);
	}
	else
	{
		if(data < root->data)	//When data is less than root, move to insert in the left subtree.
			root->left = Insert(root->left,data);		//recursively update the root pointer.
		else if(data > root->data)
			root->right = Insert(root->right,data);
	}
	return root;			//updated pointer returned here.
}
// Driver program to test above functions
#ifdef _DEBUG
int main()
{
    // Let us construct the tree shown in above figure

    /* Constructed binary tree is
            20
          /   \
        8      22
      /  \     
    4     12
    	/	\	  
    	10	14	   
  */
    struct Node* root = NULL;
   	root = Insert(root,20);
    root = Insert(root,20);
    root = Insert(root,8);
    root = Insert(root,22);
    root = Insert(root,4);
    root = Insert(root,12);
    root = Insert(root,10);
    root = Insert(root,14);
    InOrder(root);
    printf("\n");
    // int element =23;
    // if (FindInBST(root,element)!=NULL)
    // 	printf("%d is present in the BST\n",element);
    // else
    // 	printf("%d is NOT present in the BST\n",element);
 
 	// printf("%d is the Min Element of BST\n",FindMin(root)->data);
 	// printf("%d is the Max Element of BST\n",FindMax(root)->data);
 	// printf("%d is the InOrder Successor of %d\n",InOrderSuccessor(root->left->right->right,root)->data,root->left->right->right->data);
 	printf("%d is the InOrder Predecessor of %d\n",InOrderPredecessor(root,root)->data,root->data);    
    return 0;

}
#endif
