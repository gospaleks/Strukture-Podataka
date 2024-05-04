#include "BinaryMinHeapInt.h"

void BinaryMinHeapInt::update(int val, int add)
{

	/*
		Zadatak:

		f-ju koja azurira cvor sa vrednoscu val, dodavanjem vrednosti add.
		Vrednost add moze biti i pozitivna i negativna.
		Nakon promene vrednosti heap mora da zadrzi svoju strukturu.
	*/

	long pos = 1;
	while (pos <= numOfElements && array[pos] != val)
		pos++;

	if (pos > numOfElements) // element nije pronadjen
		return;

	array[pos] += add;		// azuriraj vrednost elementa
	long newVal = array[pos];

	// ako je vrednost smanjena element pomeraj na gore
	if (add < 0)
	{
		while (pos > 1 && array[pos / 2] > newVal) {
			array[pos] = array[pos / 2];
			pos /= 2;
		}
		array[pos] = newVal;
	}
	// inace pomeraj element na dole
	else {
		while (2 * pos < numOfElements + 1)
		{
			// u child zavrsi pozicija manjeg od dva deteta
			long child = 2 * pos;
			if (child + 1 < numOfElements + 1 && array[child + 1] < array[child])
				child += 1;
			
			if (newVal <= array[child])
				break;

			array[pos] = array[child];
			pos = child;
		}
		array[pos] = newVal;
	}
}

// helper funkcija da vidim sta se desava
void BinaryMinHeapInt::printTree()
{
	for (long i = 1; i <= numOfElements; i++)
		cout << array[i] << " ";
	cout << endl;
}

BinaryMinHeapInt::BinaryMinHeapInt(long len)
{
	length = len;
	numOfElements = 0;
	array = new int[length + 1]();
}

int BinaryMinHeapInt::getFirst() const
{
	if (numOfElements == 0)
		throw new exception("The heap is empty!");
	return array[1];
}

void BinaryMinHeapInt::insert(int el)
{
	if (numOfElements == length)
		throw new exception("The heap is full!");
	numOfElements++;
	int pos = numOfElements;
	while (pos > 1 && array[pos / 2] > el)
	{
		array[pos] = array[pos / 2];
		pos /= 2;
	}
	array[pos] = el;
}

int BinaryMinHeapInt::deleteRoot()
{
	if (numOfElements == 0)
		throw new exception("The heap is empty!");
	int result = array[1];
	int last = array[numOfElements];
	numOfElements--;
	long pos = 1;
	while (2 * pos < numOfElements + 1)
	{
		long child = 2 * pos;
		if (child + 1 < numOfElements + 1 && array[child + 1] < array[child])
			child += 1;
		if (last <= array[child])
			break;
		array[pos] = array[child];
		pos = child;
	}
	array[pos] = last;
	return result;
}