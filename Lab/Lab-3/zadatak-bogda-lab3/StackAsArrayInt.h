#pragma once

#include "BTNodeInt.h"

class StackAsArrayBSTNodeInt
{
protected:
	BTNodeInt** arr; 	// polje elemenata
	long size;	// velicina polja
	long top;	// indeks vrsnog elementa

public:
	StackAsArrayBSTNodeInt(long nsize);
	~StackAsArrayBSTNodeInt() { delete[] arr; };

	bool isEmpty() const { return (top == -1); };
	long numberOfElements() const { return (top + 1); };

	BTNodeInt* getTop() const;
	void push(BTNodeInt* object);
	BTNodeInt* pop();
};


