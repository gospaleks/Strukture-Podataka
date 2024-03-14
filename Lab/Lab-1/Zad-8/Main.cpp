#include "CSparseMatrix.h"

int main() {
	
	try {
		CSparseMatrix<int> m1(5, 4);

		m1.SetAt(0, 0, 5);
		m1.SetAt(1, 1, 3);
		m1.SetAt(2, 0, 12);
		m1.SetAt(3, 1, 14);
		m1.SetAt(2, 2, 1);
		m1.SetAt(2, 3, 2);
		m1.SetAt(3, 3, 3);

		m1.Print();

		std::cout << m1.GetAt(2, 0) << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}