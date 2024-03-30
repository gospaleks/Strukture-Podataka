#pragma once

class Elem
{
public:
	int key;
	Elem* prev;
	Elem* next;

	Elem(int _key, Elem* _prev = nullptr, Elem* _next = nullptr) {
		key = _key;
		prev = _prev;
		next = _next;
	}

	~Elem() { }
};

