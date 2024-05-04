#pragma once
#include <iostream>
#include <exception>
using namespace std;

class BinaryMinHeapInt
{
private:
	int* array;
	long length;
	long numOfElements;

public:
	BinaryMinHeapInt(long len);
	~BinaryMinHeapInt() { delete[] array; };

	bool isEmpty() const { return numOfElements == 0; };
	int getFirst() const;

	void insert(int el);
	int deleteRoot();

	// Dodate f-je
	void update(int val, int add);
	void printTree();
};
