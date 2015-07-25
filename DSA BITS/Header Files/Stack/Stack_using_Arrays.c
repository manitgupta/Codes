#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
	int capacity;
	int size;
	int *elements;
}STACK;


STACK* createStack(int maxElements)
{
	STACK *S;
	S = (STACK*) malloc(sizeof(STACK));
	S->elements = (int*) malloc(sizeof(int)*maxElements);
	S->size = 0;
	S->capacity = maxElements;
	return S;
}

void pop(STACK *S)
{
	if(S->size == 0)
	{
		printf("Stack is Empty!\n");
		return;
	}
	else
	{
		//free(S->elements[S->size--]);
		S->size--;
	}
}

void push(STACK *S,int ele)
{
	if(S->size == S->capacity)
	{
		printf("Stack is Full!\n");
		return;
	}
	else
	{
		S->elements[S->size++] = ele;
	}
}

int top(STACK *S)
{
	if(S->size == 0)
	{
		printf("Stack is Empty\n");
		return;
	}
	else
	{
		return S->elements[S->size-1];
	}
}

void printStack(STACK *S)
{
	printf("The Stack is:\n");
	int i;
	for (i = 0; i < S->size; ++i)
	{
		printf("%d\n",S->elements[i]);
	}
}

int main()
{
	STACK *S;
	S = createStack(5);
 	push(S,7);
    push(S,5);
    push(S,21);
    push(S,-1);
   
    printStack(S);
    pop(S);
    pop(S);
    printStack(S);
    return 0;
}