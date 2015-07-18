#include <iostream>
#include <cstdlib>
#include <cstdio>


using namespace std;

struct DynArrayStack
{
	int top;
	int capacity;
	int *array;
};

typedef struct DynArrayStack dynarraystack;

dynarraystack* CreateStack()
{
	dynarraystack *S = (dynarraystack*)malloc(sizeof(dynarraystack));
	if(!S)
		return NULL;
	S->top = -1;
	S->capacity = 1;
	S->array = (int*)malloc(sizeof(int)*S->capacity);
	if(!S->array)
		return NULL;
	return S;
}

int IsFullStack(dynarraystack *S)
{
	return(S->top == S->capacity-1);
}

int IsEmptyStack(dynarraystack *S)
{
	return (S->top == -1);
}

int CurrentSizeofStack(dynarraystack *S)
{
	return S->top+1;
}

void DoubleStack(dynarraystack *S)
{
	S->capacity*=2;
	S->array = realloc(S->array,S->capacity);
}

void Push(dynarraystack *S, int data)
{
	if(IsFullStack(S))
		DoubleStack(S);
	S->array[++S->top] = data;
}

int Pop(dynarraystack *S)
{
	if(IsEmptyStack(S))
	{
		printf("Underflow\n");
		return -1;
	}
	return S->array[S->top--];
}

void DeleteStack(dynarraystack *S)
{
	if(S)
	{
		if(S->array)
			free(S->array);
		free(S);
	}
}
//test driver program to check functionality.
// int main()
// {
// 	dynarraystack *S = CreateStack();
// 	Push(S,3);	//A pointer to the structure created is passed. This pointer is used to change values of variables
// 	Push(S,5);	// present inside the structure.
// 	Push(S,7);
// 	printf("Current Size of Stack: %d\n",CurrentSizeofStack(S));
// 	printf("%d Popped\n",Pop(S));
// 	printf("%d Popped\n",Pop(S));
// 	printf("%d Popped\n",Pop(S));
// 	printf("%d Popped\n",Pop(S));
// 	return 0;
// }