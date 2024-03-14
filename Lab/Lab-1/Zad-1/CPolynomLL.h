#pragma once
#include "Node.h"

class CPolynomLL
{
private:
	Node* head;

public:
	CPolynomLL();
	~CPolynomLL();

	bool Empty();
	Node* GetHead();
	void DeleteFromHead();

	void Coef(int exp, double coef);
	static CPolynomLL* Add(const CPolynomLL& poly1, const CPolynomLL& poly2);
	void Print();
};

