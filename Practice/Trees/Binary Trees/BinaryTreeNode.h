struct BinaryTreeNode
{
	int data;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
};

typedef struct BinaryTreeNode binarytreenode;

binarytreenode* newNode(int data)
{
    binarytreenode *node = (binarytreenode*)malloc(sizeof(binarytreenode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
