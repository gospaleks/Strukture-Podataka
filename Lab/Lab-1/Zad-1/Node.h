#pragma once
#include <iostream>
#include <iomanip>

class Node
{
public:

	int exp;
	double coef;
	Node* next;

	Node(int _exp, double _coef, Node* _next = nullptr) {
		exp = _exp;
		coef = _coef;
		next = _next;
	}
	~Node() { }

	void Print() {
		std::cout << std::showpos << coef << "x^" << std::noshowpos << exp << " ";
	}
};

