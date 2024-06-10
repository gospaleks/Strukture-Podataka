#include "BSTreeInt.h"

void main()
{
	BSTreeInt stablo;

	stablo.insert(25);
	stablo.insert(32);
	stablo.insert(17);
	stablo.insert(12);
	stablo.insert(6);
	stablo.insert(23);
	stablo.insert(19);
	stablo.insert(18);
	stablo.insert(20);
	stablo.insert(30);

	stablo.inorder();

	cout << endl;

	cout << stablo.countSmaller(5) << endl;
}
