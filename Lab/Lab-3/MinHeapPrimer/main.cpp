#include "BinaryMinHeapInt.h"

void main()
{
	BinaryMinHeapInt heap(10);
	heap.insert(5);
	heap.insert(9);
	heap.insert(23);
	heap.insert(21);
	heap.insert(32);
	heap.insert(45);
	heap.insert(2);
	heap.insert(8);
	heap.insert(22);
	heap.insert(11);
	
	heap.printTree();

	heap.update(8, 2);
	heap.printTree();

	heap.update(10, -7);
	heap.printTree();
}
