#pragma once
#include "Stack.h"
#include "LLNode.h"
#include <iostream>

template <class T>
class StackAsList : public Stack<T>
{
private:
	LLNode<T>* top;
	long numOfEl;
public:

	StackAsList() { numOfEl = 0; top = nullptr; }
	~StackAsList() {
		while (!isEmpty())
			pop();
	}

	bool isEmpty() { return top == nullptr; }
	long numberOfElements() { return numOfEl; }

	void push(T object);
	T pop();

	T getTop();
};

template<class T>
inline void StackAsList<T>::push(T object)
{
	top = new LLNode<T>(object, top);
	++numOfEl;
}

template<class T>
inline T StackAsList<T>::pop()
{
	if (isEmpty())
		throw std::exception("StackAsList underflow.");

	LLNode<T>* tmp = top;
	T el = tmp->info;
	top = top->next;
	delete tmp;
	--numOfEl;
	return el;
}	

template<class T>
inline T StackAsList<T>::getTop()
{
	if (isEmpty())
		throw std::exception("StackAsList underflow.");

	return top->info;
}
