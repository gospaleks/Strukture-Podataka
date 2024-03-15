#pragma once
#include "Node.h"
#include <iostream>

class CReorgList
{
private:
	
	Node* head;
	Node* tail;

public:

	CReorgList();
	~CReorgList();

	bool IsEmpty() const ;

	void AddToTail(int key);

	Node* GetToStart(int key);
	Node* GetTransp(int key);

	void Print();
};

