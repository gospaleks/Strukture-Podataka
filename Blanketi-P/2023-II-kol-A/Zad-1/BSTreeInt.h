#pragma once

#include "BSTNodeInt.h"

class BSTreeInt
{
protected:
	BSTNodeInt* root;
	long numOfElements;

	void deleteTree(BSTNodeInt* ptr);

	void inorder(const BSTNodeInt* ptr) const;
	void preorder(const BSTNodeInt* ptr) const;
	void postorder(const BSTNodeInt* ptr) const;

	// helper f-ja
	int maxAbs(BSTNodeInt* node, int& maxAbsValue, BSTNodeInt** maxAbsNode);

public:
	BSTreeInt() { root = nullptr; numOfElements = 0; }
	~BSTreeInt() { deleteTree(root); }

	bool isEmpty() const { return root == nullptr; }

	bool isInTree(int el) const { return search(el) != nullptr; }
	BSTNodeInt* search(int el) const;

	void insert(int el);
	void deleteByCopying(int el);
	void deleteByMerging(int el);

	void preorder() const { preorder(root); }
	void inorder() const { inorder(root); }
	void postorder() const { postorder(root); }

	void iterativePreorder() const;
	void breadthFirstSearch() const;

	// dodata funkcija
	BSTNodeInt* maxAbsBetweenSubtrees();
};

