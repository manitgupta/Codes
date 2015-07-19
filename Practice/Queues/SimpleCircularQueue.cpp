#include <iostream>
#include <cstdlib>
#include <cstdio>

#define _DEBUG			//Comment to disable Debugging mode.

using namespace std;

struct ArrayQueue
{
	int front,rear;
	int capacity;
	int *array;
};

typedef struct ArrayQueue arrayqueue;

arrayqueue* CreateQueue(int size)
{
	arrayqueue *Q = (arrayqueue*)malloc(sizeof(arrayqueue));
	if(!Q)
		return NULL;
	Q->capacity = size;
	Q->front = -1;
	Q->rear = -1;
	Q->array = (int*)malloc(sizeof(int)*Q->capacity);
	if(!Q->array)
		return NULL;
	return Q;
}

int IsEmptyQueue(arrayqueue *Q)
{
	return (Q->front == -1);
}

int IsFullQueue(arrayqueue *Q)
{
	return((Q->rear+1)%Q->capacity == Q->front);
}

int QueueSize(arrayqueue *Q)
{
	return (Q->capacity - Q->front + Q->rear +1);
}

void EnQueue(arrayqueue *Q, int data) //Insertions happpen from the end.
{
	if(IsFullQueue(Q))
		printf("Overflow\n");
	else
	{
		Q->rear = (Q->rear+1)%Q->capacity;
		Q->array[Q->rear] = data;
		#ifdef _DEBUG
		printf("%d Added\n",Q->array[Q->rear]);
		#endif
		if(Q->front == -1) //if this is the first element
			Q->front = Q->rear;
	}
}
int DeQueue(arrayqueue *Q) //Deletions happen from the beginning
{
	int data = 0; //Dummy Variable to return value of element DeQueued.
	if(IsEmptyQueue(Q))
	{
		printf("Underflow\n");
		return 0;
	}
	else
	{
		data = Q->array[Q->front];
		if (Q->front == Q->rear)		//case when only one element is present.
			Q->front = Q->rear = -1;
		Q->front = (Q->front+1)%Q->capacity;
	}
	return data;
}
//driver program to test functions. Use #define _DEBUG to check working.
#ifdef _DEBUG
int main()
{
	arrayqueue *Q = CreateQueue(4);
	EnQueue(Q,6);
	EnQueue(Q,4);
	EnQueue(Q,3);
	printf("%d Deleted\n",DeQueue(Q));
	printf("%d Deleted\n",DeQueue(Q));
	return 0;
}
#endif