#include "BTreeInt.h"

#include <exception>
using namespace std;

#include "QueueAsArrayInt.h"
#include "StackAsArrayInt.h"

void BTreeInt::deleteTree(BTNodeInt* ptr)
{
	if (ptr != nullptr) {
		deleteTree(ptr->left);
		deleteTree(ptr->right);
		delete ptr;
	}
}

void BTreeInt::preorder(const BTNodeInt* ptr) const
{
	if (ptr != nullptr) {
		ptr->visit();
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void BTreeInt::inorder(const BTNodeInt* ptr) const
{
	if (ptr != nullptr) {
		inorder(ptr->left);
		ptr->visit();
		inorder(ptr->right);
	}
}

void BTreeInt::postorder(const BTNodeInt* ptr) const
{
	if (ptr != nullptr) {
		postorder(ptr->left);
		postorder(ptr->right);
		ptr->visit();
	}
}

BTNodeInt* BTreeInt::napravi(BinaryMinHeapInt& minHeap, int indeks, BTNodeInt* cvor)
{
	if (indeks > minHeap.getNumOfElements())
		return nullptr;
	cvor = new BTNodeInt(minHeap.getEl(indeks));
	cvor->left = napravi(minHeap, indeks * 2, cvor->left);
	cvor->right = napravi(minHeap, indeks * 2 + 1, cvor->right);
	return cvor;
}

void BTreeInt::iterativePreorder() const
{
	BTNodeInt* ptr = root;
	StackAsArrayBSTNodeInt stack(numOfElements);
	if (ptr != nullptr) {
		stack.push(ptr);
		while (!stack.isEmpty()) {
			ptr = stack.pop();
			ptr->visit();
			if (ptr->right != nullptr)	// levi potomak se stavlja u magacin
				stack.push(ptr->right); // posle desnog, da bi se prvi obradio
			if (ptr->left != nullptr)
				stack.push(ptr->left);
		}
	}
}

void BTreeInt::breadthFirstSearch() const
{
	BTNodeInt* ptr = root;
	QueueAsArrayBSTNodeInt queue(numOfElements);
	if (ptr != nullptr) {
		queue.enqueue(ptr);
		while (!queue.isEmpty()) {
			ptr = queue.dequeue();
			ptr->visit();
			if (ptr->left != nullptr)
				queue.enqueue(ptr->left);
			if (ptr->right != nullptr)
				queue.enqueue(ptr->right);
		}
	}
}
//TODO: Realizovati rekurzivni metod koji kreira dinamičku memorijsku reprezentaciju binarnog stabla na osnovu sadržaja gomile (voditi računa o efikasnosti ovog metoda). 
//TODO: Rekurzivni metod sa potrebnim parametrima je neophodno dodati u klasu binarnog stabla. 
void BTreeInt::createFromMinHeap(BinaryMinHeapInt& minHeap)
{
	root = napravi(minHeap, 1, root);
}
