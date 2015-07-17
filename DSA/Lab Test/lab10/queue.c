#include "queue.h"

queue createQueue()
{
	queue s;
	s.st = createLList();
	return s;
}

bool isEmptyQueue(queue *s)
{
	if(s->st.size == 0)
		return true;
	return false;
}

void pushQueue(vertex e, queue *s)
{
	push_back(e, &s->st);
}

vertex popQueue(queue *s)
{
	vertex v = pop_front(&s->st);
	return v;
}