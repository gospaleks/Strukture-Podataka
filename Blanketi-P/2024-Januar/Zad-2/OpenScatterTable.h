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
	bool signup(int playerNumber, const char* name, const char* lastName, const char* yearBorn, int jerseyNumber);
	int countPlayersBornIn(const char* yearBorn);
	void print();
};

