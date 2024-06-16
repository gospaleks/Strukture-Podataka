#include "BSTreeInt.h"

void main()
{
	BSTreeInt stablo;

	stablo.insert(25);
	stablo.insert(12);
	stablo.insert(32);
	stablo.insert(18);
	stablo.insert(6);
	stablo.insert(3);
	stablo.insert(7);
	stablo.insert(8);
	stablo.insert(27);
	stablo.insert(48);
	stablo.insert(36);
	stablo.insert(58);
	stablo.insert(26);
	stablo.insert(19);
	stablo.insert(125);
	stablo.insert(51);

	BSTNodeInt* maxDiffNode = stablo.getMaxDifferenceNode();
	cout << "Cvor sa najvecom razlikom izmedju sume parnih i neparnih cvorova:\n";
	cout << maxDiffNode->getKey();
}
