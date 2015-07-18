#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

 struct DLLNode
 {
 	int data;
 	struct DLLNode *next;
 	struct DLLNode *prev;
 };

typedef struct DLLNode dllnode;

 void DLLInsert(dllnode **head, int data, int position)
 {
 	int k = 1;			//head is pointer to a pointer
 	dllnode *temp, *newNode;	//temp and new are just pointers of type dllnode
 	newNode = (dllnode*)malloc(sizeof(dllnode));
 	if(!newNode)
 	{
 		printf("Memory Error\n");
 		return;
 	}
 	newNode->data = data;

 	if(position ==1)
 	{
 		newNode->prev = NULL;
 		newNode->next = *head;

 		if(*head)
 			(*head)->prev = newNode;
 		*head = newNode;
 		return;		
 	}
 	temp = *head;
 	while((k < position -1) && temp->next!=NULL)
 	{
 		temp = temp->next;
 		k++;
 	}
 	if(k!=position)
 	{
 		printf("Invalid Position\n");
 	}
 	newNode->next = temp->next;
 	newNode->prev = temp;
 	if (temp->next)
 		temp->next->prev = newNode;

 	temp->next = newNode;
 	return;
 }

 void DLLDelete (dllnode **head, int position)
 {
 	dllnode *temp, *temp2;
 	int k = 1;
 	temp = *head;
 	if(*head == NULL)
 	{
 		printf("Empty list\n");
 	}
 	if (position == 1)
 	{
 		*head = (*head)->next;	//remember that the list might be one element long. (*head)->prev = NULL; would give error here.	
 	}
 	if(*head != NULL)
 	{
 		(*head)->prev = NULL;
 		free(temp);
 		return;
 	}	
 	while((k < position) && temp->next != NULL)
 	{
 		temp = temp ->next;
 		k++;
 	}
 	if (k != position)
 	{
 		printf("Invalid Position\n");		
 	}
 	temp2 = temp->prev;			//common for intermediate and last node
 	temp2->next = temp->next;

 	if(temp->next) //if next is not NULL, means deletion from intermediate node
 	{
 		temp->next->prev = temp2;
 	}
 	free(temp);
 	return;
 }