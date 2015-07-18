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

void InsertinLinkedList(listnode **head, int data)		//Inserting at beginning. Function expects the address of the head pointer, hence parameter must be pointer to
{														// a pointer.
	listnode *newNode = (listnode*)malloc(sizeof(listnode));
	newNode->data = data;
	//printf("%d\n",newNode->data);
	newNode->next = *head;
	*head = newNode;
}

int main()
{

	listnode *head = NULL;
	InsertinLinkedList(&head,5); //address of the head pointer is passed, this is call by reference.
	InsertinLinkedList(&head,8);
	InsertinLinkedList(&head,10);
	InsertinLinkedList(&head,15);
	printLinkedList(head);
	head = RecurseReverse(head);
	printLinkedList(head);
	return 0;
}

//Theory :
//When we use "pass by pointer" to pass a pointer to a function, only a copy of the pointer is passed to the function. 
// We can say "pass by pointer" is passing a pointer by value. In most cases, this does not present a problem. 
// But problem comes when you modify the pointer inside the function. Instead of modifying the variable, 
// you are only modifying a copy of the pointer and the original pointer remains unmodified, that is, it still points to the old 
// variable.