#include <iostream>
#include <cstdlib>
#include <cstdio>

#define _DEBUG

using namespace std;

struct DynArrayQueue
{
	int front,rear;
	int capacity;
	int *array;
};

typedef struct DynArrayQueue dynarrayqueue;

dynarrayqueue* CreateQueue()
{
	dynarrayqueue *Q = (dynarrayqueue*)malloc(sizeof(dynarrayqueue));
	if(!Q)
		return NULL;
	Q->front = Q->rear = -1;
	Q->capacity = 1;
	Q->array =(int*)malloc(sizeof(int)*Q->capacity);
	if(!Q->array)
		return NULL;
	return Q;
}

int IsEmptyQueue(dynarrayqueue *Q)
{
	return(Q->front == -1);
}

int IsFullQueue(dynarrayqueue *Q)
{
	return ((Q->rear+1)%Q->capacity == Q->front);
}


void ResizeQueue(dynarrayqueue *Q) //Dynamic Circular Queue, when full double the size and reallocate.
{
	int size = Q->capacity;
	Q->capacity *= 2;
	Q->array = (int*)realloc(Q->array,Q->capacity);
	if(!Q->array)
	{
		printf("Memory Error\n");
		return;
	}
	if (Q->front > Q->rear)
	{
		for (int i = 0; i < Q->front; ++i)
			Q->array[i+size] = Q->array[i];
		Q->rear = Q->rear + size;
	}
}



void EnQueue(dynarrayqueue *Q, int data)
{
	if(IsFullQueue(Q))
		ResizeQueue(Q);
	Q->rear = (Q->rear+1)%Q->capacity;
	Q->array[Q->rear] = data;
	if (Q->front == -1)		//first element case.
		{
			Q->front = Q->rear;
			#ifdef _DEBUG
			printf("%d\n",Q->front);
			#endif
		}
	#ifdef _DEBUG
	printf("%d Added\n",Q->array[Q->rear]);
	#endif
}

int DeQueue(dynarrayqueue *Q)
{
	int data = 0;
	if(IsEmptyQueue(Q))
	{
		printf("Underflow\n");
		return -1;
	}	
	else
	{
		data = Q->array[Q->front];
		if(Q->front == Q->rear)	
			Q->front = Q->rear = -1;
		else
			Q->front = (Q->front+1)%Q->capacity;
	}
	return data;
}

void DeleteQueue(dynarrayqueue *Q)
{
	if(Q)
	{
		if(Q->array)
			free(Q->array);
		free(Q);
	}
}
//driver program to test functions. Use #define _DEBUG to check working.
#ifdef _DEBUG
int main()
{
	dynarrayqueue *Q = CreateQueue();
	EnQueue(Q,6);
	EnQueue(Q,4);
	EnQueue(Q,3);
	printf("%d Deleted\n",DeQueue(Q));
	printf("%d Deleted\n",DeQueue(Q));
	return 0;
}
#endif