#include "QueueAsArrayInt.h"

#include <exception>
using namespace std;

QueueAsArrayLinkedNodeInt::QueueAsArrayLinkedNodeInt(long nsize)
{
	size = nsize;
	arr = new LinkedNodeInt*[size]();
	head = tail = -1;
	numOfElements = 0;
}

LinkedNodeInt* QueueAsArrayLinkedNodeInt::getHead() const
{
	if (numOfElements == 0)
		throw new exception("Queue underflow!");
	return arr[head];
}

void QueueAsArrayLinkedNodeInt::enqueue(LinkedNodeInt* object)
{
	if (numOfElements == size)
		throw new exception("Queue overflow!");
	if (++tail == size) tail = 0;
	arr[tail] = object;
	if (numOfElements == 0) head = tail;
	numOfElements++;
}

LinkedNodeInt* QueueAsArrayLinkedNodeInt::dequeue()
{
	if (numOfElements == 0)
		throw new exception("Queue underflow!");
	LinkedNodeInt* result = arr[head];
	if (++head == size) head = 0;
	numOfElements--;
	if (numOfElements == 0) head = tail = -1;
	return result;
}

