#include "LinkedList.h"

int main() {
	try {

		// Glavna Lista
		LinkedList lista;
		lista.addToHead(15);
		lista.addToHead(1);
		lista.addToHead(9);
		lista.addToHead(8);
		lista.addToHead(11);
		lista.addToHead(25);
		lista.addToHead(9);
		lista.addToHead(8);
		lista.addToHead(97);

		lista.printAll();

		// Podlista
		LinkedList sublist;
		sublist.addToHead(8);
		sublist.addToHead(11);
		sublist.addToHead(25);
		
		sublist.printAll();
		
		// Lista nakon brisanja
		lista.deleteSublist(&sublist);
		lista.printAll();
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}