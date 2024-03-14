#pragma once

#include "LLNode.h"
#include <iostream>

class LList
{
private:
	LLNode *head, *tail;

public:

	// Implementirane samo osnovne operacije za rad sa listom

	LList();
	~LList();

	bool isEmpty();

	int deleteFromHead();
	int deleteFromTail();

	void addToHead(int el);
	void addToTail(int el);

	void printAll();

	void swap(LLNode* ptr, LLNode* prev);
	void invertSublist(int data1, int data2);
};

