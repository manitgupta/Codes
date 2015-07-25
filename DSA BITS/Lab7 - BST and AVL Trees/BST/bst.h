#ifndef TREE_H
#define TREE_H


typedef struct NODE
{
	int data;
	struct NODE *left;
	struct NODE *right;
	//struct NODE* succ;
}NODE;

NODE* create_node(int data);
//typedef int (*comparer)(int,int);
//NODE* insert_node(NODE *root,comparer compare, int data);
//NODE* delete_node(NODE *root, int data, comparer compare);
NODE* insert_node(NODE *root, int data);
NODE* delete_node(NODE *root, int data);
NODE* search(NODE *root, int data);
int compare(int left, int right);
void display(NODE *nd);
void display_tree(NODE *nd);
void dispose(NODE* root);


#endif