#pragma once

/*
	Apstraktna klasa Stack
	(obezbedjuje da bilo kako implementiran stek mora da ima ove funkcije)
*/

template <class T>
class Stack
{
public:
	virtual T getTop() = 0;
	virtual void push(T object) = 0;
	virtual T pop() = 0;
	virtual bool isEmpty() = 0;
	virtual long numberOfElements() = 0;
};

