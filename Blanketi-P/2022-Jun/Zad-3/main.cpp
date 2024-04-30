#include "BSTreeInt.h"

/*

		    25
	    /        \
	   12         32
	 /    \      /   \
	6     18    27   48
   /     /  \     \    \ 
  4     17  19    28    49

*/



void main()
{
	BSTreeInt stablo;

	stablo.insert(25);
	stablo.insert(12);
	stablo.insert(32);
	stablo.insert(6);
	stablo.insert(18);
	stablo.insert(27);
	stablo.insert(48);
	stablo.insert(19);
	stablo.insert(17);
	stablo.insert(4);
	stablo.insert(49);
	stablo.insert(28);


	stablo.inorder();
	cout << endl;

	cout << stablo.isPerfect() << endl;
}
