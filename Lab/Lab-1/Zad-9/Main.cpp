#include "CReorgList.h"

int main() {

	CReorgList lista;
	lista.AddToTail(1);
	lista.AddToTail(55);
	lista.AddToTail(12);
	lista.AddToTail(2);
	lista.AddToTail(51);
	lista.AddToTail(78);
	lista.AddToTail(11);

	lista.Print();
	
	// Moze i da se prihvati return al oprezno posto moze da bude i nullptr
	// Node* node = lista.GetToStart(2);
	lista.GetToStart(2);

	lista.Print();
	
	lista.GetTransp(51);
	lista.Print();

	return 0;
}