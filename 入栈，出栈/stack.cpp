#include "stack.h"

bool Stack::isempty()
{
	return p==0;
}

bool Stack::isfull()
{
	return p==MAX;
}

void Stack::push(T &a)
{
	stack[p++] = a;
}

void Stack::pop(T &a)
{
	a=stack[--p];
}
