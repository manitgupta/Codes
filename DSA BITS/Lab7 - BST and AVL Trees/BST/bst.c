#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "bst.h"


int compare(int left, int right)
{
	if (left > right)
		return 1;
	else if(left < right)
		return -1;
	else
		return 0;
}

void display(NODE* nd)
{
	if (nd != NULL)
	{
		printf("%d ",nd->data);
	}
}

void display_tree(NODE *nd)
{
	if (nd == NULL)
		return;
	printf("%d ",nd->data);
	if (nd->left != NULL)
	{
		printf("(L:%d)",nd->left->data);
	}
	if (nd->right != NULL)
	{
		printf("(R:%d)",nd->right->data);
	}
	printf("\n");
	display_tree(nd->left);
	display_tree(nd->right);
}

NODE* create_node(int data)
{
	NODE *new_node = (NODE*)malloc(sizeof(NODE));
	if (new_node == NULL)
	{
		fprintf(stderr, "Overflow!\n");
		exit(0);
	}
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

//NODE* insert_node(NODE *root, comparer compare, int data)
NODE* insert_node(NODE *root, int data)
{
	if (root == NULL)
	{
		root = create_node(data); //if no element in Tree, then create a node.
	}
	else
	{
		int is_left = 0;
		int r = 0;
		NODE *cursor = root;
		NODE *prev = NULL;

		while( cursor != NULL)
		{
			r = compare(data, cursor->data);
			prev = cursor;
			if (r < 0)
			{
				is_left = 1;
				cursor = cursor->left; //move pointer to the left. we have already stored
			}							//reference to it's parent in prev.
			else if ( r > 0)
			{
				is_left = 0;
				cursor = cursor->right; 
			}
		}
		if(is_left)
			prev->left = create_node(data); //inserted as left child 
		else
			prev->right = create_node(data); //inserted as right child
	}
	return root;
}

//NODE* delete_node(NODE *root, int data, comparer compare)
NODE* delete_node(NODE *root, int data)
{
	if (root == NULL)
	{
		return NULL; //no element, return NULL
	}
	NODE* cursor;
	int r = compare(data, root->data); //compare with root
	if (r < 0)
	{
		//root->left = delete_node(root->left, data, compare);
		root->left = delete_node(root->left, data); //recursive call to left part of tree. Do this until element is found. NULL will be returned if element is not present since eventually root will become null.
	}												 
	else if (r > 0)									
	{
		//root->right = delete_node(root->right, data, compare);
		root->right = delete_node(root->right, data);
	}	
	else //means r == 0, at this point, after recursive call, the element to be deleted has been found.
	{
		if (root->left == NULL) //Case 1 and Case 2 Both are taken care of since both left and right are initialized NULL. 1 child and no child (Left Subtree is empty)
		{
			cursor = root->right; //move pointer to the node to be deleted and free the node.
			free(root);
			root = cursor; //connect the descandents of the deleted node directly to it's parent.
		}
		else if(root->right == NULL) //1 child, same as above.
		{
			cursor = root->left;
			free(root);
			root = cursor;
		}
		else //last case: When both children are present. We need to find the left most element in the right subtree of the node to be deleted and swap it's contents. The left-most element of the right subtree should be removed from it's place.
		{
			cursor = root->right; //Move to the root of right subtree
			NODE *parent = NULL; //Keep track of parent of left-most succesor since they need to remove it's link with the left-most succesor.

			while (cursor->left != NULL) //traverse
			{
				parent = cursor;
				cursor = cursor->left;
			}//FOUND!
			root->data = cursor->data; //swap contents
			if (parent != NULL)
			{
				//parent->left = delete_node(parent->left,parent->left->data,compare);
				parent->left = delete_node(parent->left,parent->left->data); // Smartly done, will go the left most element and remove it automatically, will match with Case 1 , i.e No Children. recursive call.
			}	
			else // base case when the right subtree has only one element.
			{
				//root->right = delete_node(root->right,root->right->data,compare);
				root->right = delete_node(root->right,root->right->data);
			}	
		}	
	}
	return root;	
}
//Recursive Defnition of search Function.
// NODE* search(NODE *root, int data)
// {
// 	if (root == NULL)
// 		return NULL;
// 	int r;
// 	NODE* cursor = root;
// 	r = compare(data, cursor->data);
// 	if ( r < 0)  //data is in left subtree.
// 	{
// 		cursor = search(cursor->left,data);
// 	}
// 	else if( r > 0)
// 	{
// 		cursor = search(cursor->right,data);
// 	}
// 	else
// 		return cursor;  
// }

NODE* search(NODE *root, int data)
{
	if (root == NULL)
		return NULL;
	int r;
	NODE* cursor = root;
	while(cursor != NULL)
	{
		r = compare(data, cursor->data);
		if (r < 0) //element is present in left subtree.
		{
			cursor = cursor->left; //move to the left subtree
		}
		else if (r > 0)
		{
			cursor = cursor->right; //move to the right subtree
		}
		else //element has been found.
			return cursor;
	}
	return cursor; //for case when element is not present. No necesarry to write.
}

void dispose(NODE* root)
{
	if(root !=NULL)
	{
		root->left = NULL;
		root->right = NULL;
		free(root);
	}
}