#include "StackAsArray.h"
#include "StackAsList.h"

#include <iostream>
#include <string.h>

/*
	
	- BigNumbers zadatak
	- Stek implementiran preko polja i preko jednostruke liste

*/


int charToInt(char c) {
	return (c - '0');
}

char* sum(const char* num1, const char* num2) {
	
	StackAsArray<int> stek1(strlen(num1) + 1);
	StackAsArray<int> stek2(strlen(num2) + 1);
	StackAsArray<int> stekRes(strlen(num1) + strlen(num2) + 2);

	// Popuni stek1
	for (int i = 0; i < strlen(num1); ++i)
		stek1.push(charToInt(num1[i]));

	// Popuni stek2
	for (int i = 0; i < strlen(num2); ++i)
		stek2.push(charToInt(num2[i]));
	
	int prenos = 0;
	while (!stek1.isEmpty() && !stek2.isEmpty()) {

		int cifra1 = stek1.pop();
		int cifra2 = stek2.pop();
		int tmpSum = cifra1 + cifra2 + prenos;
	
		stekRes.push(tmpSum % 10);

		prenos = tmpSum / 10;
	}

	while (!stek1.isEmpty()) {
		int cifra1 = stek1.pop();
		int tmpSum = cifra1 + prenos;

		stekRes.push(tmpSum % 10);
		
		prenos = tmpSum / 10;
	}

	while (!stek2.isEmpty()) {
		int cifra2 = stek2.pop();
		int tmpSum = cifra2 + prenos;

		stekRes.push(tmpSum % 10);

		prenos = tmpSum / 10;
	}

	int resN = stekRes.numberOfElements();
	char* res = new char[resN + 1];
	int i;
	for (i = 0; i < resN; ++i) {
		res[i] = '0' + (stekRes.pop());
	}
	res[i] = '\0';

	return res;
}

int main() {
	
	char num1[] = "1965489621896572";
	char num2[] = "15255555555987711412";

	char* result = sum(num1, num2);

	cout << result;

	if (result != nullptr)
		delete[] result;

	return 0;
}