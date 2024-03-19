#pragma once
#include <exception>

template <class T>
class Stack
{
private:
	T* array;
	int n;
	int top;

public:
	Stack();
	Stack(int n);
	~Stack();

	void push(T el);
	T pop();
	T getTop();
	bool empty();
};

template<class T>
inline Stack<T>::Stack()
{
	array = nullptr;
	n = top = -1;
}

template<class T>
inline Stack<T>::Stack(int n)
{
	this->n = n;
	top = -1;
	array = new T[n];
}

template<class T>
inline Stack<T>::~Stack()
{
	if (array != nullptr)
		delete[] array;
}

template<class T>
inline void Stack<T>::push(T el)
{
	if (top == (n - 1))
		throw std::exception("Stack overflow.");

	array[++top] = el;
}

template<class T>
inline T Stack<T>::pop()
{
	if (empty())
		throw std::exception("Stack underflow.");

	return array[top--];
}

template<class T>
inline T Stack<T>::getTop()
{
	if (empty())
		throw std::exception("Stack is empty. Can't get top element.");

	return array[top];
}

template<class T>
inline bool Stack<T>::empty()
{
	return (top == -1);
}
