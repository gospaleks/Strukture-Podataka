#pragma once
#include <iostream>

class Node
{
public:

	int info;
	Node* next;

	Node() { next = nullptr; info = 0; }

	Node(int _info, Node* _next = nullptr) {
		info = _info;
		next = _next;
	}
	
	~Node() { }

	void print() {
		std::cout << info << " ";
	}

};

