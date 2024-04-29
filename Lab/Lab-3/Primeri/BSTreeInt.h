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

	// Dodate funkcije
	int getMoment(BSTNodeInt* root);
	int getDeepest(BSTNodeInt* node, BSTNodeInt** deepest, int level);
	int deleteRightLeaves(BSTNodeInt* p);
	BSTNodeInt* mirror(BSTNodeInt* node);
	int countSingleLeavesNodes(BSTNodeInt* p);
	bool jeList(BSTNodeInt* node);
	void getMaxDifferenceNode(BSTNodeInt* root, BSTNodeInt** maxNode, int& maxDiff, int& sumParni, int& sumNeparni);

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

	// Dodate funkcije
	int getMoment();
	int getDeepest(BSTNodeInt** deepest);
	int deleteRightLeaves();
	int levelWithMostNodes();
	BSTreeInt* mirrorCopy();
	int countSingleLeavesNodes();
	BSTNodeInt* getMaxDifferenceNode(); // klk II 2023
};

