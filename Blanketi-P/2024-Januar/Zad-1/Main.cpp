#include "ElemCache.h"

int main() {

	try {
		
		ElemCache kes(5);

		kes.add(new Elem(1));
		kes.add(new Elem(7));
		kes.add(new Elem(5));
		kes.add(new Elem(2));
		kes.add(new Elem(22));
		kes.add(new Elem(11));
		kes.add(new Elem(43));


		kes.printAll();
		kes.get(22);
		kes.printAll();
		kes.get(5);
		kes.printAll();

	}
	catch (std::exception& e) {
		std::cout << e.what() << '\n';
	}

	return 0;
}