#include "StackAsArrayInt.h"

#include <exception>
using namespace std;

StackAsArrayBSTNodeInt::StackAsArrayBSTNodeInt(long nsize)
{
	size = nsize;
	arr = new BSTNodeInt*[size]();
	top = -1;
}

BSTNodeInt* StackAsArrayBSTNodeInt::getTop() const
{
	if (top == -1)
		throw new exception("Stack underflow!");
	return arr[top];
}

void StackAsArrayBSTNodeInt::push(BSTNodeInt* object)
{
	if (top == (size - 1))
		throw new exception("Stack overflow!");
	arr[++top] = object;
}

BSTNodeInt* StackAsArrayBSTNodeInt::pop()
{
	if (top == -1)
		throw new exception("Stack underflow!");
	return arr[top--];
}
