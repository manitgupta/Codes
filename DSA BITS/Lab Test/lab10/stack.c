#include "stack.h"

stack createStack()
{
	stack s;
	s.st = createLList();
	return s;
}

bool isEmptyStack(stack *s)
{
	if(s->st.size == 0)
		return true;
	return false;
}

void pushStack(vertex e, stack *s)
{
	push_front(e, &s->st);
}

vertex popStack(stack *s)
{
	vertex v = pop_front(&s->st);
	return v;
}