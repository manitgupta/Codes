#ifndef QUEUE_H
#define QUEUE_H

#include "llist.h"

struct _queue
{
	llist st;
};

typedef struct _queue queue;

queue createQueue();
bool isEmptyQueue(queue *s);
void pushQueue(vertex e, queue *s);
vertex popQueue(queue *s);

#endif