#pragma once

class Node
{
public:
	int key;
	Node* next;

	Node() {
		key = 0;
		next = nullptr;
	}

	Node(int _key, Node* _next = nullptr) {
		key = _key;
		next = _next;
	}

	~Node() { }
};

