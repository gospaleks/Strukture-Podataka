#include "Stack.h"
#include <iostream>
#include <string.h>

int prioritet(char c) {
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}


char* infixToPostfix(const char* infix) {

	char* postfix = new char[strlen(infix)];
	Stack<char> stek(strlen(infix) + 1);

	int i = 0;
	int iPost = 0;
	while (infix[i] != '\0') {

		if (infix[i] == '(')
			stek.push(infix[i]);

		else if (infix[i] >= 'a' && infix[i] <= 'z')
			postfix[iPost++] = infix[i];

		else if (infix[i] == ')') {
			// skloni sve sa steka dok nije prazan ili dok nije '('
			while (!stek.isEmpty() && stek.getTop() != '(')
				postfix[iPost++] = stek.pop();
		}

		else {
			if (stek.isEmpty() || stek.getTop() == '(')
				stek.push(infix[i]);

			else {
				char op = infix[i];

				// ako je istog ili manjeg prioriteta obrisi sve 
				while (!stek.isEmpty() && stek.getTop() != '(' && prioritet(op) <= prioritet(stek.getTop()))
					postfix[iPost++] = stek.pop();

				stek.push(op);
			}
		}

		++i;
	}

	while (!stek.isEmpty() && stek.getTop() != '(')
		postfix[iPost++] = stek.pop();

	postfix[iPost] = '\0';

	return postfix;
}

int main() {

	const char infix[] = "((a+b)*c/d+e^f)/g";
	char* postfix = infixToPostfix(infix);

	std::cout << infix << std::endl;
	std::cout << postfix << std::endl;

	delete postfix;

	return 0;
}