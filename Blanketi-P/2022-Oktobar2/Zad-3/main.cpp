#include "BSTreeInt.h"

void main()
{
	BSTreeInt stablo;

	stablo.insert(25);
	stablo.insert(17);
	stablo.insert(32);
	stablo.insert(10);
	stablo.insert(19);
	stablo.insert(8);
	stablo.insert(23);
	stablo.insert(3);
	stablo.insert(48);
	stablo.insert(38);
	stablo.insert(55);

	BSTNodeInt* p = stablo.search(3);
	p = stablo.findSibling(p);
	if (p)
		cout << "Siblings: " << p->getKey() << endl;
	else
		cout << "No siblings!" << endl;
}
