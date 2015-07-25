#ifndef STACK_H
#define STACK_H

#include "llist.h"

struct _stack
{
	llist st;
};

typedef struct _stack stack;

stack createStack();
bool isEmptyStack(stack *s);
void pushStack(vertex e, stack *s);
vertex popStack(stack *s);

#endif
