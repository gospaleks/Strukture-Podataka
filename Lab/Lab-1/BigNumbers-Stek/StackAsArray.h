#pragma once
#include "Stack.h"

#include <iostream>

using std::cout;
using std::endl;

template <class T>
class StackAsArray : public Stack<T>
{
private:
	T* array;
	long _size;
	long top;

public:
	StackAsArray(long ssize) {
		_size = ssize;
		array = new T[_size];
		top = -1;
	}

	~StackAsArray() {
		if (array != nullptr)
			delete[] array;
	}

	bool isEmpty() { return (top == -1); }

	long numberOfElements() { return (top + 1); }

	void push(T object) {
		if (top + 1 == (_size - 1))
			throw std::exception("Stack overflow.");

		array[++top] = object;
	}

	T pop() {
		if (isEmpty())
			throw std::exception("Stack underflow.");

		T result = array[top--];
		return result;
	}

	T getTop() {
		if (isEmpty())
			throw std::exception("Stack underflow.");
		return array[top];
	}
};

