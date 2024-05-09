#pragma once

#include "BTNodeInt.h"
#include "BinaryMinHeapInt.h"

class BTreeInt
{
protected:
	BTNodeInt* root;
	long numOfElements;

	void deleteTree(BTNodeInt* ptr);

	void inorder(const BTNodeInt* ptr) const;
	void preorder(const BTNodeInt* ptr) const;
	void postorder(const BTNodeInt* ptr) const;

	BTNodeInt* napravi(BinaryMinHeapInt& minHeap, int indeks, BTNodeInt* root);

public:
	BTreeInt() { root = nullptr; numOfElements = 0; }
	~BTreeInt() { deleteTree(root); }

	bool isEmpty() const { return root == nullptr; }

	void preorder() const { preorder(root); }
	void inorder() const { inorder(root); }
	void postorder() const { postorder(root); }

	void iterativePreorder() const;
	void breadthFirstSearch() const;

	void createFromMinHeap(BinaryMinHeapInt& minHeap);
};

