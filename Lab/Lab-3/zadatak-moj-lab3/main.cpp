#include "BSTreeInt.h"

void main()
{
	//TODO: Proveriti rad implementiranog metoda za različite slučajeve izvršenja
	BSTreeInt stablo;

	stablo.insert(25);
	stablo.insert(18);
	stablo.insert(12);
	stablo.insert(10);
	stablo.insert(8);
	stablo.insert(7);
	//stablo.insert(21);
	//stablo.insert(19);


	stablo.insert(32);
	stablo.insert(50);
	stablo.insert(38);



	stablo.preorder();
	cout << endl;

	stablo.updateAllSpecificPairs();

	stablo.preorder();
	cout << endl;
}
