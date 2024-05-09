#pragma once

#include "BSTNodeInt.h"

class QueueAsArrayBSTNodeInt
{
protected:
	BSTNodeInt** arr;	// polje elemenata
	long size;			// velidina polja
	long head;			// indeks pocetnog elementa
	long tail;			// indeks krajnjeg elementa
	long numOfElements;	// broj elemenata u redu

public:
	QueueAsArrayBSTNodeInt(long nsize);
	~QueueAsArrayBSTNodeInt() { delete[] arr; }

	bool isEmpty() const { return (numOfElements == 0); }
	long numberOfElements() const { return numOfElements; }

	BSTNodeInt* getHead() const;
	void enqueue(BSTNodeInt* object);
	BSTNodeInt* dequeue();
};
