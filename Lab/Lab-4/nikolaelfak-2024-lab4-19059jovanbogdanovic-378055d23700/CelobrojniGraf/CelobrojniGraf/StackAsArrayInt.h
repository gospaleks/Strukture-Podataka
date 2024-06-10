#pragma once

#include "LinkedNodeInt.h"

class StackAsArrayLinkedNodeInt
{
protected:
	LinkedNodeInt** arr; 	// polje elemenata
	long size;	// velicina polja
	long top;	// indeks vrsnog elementa

public:
	StackAsArrayLinkedNodeInt(long nsize);
	~StackAsArrayLinkedNodeInt() { delete[] arr; };

	bool isEmpty() const { return (top == -1); };
	long numberOfElements() const { return (top + 1); };

	LinkedNodeInt* getTop() const;
	void push(LinkedNodeInt* object);
	LinkedNodeInt* pop();
};


