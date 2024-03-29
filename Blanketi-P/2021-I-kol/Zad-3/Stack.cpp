#include"Stack.h"

Stack::Stack(int nsize) 
{
	size = nsize;
	array = new double[size];
	top = -1;
};

bool Stack::isEmpty()
{ 
	return (top == -1); 
};

int Stack::numberOfElements()
{ 
	return (top + 1); 
};

Stack::~Stack()
{ 
	delete[] array; 
};

void Stack::push(double element)
{
	if (top == (size - 1))
		throw new exception("Stack overflow!");
	array[++top] = element;
};

double Stack::pop()
{
	if (top == -1)
		throw new exception("Stack underflow!");
	double result = array[top--];
	return result;
};

double Stack::getTop() 
{
	if (top == -1)
		throw new exception("Stack underflow!");
	return array[top];
};

