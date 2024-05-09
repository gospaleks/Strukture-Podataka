#include "QueueAsArrayInt.h"

#include <exception>
using namespace std;

QueueAsArrayBSTNodeInt::QueueAsArrayBSTNodeInt(long nsize)
{
	size = nsize;
	arr = new BTNodeInt*[size]();
	head = tail = -1;
	numOfElements = 0;
}

BTNodeInt* QueueAsArrayBSTNodeInt::getHead() const
{
	if (numOfElements == 0)
		throw new exception("Queue underflow!");
	return arr[head];
}

void QueueAsArrayBSTNodeInt::enqueue(BTNodeInt* object)
{
	if (numOfElements == size)
		throw new exception("Queue overflow!");
	if (++tail == size) tail = 0;
	arr[tail] = object;
	if (numOfElements == 0) head = tail;
	numOfElements++;
}

BTNodeInt* QueueAsArrayBSTNodeInt::dequeue()
{
	if (numOfElements == 0)
		throw new exception("Queue underflow!");
	BTNodeInt* result = arr[head];
	if (++head == size) head = 0;
	numOfElements--;
	if (numOfElements == 0) head = tail = -1;
	return result;
}

