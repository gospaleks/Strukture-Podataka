#pragma once
#include <iostream>
using namespace std;

class Stack
{
protected:
	double* array; 	// polje elemenata
	int size;	// veličina polja
	int top;	// indeks vršnog elementa
public:
	Stack(int nsize);
	bool isEmpty();
	int numberOfElements();
	~Stack();
	void push(double element); 
	double pop(); 
	double getTop();
};