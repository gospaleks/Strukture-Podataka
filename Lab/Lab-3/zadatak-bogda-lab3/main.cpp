#include "BinaryMinHeapInt.h"
#include "BTreeInt.h"
#include <iostream>
using namespace std;

void main()
{
	BinaryMinHeapInt* b = new BinaryMinHeapInt(10);
	b->insert(8);
	b->insert(10);
	b->insert(7);
	b->insert(3);
	b->insert(12);
	b->insert(66);
	b->insert(15);
	b->insert(99);
	b->stampaj();

	cout << endl;

	BTreeInt* stablo = new BTreeInt();
	stablo->createFromMinHeap(*b);
	stablo->inorder();

	delete stablo;
	delete b;
}
