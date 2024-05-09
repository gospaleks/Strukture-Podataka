#include "StackAsArrayInt.h"

#include <exception>
using namespace std;

StackAsArrayBSTNodeInt::StackAsArrayBSTNodeInt(long nsize)
{
	size = nsize;
	arr = new BTNodeInt*[size]();
	top = -1;
}

BTNodeInt* StackAsArrayBSTNodeInt::getTop() const
{
	if (top == -1)
		throw new exception("Stack underflow!");
	return arr[top];
}

void StackAsArrayBSTNodeInt::push(BTNodeInt* object)
{
	if (top == (size - 1))
		throw new exception("Stack overflow!");
	arr[++top] = object;
}

BTNodeInt* StackAsArrayBSTNodeInt::pop()
{
	if (top == -1)
		throw new exception("Stack underflow!");
	return arr[top--];
}
