#include <stdio.h>
#include <stdlib.h>


/*
	Author = Manit Gupta
	Program = Header File which implements the Stack in C using Linked Lists.
	Push, Pop return the Head pointer of the stack.
	init initializes the Head pointer.
	empty checks if the Head pointer is empty.
*/

typedef struct NODE
{
	int data;
	struct NODE *next;
}NODE;

#ifndef LINKEDSTACK
#define LINKEDSTACK

int empty(NODE *Head);
NODE* push(NODE *Head,int val);
NODE* pop(NODE *Head,int val);
void init(NODE *Head);
void display(NODE* Head);

#endif
//Declares the function prototypes if not declared.		





void init(NODE *Head)
{
	Head = NULL;
}

NODE* push(NODE *Head,int val)
{
	NODE *temp;
	temp = (NODE*) malloc(sizeof(NODE));
	if(temp == NULL)
	{
		printf("Overflow!\n");
		exit(0);
	} 
	temp->data = val;
	if(Head == NULL) //The first element.
	{
		Head = temp;
		Head->next = NULL;
	}
	else 		//The other elements. Head needs to move forward.
	{
		temp->next = Head;
		Head = temp;
	}
	return Head;
}

NODE* pop(NODE *Head,int val)
{
	NODE *temp = Head;
	if(temp ==NULL)
	{
		printf("Stack is Empty!\n");
	}
	val = temp->data;
	Head = Head->next;
	free(temp);
	return Head;
}

void display(NODE *Head)
{
	NODE *temp = Head;
	if(temp !=NULL)
	{
		printf("The Stack is:\n");
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
	else
	{
		printf("The Stack is Empty!\n");
	}
}

int empty(NODE *Head)
{
	return Head == NULL ? 1:0;
}





