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

	void ispisiLepo(BSTNodeInt* root, int space);
	void ispisiLepo1();

	//pravljenje funkcije
	int visinaStabla1();
	int visinaStabla(BSTNodeInt* root);
	int moment();
	int moment(BSTNodeInt* root);
	int tezina();
	int tezina(BSTNodeInt* root);
	void obrisiListove();
	void obrisiListove(BSTNodeInt* root);

	//blanketi

	//januar 2024
	int coutCloseParents(int n);
	int coutCloseParents(BSTNodeInt* root, int n);

	//kolokvijum 2 2023 grupa A
	BSTNodeInt* funkcija(BSTNodeInt** cvorSaNajvecomRazlikom, int* najvecaRazlika);
	int izbrojiCvorove(BSTNodeInt* root);
	BSTNodeInt* pronadjiBSTreeIntSaNajvecomRazlikom(BSTNodeInt* koren, BSTNodeInt** cvorSaNajvecomRazlikom, int* najvecaRazlika);

	//Oktobar 2023
	BSTNodeInt* findDeepestLeaf();
	BSTNodeInt* findDeepestLeaf(BSTNodeInt* root, BSTNodeInt** najdublji, int* najdubljinivo, int trenutna);

	//Jun 2023
	BSTNodeInt* maxHeigthDiff();
	BSTNodeInt* maxHeigthDiff(BSTNodeInt* root, BSTNodeInt** izabrani, int* najvecarazlika);

	//Oktobar2 2022
	BSTNodeInt* findSibling(BSTNodeInt* p);

	//Septembar 2022
	int countNodesInRange(BSTNodeInt* root, int max, int min);
	int countNodesInRange(int max, int min);

	//Oktobar 2022
	int countCloseSiblings();
	int countCloseSiblings(BSTNodeInt* root);

	//Jun 2022
	bool isPerfect();
	bool isPerfect(BSTNodeInt* root);

	//Jun2 2021
	BSTNodeInt* nadjiNajveceDesnoPodstablo();
	BSTNodeInt* nadjiNajveciDesnoPodstablo(BSTNodeInt* root, BSTNodeInt** nadjenitr, int* najvecaRazlika);
};
