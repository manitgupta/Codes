#include <iostream>
#include <cstdio>
#include <cstdlib>

#define _DEBUG			//Comment to disable Debugging mode.

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
	arraystack *S = (arraystack*)malloc(sizeof(arraystack));		//S denotes the stack which is created. *array is the Array that will be used to implement Stack.
	if (!S)															// top is a property of the stack, it is also used for increasing index of array. 
		return NULL;												//Array Index = top + 1
	S->capacity = 10;
	S->top = -1;
	S->array = (int*)malloc(S->capacity*sizeof(int));
	if(!S->array)	//check if array was allocated memory.
	{
		return NULL;
	}
	return S;
}

int CurrentSizeofStack(arraystack *S)
{
	return S->top+1;
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
		{
			S->array[++S->top] = data;
			printf("%d\n",S->array[S->top]);
		}
}

int Pop(arraystack *S)
{
	if(IsEmptyStack(S))
	{
		printf("Underflow\n");
		return -1;
	}
	else
		return (S->array[S->top--]);
}

void DeleteStack(arraystack *S)
{
	if(S)
	{
		if(S->array)
			free(S->array);
		free(S);
	}
}
//driver to test. Comment if file is to be included.
#ifdef _DEBUG
int main()
{
	arraystack *S = CreateStack();
	Push(S,3);
	Push(S,5);
	Push(S,7);
	printf("Current Size of Stack: %d\n",CurrentSizeofStack(S));
	printf("%d Popped\n",Pop(S));
	printf("%d Popped\n",Pop(S));
	printf("%d Popped\n",Pop(S));
	printf("%d Popped\n",Pop(S));
	return 0;
}
#endif