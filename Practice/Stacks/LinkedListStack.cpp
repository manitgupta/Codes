#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct ListNode
{
	int data;
	struct ListNode *next;
};

typedef struct ListNode stack;

stack* CreateStack()
{
	return NULL;
}

void Push(stack **top, int data) //Pushing in a Stack for a Linked List is adding at the beginning.
{
	stack *newNode = (stack*)malloc(sizeof(stack));
	newNode->data = data;
	newNode->next = *top;
	*top = newNode;
	printf("%d Pushed\n",newNode->data);
}

int IsEmptyStack(stack *top) 
{
	return (top == NULL);
}

int Pop(stack **top)	//parameter is a pointer to a pointer
{
	stack *temp = *top;	//*top is the value/address of pointer.
	if(IsEmptyStack(*top))
		return -1;
	*top = (*top)->next;
	return temp->data;
}
//Test Driver Program to check functionality. 
// int main()
// {
// 	stack *top = CreateStack();
// 	Push(&top,3);	//A pointer to the structure created is passed. This pointer is used to change values of variables
// 	Push(&top,5);	// present inside the structure.stat
// 	Push(&top,7);
// 	printf("%d Popped\n",Pop(&top));
// 	printf("%d Popped\n",Pop(&top));
// 	printf("%d Popped\n",Pop(&top));
// 	printf("%d Popped\n",Pop(&top));
// 	return 0;
// }