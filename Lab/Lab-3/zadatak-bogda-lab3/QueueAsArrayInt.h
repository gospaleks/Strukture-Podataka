#pragma once

#include "BTNodeInt.h"

class QueueAsArrayBSTNodeInt
{
protected:
	BTNodeInt** arr;	// polje elemenata
	long size;			// velidina polja
	long head;			// indeks pocetnog elementa
	long tail;			// indeks krajnjeg elementa
	long numOfElements;	// broj elemenata u redu

public:
	QueueAsArrayBSTNodeInt(long nsize);
	~QueueAsArrayBSTNodeInt() { delete[] arr; }

	bool isEmpty() const { return (numOfElements == 0); }
	long numberOfElements() const { return numOfElements; }

	BTNodeInt* getHead() const;
	void enqueue(BTNodeInt* object);
	BTNodeInt* dequeue();
};
