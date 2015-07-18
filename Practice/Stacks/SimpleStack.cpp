#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct ArrayStack
{
	int top;
	int capacity;
	int *array;		//simple array which stores the stack.
};

typedef struct ArrayStack arraystack;

arraystack* CreateStack()
{
	arraystack *S = (arraystack*)malloc(sizeof(arraystack));
	if (!S)
		return NULL;
	S->capacity = 10;
	S->top = -1;
	S->array = (int*)malloc(S->capacity*sizeof(int));
	if(!S->array)	//check if array was allocated memory.
	{
		return NULL;
	}
	return S;
}

int IsEmptyStack(arraystack *S)
{
	return(S->top == -1);
}

int IsFullStack(arraystack *S)
{
	return(S->top == S->capacity -1);
}

void Push(arraystack *S, int data)
{
	if(IsFullStack(S))
	{
		printf("Stack Overflow\n");
		return;
	}
	else
		S->array[++S->top] = data;
}

