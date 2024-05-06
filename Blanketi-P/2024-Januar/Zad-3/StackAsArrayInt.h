#pragma once

#include "BSTNodeInt.h"

class StackAsArrayBSTNodeInt
{
protected:
	BSTNodeInt** arr; 	// polje elemenata
	long size;	// velicina polja
	long top;	// indeks vrsnog elementa

public:
	StackAsArrayBSTNodeInt(long nsize);
	~StackAsArrayBSTNodeInt() { delete[] arr; };

	bool isEmpty() const { return (top == -1); };
	long numberOfElements() const { return (top + 1); };

	BSTNodeInt* getTop() const;
	void push(BSTNodeInt* object);
	BSTNodeInt* pop();
};


