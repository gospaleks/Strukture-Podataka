#include "BSTreeInt.h"

void main()
{
	BSTreeInt stablo;

	stablo.insert(16);
    stablo.insert(12);
    stablo.insert(20);
    stablo.insert(7);
    stablo.insert(13);
    stablo.insert(6);
    stablo.insert(9);
    stablo.insert(22);
    stablo.insert(21);
    stablo.insert(28);
    stablo.insert(29);

	cout << stablo.countNodesInRange(10, 22);
}
