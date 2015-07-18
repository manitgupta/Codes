#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

int blockSize;	//Max number of nodes in a block

struct ListNode
{
	struct ListNode *next;
	int value;					//Node structure of creating Circular linked list inside the blocks.
};

struct LinkedBlock
{
	struct LinkedBlock *next;	//Is the connection between two blocks.
	struct ListNode *head;		//This is the head of the circular linked list.
	int nodeCount;				//Count of number of nodes in each block.
};
typedef struct ListNode listnode;
typedef struct LinkedBlock linkedblock;
linkedblock *blockHead;

linkedblock* newLinkedBlock()	//Create a new Empty Block.
{
	linkedblock *block = (linkedblock*)malloc(sizeof(linkedblock));
	block->next = NULL;
	block->head = NULL;
	block->nodeCount = 0;
	return block;
}

listnode* newListNode(int value)
{
	listnode *temp = (listnode*)malloc(sizeof(listnode));
	temp->next =NULL;
	temp->value = value;
	return temp;
}

void searchElement(int k,linkedblock **fLinkedBlock, listnode **fListNode)
{
	int j = (k+blockSize-1)/blockSize;		//j is the block number of node k
	linkedblock *p = blockHead;
	while (--j)
	{
		p = p->next;		//traverse to the block j
	}
	*fLinkedBlock = p;
	listnode *q = p->head;
	k = k%blockSize;		//remainder the position of element.
	if (k == 0) //if multiple, then last elemrnt of block
	{
		k = blockSize;
	}
	k = p->nodeCount + 1 - k;
	while (k--)
	{
		q = q->next;
	}
	*fListNode = q;
}

void shift(linkedblock *A)
{
	linkedblock *B;
	listnode *temp;
	while (A->nodeCount > blockSize) //if this block will have to perform shift operation.
	{
		if (A->next == NULL) //if A is the last block. Then create a new block and peform shift.
		{
			A->next = newLinkedBlock();
			B = A->next; //Assign newLinkedBlock to B. Now perform shift.
			temp = A->head->next;
			A->head->next = temp->next; //or A->head->next->next
			B->head = temp;
			temp->next = temp;		//Since B is newly created with temp as the only node.
			A->nodeCount--;
			B->nodeCount++;
		}
		else
		{
			B = A->next;
			temp = A->head->next;
			A->head->next = temp->next;
			temp->next = B->head->next;
			B->head->next = temp;
			B->head = temp;
			B->nodeCount++;
			A->nodeCount--;
		}
		A = B;
	}
}

void addElement(int k, int x)
{
	listnode *p,*q;
	linkedblock *r;

	if (!blockHead)
	{
		blockHead = newLinkedBlock();
		blockHead->head = newListNode(x);
		blockHead->head->next = blockHead->head;
		blockHead->nodeCount++;
	}
	else
	{
		if(k == 0) //addElement at first position.
		{
			p =  blockHead->head;
			q = p->next;
			p->next = newListNode(x);
			p->next->next = q;
			blockHead->head = p->next;
			blockHead->nodeCount++;
			shift(blockHead);
		}
		else
		{
			searchElement(k,&r,&p);
			q = p;
			while(q->next!=p)	//used to come to the position next to the node where it element is to be added. Remember the way circular linked list is linked.
				q =q->next;
			q->next = newListNode(x);
			q->next->next = p;
			r->nodeCount++;
			shift(r);
		}
	}
}
int searchElement(int k)
{
	listnode *p;
	linkedblock *q;
	searchElement(k,&q,&p);	//we need to pass pointer to pointer to searchElement
	return p->value;
}

int testUnRolledLinkedList()
{
	int i,k,x;
	blockSize = 4; //should write the function for blockSize here.
	
	addElement(0,10);
	addElement(1,1);
	addElement(2,30);
	addElement(3,6);
	
	addElement(4,70);
	addElement(5,3);
	addElement(6,45);
	addElement(7,2);
	
	addElement(8,91);
	addElement(9,19);
	addElement(10,4);
	addElement(11,17);

	printf("Enter the position of element to search:\n");
	scanf("%d",&i);
	printf("Element is:%d\n",searchElement(i));
	printf("Enter the position of element to add at:\n");
	scanf("%d",&k);
	printf("Enter the value of element:\n");
	scanf("%d",&x);
	addElement(k,x);
}

int main()
{
	testUnRolledLinkedList();

	return 0;
}