#include "Stack.h"
#include <string.h>

double doOperation(char op, double x, double y) {

	switch (op)
	{
		case '+':
			return (x + y);
		case '-':
			return (x - y);
		case '*':
			return (x * y);
		case '/':
			return (x / y);
		default:
			return 0.0;
	}
}

double calcPrefix(const char* inStr) {

	/*
		nisu obradjeni granicni slucajevi niti greske u izrazu
		jer kaze u zad da podrazumevamo da je sve ok
	*/

	Stack s(strlen(inStr));

	double firstOp = 0.0;
	double secondOp = 0.0;

	// kreni od nazad
	for (int i = strlen(inStr) - 1; i >= 0; --i) {

		// ako je cifra baci na stek
		if (isdigit(inStr[i]))
			s.push((double)(inStr[i] - '0'));

		// ako je operacija uzmi zadnja dva od stek i odradi operaciju
		// a rezultat stavi opet na stek
		else {

			firstOp = s.pop();
			secondOp = s.pop();
	
			firstOp = doOperation(inStr[i], firstOp, secondOp);

			s.push(firstOp);
		}
	}

	return firstOp;
}


void main()
{
	cout << calcPrefix("**+4/35-934"); // pise da treba vrati 92 al to je greska ja msm
}