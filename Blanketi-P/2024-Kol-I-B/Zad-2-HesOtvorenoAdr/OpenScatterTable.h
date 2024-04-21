#pragma once
#include "HashTable.h"
#include "ScatterObject.h"
class OpenScatterTable :
	public HashTable
{
protected:
	ScatterObject* array;
public:
	OpenScatterTable(unsigned int length);
	~OpenScatterTable();
	unsigned int c(unsigned int i);
	void insert(ScatterObject obj);
	bool swapWithPrevious(char* key);
	void print();
};

