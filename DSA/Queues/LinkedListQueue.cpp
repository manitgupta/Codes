#include <iostream>
#include <cstdlib>
#include <cstdio>

#define _DEBUG

using namespace std;

struct ListNode
{
	int data;
	struct ListNode *next;
};

typedef struct ListNode listnode;

struct Queue
{
	listnode *front;
	listnode *rear;
};

typedef struct Queue queue;

queue* CreateQueue()
{
	queue* Q = (queue*)malloc(sizeof(queue));
	if(!Q)
		return NULL;
	Q->front = Q->rear = NULL;
	return Q;
}

int IsEmptyQueue(queue *Q)
{
	return(Q->front == NULL);
}

void EnQueue(queue *Q, int data)
{
	listnode *newNode = (listnode*)malloc(sizeof(listnode));
	newNode->data = data;
	newNode->next = NULL;
	if(Q->rear)
		Q->rear->next = newNode;
	Q->rear = newNode;
	if(Q->front == NULL)
		Q->front = Q->rear;
	#ifdef _DEBUG
	printf("%d Added\n",Q->rear->data);
	#endif
}

int DeQueue(queue *Q)
{
	int data = 0;
	listnode *temp;
	if(IsEmptyQueue(Q))
	{
		printf("Underflow\n");
		return 0;
	}
	else
	{
		temp = Q->front;
		data = Q->front->data;
		Q->front = Q->front->next;
		free(temp);
	}
	return data;
}

void DeleteQueue(queue *Q)
{
	listnode *temp;
	while(Q->front)
	{
		temp = Q->front;
		Q->front = Q->front->next;
		free(temp);
	}
	free(Q);
}
//driver program to test functions. Use #define _DEBUG to check working.
#ifdef _DEBUG
int main()
{
	queue *Q = CreateQueue();
	EnQueue(Q,6);
	EnQueue(Q,4);
	EnQueue(Q,3);
	printf("%d Deleted\n",DeQueue(Q));
	printf("%d Deleted\n",DeQueue(Q));
	return 0;
}
#endif