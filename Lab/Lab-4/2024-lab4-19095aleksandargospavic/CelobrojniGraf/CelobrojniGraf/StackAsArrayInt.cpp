#include "StackAsArrayInt.h"

#include <exception>
using namespace std;

StackAsArrayLinkedNodeInt::StackAsArrayLinkedNodeInt(long nsize)
{
	size = nsize;
	arr = new LinkedNodeInt*[size]();
	top = -1;
}

LinkedNodeInt* StackAsArrayLinkedNodeInt::getTop() const
{
	if (top == -1)
		throw new exception("Stack underflow!");
	return arr[top];
}

void StackAsArrayLinkedNodeInt::push(LinkedNodeInt* object)
{
	if (top == (size - 1))
		throw new exception("Stack overflow!");
	arr[++top] = object;
}

LinkedNodeInt* StackAsArrayLinkedNodeInt::pop()
{
	if (top == -1)
		throw new exception("Stack underflow!");
	return arr[top--];
}
