#pragma once

#include "LinkedNodeInt.h"

class QueueAsArrayLinkedNodeInt
{
protected:
	LinkedNodeInt** arr;	// polje elemenata
	long size;			// velidina polja
	long head;			// indeks pocetnog elementa
	long tail;			// indeks krajnjeg elementa
	long numOfElements;	// broj elemenata u redu

public:
	QueueAsArrayLinkedNodeInt(long nsize);
	~QueueAsArrayLinkedNodeInt() { delete[] arr; }

	bool isEmpty() const { return (numOfElements == 0); }
	long numberOfElements() const { return numOfElements; }

	LinkedNodeInt* getHead() const;
	void enqueue(LinkedNodeInt* object);
	LinkedNodeInt* dequeue();
};
