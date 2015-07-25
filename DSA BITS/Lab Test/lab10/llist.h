#ifndef LLIST_H
#define LLIST_H

#include "data.h"

struct NODE
{
	vertex val;
	struct NODE *next;
	struct NODE *prev;
};

typedef struct NODE node;

typedef struct
{
	int size;
	node *head;
	node *tail;
}llist;

llist createLList();
void push_front(vertex e, llist *l);
void push_back(vertex e, llist *l);
vertex pop_front(llist *l);
vertex pop_back(llist *l);
//void displayList(llist *l);
void clearList(llist *l);
//void insertSortLL(llist *l);
//void mergeSortLL(llist *l);
//void quickSortLL(llist *l);
//void quickSortHelperLL(llist *l1, node *l, node *r);
//node* partitionLL(llist *l1, node *l, node *r);

#endif
