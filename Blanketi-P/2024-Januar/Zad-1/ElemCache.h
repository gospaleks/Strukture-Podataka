#pragma once
#include "Elem.h"
#include <iostream>

class ElemCache
{
private:
	Elem* head;
	Elem* tail;
	int maxCnt;
	int top;

public:
	ElemCache(int _maxCnt);
	~ElemCache();

	bool isEmpty() const;

	void add(Elem* elem);
	Elem* get(int key);

	int deleteFromTail();
	void printAll();
};

