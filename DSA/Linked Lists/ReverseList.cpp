#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct ListNode
{
	int data;
	struct ListNode *next;
};

typedef struct ListNode listnode;

listnode* ReverseList(listnode *head) //iterative version
{
	listnode *temp = NULL;
	listnode *nextNode = NULL;
	while(head)
	{
		nextNode = head->next;
		head->next = temp;
		temp = head;
		head = nextNode;
	}
	return temp;
}

listnode* RecurseReverse(listnode *head)
{
	if(head == NULL)
	{
		return NULL;
	}
	if(head->next == NULL)
	{
		return head;
	}
	listnode *secondElem = head->next;
	head->next = NULL;
	listnode *reverseRest = RecurseReverse(secondElem);
	secondElem->next = head;
	return reverseRest;
}

void printLinkedList(listnode *head)
{
	listnode *temp = head;
	int count = 0;

	while(temp !=NULL)
	{
		printf(" %d ",temp->data);
		temp = temp->next;
		count++;
	}
	printf("\nCount = %d\n",count);
}

listnode* InsertinLinkedList(listnode *head, int data)		//Inserting at beginning.
{
	listnode *newNode = (listnode*)malloc(sizeof(listnode));
	newNode->data = data;
	//printf("%d\n",newNode->data);
	newNode->next = head;
	head = newNode;
	return head;
}

int main()
{
	listnode *head = NULL;
	head = InsertinLinkedList(head,5);
	head = InsertinLinkedList(head,8);
	head = InsertinLinkedList(head,10);
	head = InsertinLinkedList(head,15);
	printLinkedList(head);
	head = RecurseReverse(head);
	printLinkedList(head);
	return 0;
}
