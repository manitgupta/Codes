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

void InOrder(struct Node *root,FILE* fp)
{
	if(root)
	{
		InOrder(root->left,fp);
		fprintf(fp," %d ",root->data);
		InOrder(root->right,fp);
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

void file_read(char filename[], int N, int *a)
{
	FILE *fp;
	fp = fopen(filename,"r+");
	int i=0;
	while(i < N)
	{
		int num;
		fscanf(fp,"%d",&num);
		a[i++] = num;
	}
	fclose(fp);
}

// Driver program to test above functions
#ifdef _DEBUG
int main(int argc, char* argv[])
{
	struct Node* root = NULL;
    int *arr,SIZE;
	if (argc == 4)
	{
		SIZE = atoi(argv[1]);	
	}
	else
	{
		printf("Insufficient No. of Args!\n");
		printf("Format Example: ./a.out 1000 input.txt output.txt\n");
		exit(0);
	}
	FILE *fp;
	fp = fopen(argv[3],"w+");
	
	fprintf(fp,"The Size is: %d\n",SIZE);
	arr = (int*)malloc(sizeof(int)*SIZE);
	file_read(argv[2],SIZE,arr);

	for (int i = 0; i < SIZE; ++i)
	{
		root = Insert(root,arr[i]);
	}

	
    InOrder(root,fp);
    fclose(fp);
    
    return 0;

}
#endif
