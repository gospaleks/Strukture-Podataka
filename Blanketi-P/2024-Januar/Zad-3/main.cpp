#include "BSTreeInt.h"

void main()
{
	BSTreeInt stablo;

	stablo.insert(26);
	stablo.insert(21);
	stablo.insert(17);
	stablo.insert(22);
	stablo.insert(24);
	stablo.insert(23);
	stablo.insert(25);

	stablo.insert(32);
	stablo.insert(48);
	stablo.insert(58);
	stablo.insert(35);
	stablo.insert(49);
	stablo.insert(59);

	stablo.inorder();
	cout << endl;

	cout << stablo.countCloseParents(5);
}
