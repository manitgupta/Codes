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
	{
		printf("Not Found in tree\n");
		return NULL;
		// exit(0);
	}	
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

struct Node* Delete(struct Node* root, int data)
{
	struct Node* temp;
	//First Step: Find the node to be deleted.
	if(root == NULL)
	{
		printf("\nElement is NOT Present\n");
	}
	else if(data < root->data)		//less than root, must be in left subtree
		root->left = Delete(root->left,data);
	else if(data > root->data)		//greater than root, must be in right subtree
		root->right = Delete(root->right,data);
	else			//Means node to be deleted has been found
	{
		if(root->left && root->right)	//Case where node to be deleted has both left and right children.
		{
			temp = FindMax(root->left);//InorderPredecessor Function will also work, however it is guarenteed here that InPredecessor will be largest
			root->data = temp->data;	//element of left subtree (since node to be deleted has a left child)
			root->left = Delete(root->left,temp->data);	//Recursively handle deletion of Max element of left subtree.							 
		}
		else	//Case wwhere node to has 1 or 0 child.
		{
			if(root->left == NULL)		//Node with only right child. Stick the right child to the node's parent.
				root = root->right;
			if(root->right == NULL)		//Another if to handle 0th child case as well.
				root = root->left;
		}								
	}
	return root;
}

struct Node* FindLCA(struct Node *root, int first, int second) 		//LCA is the first ancestor whose value is between a & b.
{
	struct Node *a,*b;
	a = FindInBST(root,first);
	b = FindInBST(root,second);
	if(b != NULL && a!= NULL)
	{
		while(1)
		{
			if((a->data > root->data && b->data < root->data) || (a->data < root->data && b->data > root->data))	//root is between a&b; hence it is LCA
				return root;
			if(root->data < a->data && root->data < b->data)		//root is less than both a and b, LCA must be in right subtree.
				root = root->right;
			else
				root = root->left;				//last condition : root is greater than both a & b, LCA must be in left subtree.
		}
		return root;	
	}
	else
	{
		printf("Elements not in Tree.\n");
		return NULL;
	}
	
}

// Driver program to test above functions
#ifdef _DEBUG
int main()
{
    // Let us construct the tree shown in above figure

    /* Constructed binary tree is (example on book Pg. 163)
            4
          /   \
        2      8
         	 /	  \
         	5      12
        	 \
    	  	  7
    	  	 /
			6		   
  */
    struct Node* root = NULL;

    root = Insert(root,4);
    root = Insert(root,2);
    root = Insert(root,8);
    root = Insert(root,5);
    root = Insert(root,12);
    root = Insert(root,7);
    root = Insert(root,6);
    InOrder(root);
    root = Delete(root,7);
    printf("\n");
    InOrder(root);
    printf("\n");
    printf("%d is the LCA\n",FindLCA(root,6,12)->data);
    // int element =23;
    // if (FindInBST(root,element)!=NULL)
    // 	printf("%d is present in the BST\n",element);
    // else
    // 	printf("%d is NOT present in the BST\n",element);
 
 	// printf("%d is the Min Element of BST\n",FindMin(root)->data);
 	// printf("%d is the Max Element of BST\n",FindMax(root)->data);
 	// printf("%d is the InOrder Successor of %d\n",InOrderSuccessor(root->left->right->right,root)->data,root->left->right->right->data);
 	// printf("%d is the InOrder Predecessor of %d\n",InOrderPredecessor(root,root)->data,root->data);    
    return 0;

}
#endif
