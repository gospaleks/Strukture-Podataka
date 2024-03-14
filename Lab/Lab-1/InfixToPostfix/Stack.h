#pragma once
#include <iostream>

template <class T>
class Stack
{
private:
	T* array;
	int size;
	int top;

public:
	Stack(long _size);
	~Stack();

	bool isEmpty();
	int numberOfElements();

	T getTop();

	void push(T object);
	T pop();
};

template<class T>
inline Stack<T>::Stack(long _size)
{
	size = _size;
	array = new T[size];
	top = -1;
}

template<class T>
inline Stack<T>::~Stack()
{
	if (array != nullptr)
		delete[] array;
}

template<class T>
inline bool Stack<T>::isEmpty()
{
	return (top == -1);
}

template<class T>
inline int Stack<T>::numberOfElements()
{
	return (top + 1);
}

template<class T>
inline T Stack<T>::getTop()
{
	if (isEmpty())
		throw std::exception("Stack underflow.");
	return array[top];
}

template<class T>
inline void Stack<T>::push(T object)
{
	if (top == (size - 1))
		throw std::exception("Stack overflow.");
	array[++top] = object;
}

template<class T>
inline T Stack<T>::pop()
{
	if (isEmpty())
		throw std::exception("Stack underflow.");
	T elForDel = array[top--];
	return elForDel;
}
