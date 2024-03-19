#include "Stack.h"
#include <iostream>
#include <string.h>

const enum TipZagrade {
	MALA,
	SREDNJA,
	VELIKA,
	NISTA
};

TipZagrade getTip(char c) {
	if (c == '{' || c == '}')
		return TipZagrade::VELIKA;
	else if (c == '[' || c == ']')
		return TipZagrade::SREDNJA;
	else if (c == '(' || c == ')')
		return TipZagrade::MALA;
	else
		return TipZagrade::NISTA;
}

bool isCorrect(const char* inStr) {

	Stack<char> stek(strlen(inStr) + 1);

	int i = 0;
	while (inStr[i] != '\0')
	{
		char c = inStr[i];

		// Ako je otvorena zagrada samo stavi na stek
		if (c == '{' || c == '[' || c == '(')
			stek.push(c);

		// Ako je zatvorena proveri dal je prethodna otvorena
		// istog tipa - ako jeste skloni sa steka jer to znaci da su uparene
		else if (c == '}' || c == ']' || c == ')') {
			// poseban slucaj ako pre bilo koje otvorene dodje zatvorena
			if (stek.empty())
				return false;
			if (getTip(stek.getTop()) == getTip(c))
				stek.pop();
		}

		++i;
	}

	return stek.empty();
}

int main() {
	
	try {

		char s[] = "{(a+b)*[(c-d)]}";
		// char s[] = "{[a+b]*(c-d})";
		
		if (isCorrect(s))
			std::cout << "Ispravan.\n";
		else
			std::cout << "Neispravan.\n";

	}
	catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}


	return 0;
}