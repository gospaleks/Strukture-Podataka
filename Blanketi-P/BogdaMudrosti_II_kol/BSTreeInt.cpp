#include "BSTreeInt.h"
#include <math.h>
#include <exception>

#include "QueueAsArrayInt.h"
#include "StackAsArrayInt.h"
using namespace std;

void BSTreeInt::deleteTree(BSTNodeInt* ptr)
{
	if (ptr != nullptr) {
		deleteTree(ptr->left);
		deleteTree(ptr->right);
		delete ptr;
	}
}

BSTNodeInt* BSTreeInt::search(int el) const
{
	BSTNodeInt* ptr = root;
	while (ptr != nullptr)
		if (ptr->isEQ(el))
			return ptr;
		else if (ptr->isGT(el))
			ptr = ptr->left;
		else
			ptr = ptr->right;
	return nullptr;
}

void BSTreeInt::insert(int el)
{
	BSTNodeInt* ptr = root, * par = nullptr;
	while (ptr != nullptr) {  // trazenje mesta za umetanje novog cvora
		par = ptr;
		if (ptr->isLT(el))
			ptr = ptr->right;
		else
			ptr = ptr->left;
	}
	if (root == nullptr)    // stablo je prazno
		root = new BSTNodeInt(el);
	else if (par->isLT(el))
		par->right = new BSTNodeInt(el);
	else
		par->left = new BSTNodeInt(el);
	numOfElements++;
}

void BSTreeInt::deleteByCopying(int el)
{
	BSTNodeInt* node, * ptr = root, * par = nullptr;
	while (ptr != nullptr && !ptr->isEQ(el)) { 	// nalazenje cvora sa zeljenim el.
		par = ptr;
		if (ptr->isLT(el)) ptr = ptr->right;
		else ptr = ptr->left;
	}
	node = ptr;
	if (ptr != nullptr && ptr->isEQ(el)) {
		if (node->right == nullptr)             // cvor nema desnog potomka (1)
			node = node->left;
		else if (node->left == nullptr)         // cvor nema levog potomka (2)
			node = node->right;
		else {									// cvor ima oba potomka (3)
			BSTNodeInt* tmp = node->left;
			BSTNodeInt* parent = node;
			while (tmp->right != nullptr) {		// nalazenje krajnjeg desnog cvora
				parent = tmp;             		// u levom podstablu
				tmp = tmp->right;
			}
			node->setKey(tmp->getKey());		// prepisivanje reference na kljuc 
			if (parent == node)           		// tmp je direktni levi potomak node-a
				parent->left = tmp->left;		// ostaje isti raspored u levom podstablu
			else
				parent->right = tmp->left; 		// levi potomak tmp-a 
			delete tmp;							// se pomera na mesto tmp-a
			numOfElements--;
			return;
		}
		if (ptr == root)						// u slucaju (1) i (2) samo je pomerena
			root = node;						// referenca node pa je potrebno
		else if (par->left == ptr)				// izmeniti i link prethodnog cvora
			par->left = node;					// u slucaju (3) ovo nema dejstva
		else
			par->right = node;
		delete ptr;
		numOfElements--;
	}
	else if (root != nullptr)
		throw new exception("Element is not in the tree!");
	else
		throw new exception("The tree is empty!");
}

void BSTreeInt::deleteByMerging(int el)
{
	BSTNodeInt* node, * ptr = root, * par = nullptr;
	while (ptr != nullptr && !ptr->isEQ(el)) {	// nalazenje cvora sa zeljenim el.
		par = ptr;
		if (ptr->isLT(el)) ptr = ptr->right;
		else ptr = ptr->left;
	}
	node = ptr;
	if (ptr != nullptr && ptr->isEQ(el)) {
		if (node->right == nullptr)				// cvor nema desnog potomka (1)
			node = node->left;
		else if (node->left == nullptr)			// cvor nema levog potomka (2)
			node = node->right;
		else {									// cvor ima oba potomka (3)
			BSTNodeInt* tmp = node->left;
			while (tmp->right != nullptr)		// nalazenje krajnjeg desnog cvora
				tmp = tmp->right;				// u levom podstablu
			tmp->right = node->right;			// prebacivanje desnog linka node-a u tmp
			node = node->left;					// na tekucem mestu bice prvi levi potomak
		}
		if (ptr == root)
			root = node;
		else if (par->left == ptr)
			par->left = node;
		else
			par->right = node;
		delete ptr;
		numOfElements--;
	}
	else if (root != nullptr)
		throw new exception("Element is not in the tree!");
	else
		throw new exception("The tree is empty!");
}

void BSTreeInt::preorder(const BSTNodeInt* ptr) const
{
	if (ptr != nullptr) {
		ptr->visit();
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void BSTreeInt::inorder(const BSTNodeInt* ptr) const
{
	if (ptr != nullptr) {
		inorder(ptr->left);
		ptr->visit();
		inorder(ptr->right);
	}
}

void BSTreeInt::postorder(const BSTNodeInt* ptr) const
{
	if (ptr != nullptr) {
		postorder(ptr->left);
		postorder(ptr->right);
		ptr->visit();
	}
}

void BSTreeInt::iterativePreorder() const
{
	BSTNodeInt* ptr = root;
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

void BSTreeInt::breadthFirstSearch() const
{
	BSTNodeInt* ptr = root;
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

void BSTreeInt::ispisiLepo(BSTNodeInt* root, int space)
{
	int COUNT = 10;
	// Base case
	if (root == NULL)
		return;

	// Increase distance between levels
	space += COUNT;

	// Process right child first
	ispisiLepo(root->right, space);

	// Print current node after space
	// count
	cout << endl;
	for (int i = COUNT; i < space; i++) {
		cout << " ";

	}
	cout << root->key << "\n";

	// Process left child
	ispisiLepo(root->left, space);
}

void BSTreeInt::ispisiLepo1()
{
	ispisiLepo(root, 0);
}

int BSTreeInt::visinaStabla1()
{
	return visinaStabla(root);
}

int BSTreeInt::visinaStabla(BSTNodeInt* root)
{
	if (root == nullptr)
		return 0;
	int levaVisina = visinaStabla(root->left);
	int desnaVisina = visinaStabla(root->right);
	return max(levaVisina, desnaVisina) + 1;
}

int BSTreeInt::moment()
{
	return moment(root);
}

int BSTreeInt::moment(BSTNodeInt* root)
{
	if (root == nullptr)
		return 0;
	if (root->left == nullptr && root->right == nullptr)
		return 1;
	return 1 + moment(root->left) + moment(root->right);
}

int BSTreeInt::tezina()
{
	return tezina(root);
}

int BSTreeInt::tezina(BSTNodeInt* root)
{
	if (root == nullptr)
		return 0;
	if (root->left == nullptr && root->right == nullptr)
		return 1;
	return tezina(root->right) + tezina(root->left);
}

void BSTreeInt::obrisiListove()
{
	obrisiListove(root);
}

void BSTreeInt::obrisiListove(BSTNodeInt* root)
{
	if (root == NULL)
		return;
	if (root->left == NULL && root->right == NULL) {
		delete root;
		return;
	}
	obrisiListove(root->left);
	obrisiListove(root->right);

	//nesto jebe opasno
}

int BSTreeInt::coutCloseParents(int n)
{
	return coutCloseParents(root, n);
}

int BSTreeInt::coutCloseParents(BSTNodeInt* root, int n)
{
	if (root == nullptr)
		return 0;

	if (root->left != nullptr && root->right != nullptr)
		if (abs(root->getKey() - root->left->getKey()) <= n && abs(root->getKey() - root->right->getKey()) <= n)
			return 1 + coutCloseParents(root->left, n) + coutCloseParents(root->right, n);

	return coutCloseParents(root->left, n) + coutCloseParents(root->right, n);


	//drugi nacin
	/*if (root == NULL)
		return 0;

	int sum = 0;
	if (root->left != nullptr || root->right != nullptr)
		sum = coutCloseParents(root->left, n) + coutCloseParents(root->right, n);

	if (root->left == NULL && root->right == NULL)
		return sum;

	if (root->left != NULL && root->right != NULL)
	{
		if (abs(root->key - root->left->key) < n && abs(root->key - root->right->key) < n)
			return sum + 1;
		else
			return sum;
	}
	else
	{
		return sum;
	}*/
}

BSTNodeInt* BSTreeInt::funkcija(BSTNodeInt** cvorSaNajvecomRazlikom, int* najvecaRazlika)
{
	
	return pronadjiBSTreeIntSaNajvecomRazlikom(root, cvorSaNajvecomRazlikom, najvecaRazlika);
}

int BSTreeInt::izbrojiCvorove(BSTNodeInt* root)
{
	if (root == nullptr)
		return 0;
	return 1 + izbrojiCvorove(root->left) + izbrojiCvorove(root->right);
}

BSTNodeInt* BSTreeInt::pronadjiBSTreeIntSaNajvecomRazlikom(BSTNodeInt* koren, BSTNodeInt** cvorSaNajvecomRazlikom, int* najvecaRazlika)
{
	if (root == NULL)
		return NULL;

	// Izračunavanje razlike broja čvorova u levom i desnom podstablu
	int razlika = abs(izbrojiCvorove(root->left) - izbrojiCvorove(root->right));

	// Ažuriranje čvora sa najvećom razlikom i najveće razlike
	if (razlika > *najvecaRazlika) {
		*najvecaRazlika = razlika;
		*cvorSaNajvecomRazlikom = root;
	}

	// Rekurzivno pretraga levog i desnog podstabla
	pronadjiBSTreeIntSaNajvecomRazlikom(root->left, cvorSaNajvecomRazlikom, najvecaRazlika);
	pronadjiBSTreeIntSaNajvecomRazlikom(root->right, cvorSaNajvecomRazlikom, najvecaRazlika);

	return *cvorSaNajvecomRazlikom;
}

BSTNodeInt* BSTreeInt::findDeepestLeaf()
{
	if (!root)
		return nullptr;
	BSTNodeInt* najdublji = nullptr;
	int dubina = 0;
	return findDeepestLeaf(root, &najdublji, &dubina, 0);
}

BSTNodeInt* BSTreeInt::findDeepestLeaf(BSTNodeInt* root, BSTNodeInt** najdublji, int* najdubljiNivo, int trenutna)
{
	if (!root)
		return nullptr;
	if (root->left == nullptr && root->right == nullptr) {
		if (trenutna > *najdubljiNivo) {
			*najdubljiNivo = trenutna;
			*najdublji = root;
		}
	}

	findDeepestLeaf(root->left, najdublji, najdubljiNivo, trenutna + 1);
	findDeepestLeaf(root->right, najdublji, najdubljiNivo, trenutna + 1);

	return *najdublji;
}

BSTNodeInt* BSTreeInt::maxHeigthDiff()
{
	BSTNodeInt* izabrani = nullptr;
	int najvecarazlika = 0;
	return maxHeigthDiff(root, &izabrani, &najvecarazlika);
}

BSTNodeInt* BSTreeInt::maxHeigthDiff(BSTNodeInt* root, BSTNodeInt** izabrani, int* najvecarazlika)
{
	if (!root)
		return nullptr;
	int razlika = visinaStabla(root->left) - visinaStabla(root->right);
	if (abs(razlika) > *najvecarazlika) {
		*izabrani = root;
		*najvecarazlika = abs(razlika);
	}
	maxHeigthDiff(root->left, izabrani, najvecarazlika);
	maxHeigthDiff(root->right, izabrani, najvecarazlika);
	return *izabrani;
}

BSTNodeInt* BSTreeInt::findSibling(BSTNodeInt* p)
{
	if (root == p)
		return nullptr;

	BSTNodeInt* ptr = root;
	QueueAsArrayBSTNodeInt red(numOfElements);
	red.enqueue(ptr);
	int brDodatih = 1;
	bool uRed = false;

	while (!red.isEmpty()) {
		if (brDodatih == red.numberOfElements()) {

			if (uRed && red.numberOfElements() > 1) {
				do {
					ptr = red.dequeue();
					if (ptr != p)
						return ptr;
				} while (!red.isEmpty());
			}
			else if (uRed)
				return nullptr;

			brDodatih = 0;
		}
		ptr = red.dequeue();

		if (ptr->left != nullptr) {
			if (ptr->left == p)
				uRed = true;
			red.enqueue(ptr->left);
			brDodatih++;
		}

		if (ptr->right != nullptr) {
			if (ptr->right == p)
				uRed = true;
			red.enqueue(ptr->left);
			brDodatih++;
		}
	}
	return nullptr;
}

int BSTreeInt::countNodesInRange(BSTNodeInt* root, int max, int min)
{
	/*if (!root)			neefikasno
		return 0;
	if (root->key >= min && root->key <= max)
		return 1 + countNodesInRange(root->left, max, min) + countNodesInRange(root->right, max, min);
	else
		return countNodesInRange(root->left, max, min) + countNodesInRange(root->right, max, min);*/

	if (!root)
		return 0;

	int suma = 0;
	if (root->left)
		if ((root->left->key >= min && root->left->key <= max) || root->left->right != NULL)
			suma += countNodesInRange(root->left, min, max);
	if (root->right)
		if ((root->right->key <= max && root->right->key >= min) || root->right->left != NULL)
			suma += countNodesInRange(root->right, min, max);

	if (root->key >= min && root->key <= max)
		suma++;

	return suma;
}

int BSTreeInt::countNodesInRange(int max, int min)
{
	if (!root)
		return 0;
	return countNodesInRange(root, max, min);
}

int BSTreeInt::countCloseSiblings()
{
	return countCloseSiblings(root);
}

int BSTreeInt::countCloseSiblings(BSTNodeInt* root)
{
	if (!root || (!root->left && !root->right))
		return 0;

	int broj = 0;
	broj = countCloseSiblings(root->left) + countCloseSiblings(root->right);

	if (root->left && abs(abs(root->key - root->left->key) == 1))
		broj++;
	if (root->right && abs(root->key - root->right->key) == 1)
		broj++;

	return broj;
}

bool BSTreeInt::isPerfect()
{
	if (!root)
		return false;
	return isPerfect(root);
}

bool BSTreeInt::isPerfect(BSTNodeInt* root)
{
	if (!root)
		return true;

	if (abs(izbrojiCvorove(root->left) - izbrojiCvorove(root->right)) <= 1)
		return true * isPerfect(root->left) * isPerfect(root->right);
	else
		return false;
}

BSTNodeInt* BSTreeInt::nadjiNajveceDesnoPodstablo()
{
	BSTNodeInt* nadjenitr = nullptr;
	int brojDesno = 0;
	
	return nadjiNajveciDesnoPodstablo(root, &nadjenitr, &brojDesno);
}

BSTNodeInt* BSTreeInt::nadjiNajveciDesnoPodstablo(BSTNodeInt* root, BSTNodeInt** nadjenitr, int* najvecaRazlika)
{
	if (!root)
		return nullptr;

	int brojDesnih = izbrojiCvorove(root->right);

	if (brojDesnih > *najvecaRazlika) {
		*najvecaRazlika = brojDesnih;
		*nadjenitr = root;
	}
	nadjiNajveciDesnoPodstablo(root->left, nadjenitr, najvecaRazlika);
	return *nadjenitr;
}
