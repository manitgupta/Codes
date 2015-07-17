#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;					//Circular Linked List.

struct CLLNode
{
	int data;
	struct CLLNode *next;
};

typedef struct CLLNode cllnode;

int CircularListLength(cllnode *head)
{
	cllnode *current = head;
	int count = 0;
	do
	{
		count++;
		current = current->next;
	}while(current!=head);

	return count;
}

void PrintCircularListData(cllnode *head)
{
	cllnode *current = head;
	if (head == NULL)
	{
		printf("%s\n","Empty");
		return;
	}
	do
	{
		printf("%d\n",current->data);
		current = current->next;
	} while(current!=head);
}

void InsertAtEndInCLL(cllnode **head, int data) //head is a pointer to a pointer here
{
	cllnode *current = *head;
	cllnode *newNode = (cllnode*)malloc(sizeof(cllnode));
	if (!newNode)
	{
		printf("%s\n","Mem Error");
		return;
	}
	newNode->data = data;
	newNode->next = newNode; //new node pointing to itself for the case of empty list.
	while(current->next!=*head)
		current = current->next;
	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		newNode->next = *head;
		current->next = newNode;
	}
}

void InsertAtBeginInCLL(cllnode **head, int data) //head is a pointer to a pointer here
{
	cllnode *current = *head;
	cllnode *newNode = (cllnode*)malloc(sizeof(cllnode));
	if (!newNode)
	{
		printf("Mem Error \n");
		return;
	}
	newNode->data = data;
	newNode->next = newNode; //new node pointing to itself for the case of empty list.
	while(current->next!=*head)
		current = current->next;
	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		newNode->next = *head;
		current->next = newNode;
		*head = newNode;  			//This Line is the ONLY Difference between inserting at the end and the beginning.
	}
}

void DeleteLastNodeFromCLL(cllnode **head)
{
	cllnode *temp = *head;
	cllnode *current = *head;
	if(*head == NULL)
	{
		printf("List Empty\n");
		return;
	}
	while(current->next!=*head)
	{
		temp = current; //to keep track of previous node
		current = current->next;
	}
	temp->next = current->next;
	free(current);
	return;
}

void DeleteFirstNodeFromCLL(cllnode **head)
{
	cllnode *current = *head;
	if(*head == NULL)
	{
		printf("List Empty\n");
		return;
	}
	while(current->next!=*head)
		current = current->next;
	current->next = (*head)->next;
	*head = (*head)->next;
	return;
}