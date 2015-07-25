#include <stdio.h>
#include <stdlib.h>

typedef struct NODE	
{ 
	int data;
	struct NODE *next;
}NODE;

NODE *Head = NULL; //Denotes the head of the stack. Keeps on shifting when new element is added.

void push(int val)
{
	NODE *temp;
	temp = (NODE*) malloc(sizeof(NODE));
	temp->data = val;
	if(temp == NULL)
	{
		exit(0);
	}
	if(Head == NULL)
	{
		Head = temp;
		Head->next = NULL;
	}
	else
	{
		temp->next = Head;
		Head = temp;
	}
	printf("%d inserted at the top!\n",val);
}

void pop()
{
	int val;
	if (Head == NULL)
	{
		printf("Stack is empty!\n");
		return;
	}
	else
	{
		val = Head->data;
		printf("%d : Popped\n",val);
		Head = Head->next;
	}
}

void display()
{
	NODE *temp = Head;
	if(temp != NULL)
	{
		printf("The Stack is:");
		while(temp != NULL)
		{	
			printf("%d ",temp->data);
			temp = temp->next;
		}
		printf("\n");	
	}
	else
	{
		printf("Stack is Empty!\n");
	}
}


int main()
{
	push(5);
	push(10);
	pop();
	display();
	push(12);
	display();
	return 0;
}