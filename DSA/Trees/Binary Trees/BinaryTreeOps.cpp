#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <queue>

#define _DEBUG
// #define _FUNCDG

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

void LevelOrder(struct Node* root)				//Note : Return temp in the end to obtain the deepest node in the tree.
{
	queue <struct Node*> Q;
	if(!root)
		return;
	Q.push(root);
	while(!Q.empty())
	{
		struct Node* temp = Q.front();
		Q.pop();
		printf(" %d ",temp->data);
		if(temp->left)
			Q.push(temp->left);
		if(temp->right)
			Q.push(temp->right);
	}
	printf("\n");
}

struct Node* DeepestNode(struct Node* root)				//Note : Return temp in the end to obtain the deepest node in the tree.
{
	queue <struct Node*> Q;								//Same as Level Order Traversal, since LOT goes level size, deepest node would be at the
	struct Node* temp;									//last level.
	if(!root)										
		return NULL;
	Q.push(root);
	while(!Q.empty())
	{
		temp = Q.front();
		Q.pop();
		if(temp->left)
			Q.push(temp->left);
		if(temp->right)
			Q.push(temp->right);
	}
	return temp;
}
void LeverOrderReverse(struct Node* root)
{
	queue<struct Node*> Q;						//For reverse LOT, traverse the tree using the Queue and store the LOT order in a stack,
	stack<struct Node*> S;						// after completion of traversal pop the stack completely.
	if(!root)
		return;
	Q.push(root);
	S.push(root);
	while(!Q.empty())
	{
		struct Node* temp = Q.front();
		Q.pop();
		if(temp->left)
		{
			Q.push(temp->left);
			S.push(temp->left);
		}
		if(temp->right)
		{
			Q.push(temp->right);
			S.push(temp->right);
		}
	}
	while(!S.empty())
	{
		printf(" %d ",S.top()->data);
		S.pop();
	}
}

int HeightBinaryTree(struct Node* root)
{
	int leftheight,rightheight;
	if(root == NULL)			//base case of recursion for exiting.
		return 0;				//returning 0 since if a root is NULL, it means it not there and it's height will be 0. The node which called 
	else						// recursive function on this node will have a height of 1.
	{
		leftheight = HeightBinaryTree(root->left);
		rightheight = HeightBinaryTree(root->right);
		if(leftheight > rightheight)
			return (leftheight+1);
		else						//takes care of two cases : When leftheight < rightheight AND when both are 0, ie. for leaf nodes...
			return (rightheight+1);
	}
}

int FindMax(struct Node* root)
{
	int max = INT_MIN;
	int left,right;					//Find Max value in left and right subtrees and compare it with the current node value.
	int root_val = INT_MIN;
	if(root != NULL)
	{
		root_val = root->data;
		#ifdef _FUNCDG
		printf("%d Root Value\n",root_val);
		#endif
		left = FindMax(root->left);
		right = FindMax(root->right);
		if(left > right)
		{
			max = left;
			#ifdef _FUNCDG
			printf("%d\n",max);
			#endif
		}	
		else
			{
				max = right;
				#ifdef _FUNCDG
				printf("%d\n",max);
				#endif
			}
		if(root_val > max)
			max = root_val;
	}
	return max;
}

int FindMaxIterative(struct Node* root)			//Use Level Order Traversal and keep track of largest element traversed till now.
{
	int max = INT_MIN;
	if(!root)
		return INT_MIN;
	queue <struct Node*> Q;
	Q.push(root);
	while(!Q.empty())
	{
		struct Node* temp = Q.front();
		Q.pop();
		if(max < temp->data)
			max = temp->data;
		if(temp->left)
			Q.push(temp->left);
		if(temp->right)
			Q.push(temp->right);
	}
	return max;
}

int SearchBinaryTree(struct Node* root, int element)
{
	int temp;
	if(root == NULL)			//Base Case.
		return INT_MIN;
	if(root->data == element)	//if match found then exit
		return 1;
	else						//value not equal to current node
	{
		temp = SearchBinaryTree(root->left,element);	//search in the left subtree via recursion	
		if (temp!=INT_MIN)
			return temp;
		else
		{
			temp = SearchBinaryTree(root->right,element);		//if not in left subtree, search in right
			if(temp!=INT_MIN)
				return temp;
			else
				return INT_MIN;							//not in current, left and right subtrees then not in tree.
		}
	}
}

void DeleteNode(struct Node* root, int element)
{
	int temp;
	struct Node* DeepNode = DeepestNode(root); 			//Find the deepest node.
	if(root == NULL)
		return;
	if(root->data == element)			//Match Found! Delete it!
	{
		root->data = DeepNode->data;
		free(DeepNode);			//DeepNode is a pointer to the node returned by DeepestNode. free deallocates the space pointed to by DeepNode.
	}
	else						//value not equal to current node
	{
		temp = SearchBinaryTree(root->left,element);	//search in the left subtree via recursion	
		if (temp!=INT_MIN)
			return;
		else
		{
			temp = SearchBinaryTree(root->right,element);		//if not in left subtree, search in right
			if(temp!=INT_MIN)
				return; 
			else
				return;							//not in current, left and right subtrees then not in tree.
		}
	}
}

// Driver program to test above functions
#ifdef _DEBUG
int main()
{
    // Let us construct the tree shown in above figure

    /* Constructed binary tree is
            21
          /   \
        2      13
      /  \    / \
    14     5  6   7
    			   \
    			   	34
  */
    struct Node* root = NULL;
    root = newNode(21);
    root->left = newNode(2);
    root->right = newNode(13);
    root->left->left = newNode(14);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->right = newNode(34);
    // printf("\n%d is the Max Value (Iterative)\n",FindMaxIterative(root));
    // printf("%d is the Maxmimum Element in tree\n",FindMax(root));
    // printf("%d: 1 = Match Found, -99999 = NOT FOUND\n",SearchBinaryTree(root,14));
    // printf("Level Order in Reverse:\n");
    // LeverOrderReverse(root);
    // printf("\n%d is the Height of the Binary Tree\n",HeightBinaryTree(root));
    // printf("\n");
    DeleteNode(root,21);
    printf("Level Order Traversal After Deletion:\n");
    LevelOrder(root);
    
    return 0;
}
#endif

