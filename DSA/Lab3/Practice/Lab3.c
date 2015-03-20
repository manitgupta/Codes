#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


/*
	Author : Manit Gupta
	Program : Lab-3 2015 DSA BITS Pilani
	Insertion Sort on LinkedList with File Handling.
*/

int SIZE =0;

typedef struct NODE
{
	int data;
	struct NODE *next;
	struct NODE *prev;
}NODE;

NODE *Head = NULL;

void push(int val)
{
	NODE *temp;
	temp = (NODE*) malloc(sizeof(NODE));
	if(temp == NULL)
	{
		printf("Overflow!\n");
		exit(0);
	}
	temp->data = val;
	if (Head == NULL) //The first element
	{
		Head = temp;
		Head->next = NULL;
		Head->prev = NULL;
		SIZE++;
	}
	else
	{
		temp->next = Head;
		Head->prev = temp;
		Head = temp;
		Head->prev = NULL;
		SIZE++;
	}
}

void displayOnTerminal()
{
	printf("The Linked List is:\n");
	NODE *temp = Head;
	if(temp!=NULL)
	{
		while(temp!=NULL)
		{	
			printf("%d\n",temp->data);
			temp = temp->next;
		}	
	}
	else
	{
		printf("The Linked List is Empty!\n");
	}	
}

void readData(char filename[])
{
	FILE *fp;
	fp = fopen(filename,"r+");
	while(!feof(fp))
	{
		int num;
		fscanf(fp,"%d",&num);
		push(num);
	}
	displayOnTerminal();
}

void printList(char filename[])
{
	FILE *fp;
	fp = fopen(filename,"w+");
	NODE *temp = Head;
	if(temp != NULL)
	{
		while(temp!=NULL)
		{
			fprintf(fp, "%d\n",temp->data);
			temp = temp->next;
		}
	}
	else
	{
		printf("The Linked List is Empty\n");
	}
}

void insertion_sort()
{
	NODE *tempj = Head->next;
	//printf("%d\n",tempj->data);
	NODE *tempi;
	NODE *temptempi; //There is a lot of scope for error in the end pointers! temptempi is used to keep track of last useful value in case tempi becomes NULL.
	NODE *key = (NODE*) malloc(sizeof(NODE));
	while(tempj!=NULL)
	{
		key->data = tempj->data; 						//	key = data
		tempi = tempj->prev; 							//i = j-1
		while (tempi!= NULL && key->data <= tempi->data)
		{
			tempi->next->data = tempi->data;			//A[i+1] = A[i]
			temptempi = tempi;							//Exclusive to this. Keep track of tempi in case become NULL by tempi = tempi->prev
			tempi = tempi->prev;						// i--
		}
		if(temptempi->prev == NULL)
		{
			temptempi->data = key->data;
		}
		else 											//A[i+1] = key
		{
			tempi->next->data = key->data;
		}
		tempj = tempj->next;						//j++
	}
}

int main()
{
	readData("input.txt");
	printList("output.txt");
	printf("After Sorting:\n");
	insertion_sort();
	//printf("Hello!\n");
	displayOnTerminal();
	return 0;
}