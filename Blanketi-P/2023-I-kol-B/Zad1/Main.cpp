#include "LList.h"

int main() {

	try {
		LList lista;

		for (int i = 1; i <= 9; ++i)
			lista.addToTail(i);
		lista.addToTail(0);

		lista.printAll();

		lista.invertSublist(4, 8);
		lista.printAll();

	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}


	return 0;
}