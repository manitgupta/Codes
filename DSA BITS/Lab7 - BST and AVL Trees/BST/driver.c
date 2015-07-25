#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

#define SIZE 9

int main()
{
	NODE *root = NULL;
	//comparer int_comp = compare;
	//callback f = display;

	int a[SIZE] = {8,3,10,1,6,14,4,7,13};
	int i;
	printf("----------- BST--------\n");
	printf("Insert:");
	for( i = 0 ;i < SIZE; i++)
	{
		printf("%d ",a[i]);
		//root = insert_node(root,int_comp,a[i]);
		root = insert_node(root,a[i]);
	}
	printf(" All Inserted!\n");

	display_tree(root);

	int key = 0;
    NODE* s;
    printf("Enter data to search:");
    scanf("%d",&key);
    s = search(root,key);
    if(s != NULL)
    {
        printf("Found it %d",s->data);
        if(s->left != NULL)
            printf("(L: %d)",s->left->data);
        if(s->right != NULL)
            printf("(R: %d)",s->right->data);
        printf("\n");
    }
    else
    {
        printf("node %d not found\n",key);
    }
    int r;
    do
    {
        printf("Enter data to remove, (-1 to exit):");
        scanf("%d",&r);
        if(r == -1)
            break;
        root = delete_node(root,r);
        /* display the tree */
        if(root != NULL)
            display_tree(root);
        else
            break;
    }
    while(root != NULL);
return 0;
}