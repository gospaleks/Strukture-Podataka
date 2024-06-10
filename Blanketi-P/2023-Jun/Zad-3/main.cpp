#include "BSTreeInt.h"

void main()
{
	BSTreeInt stablo;

	stablo.insert(25);
	stablo.insert(17);
	stablo.insert(13);
	stablo.insert(23);
	stablo.insert(32);
	stablo.insert(29);
	stablo.insert(48);
	stablo.insert(53);
	stablo.insert(59);
	stablo.insert(56);

	stablo.insert(11);
	stablo.insert(12);
	stablo.insert(10);
	stablo.insert(9);
	stablo.insert(55);

	
	cout << stablo.maxHeightDiff()->getKey() << endl;
}
