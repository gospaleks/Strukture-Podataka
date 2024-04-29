#include "BSTreeInt.h"

#include <exception>
using namespace std;

#include "QueueAsArrayInt.h"
#include "StackAsArrayInt.h"

int BSTreeInt::getMoment()
{
	return getMoment(root);
}

int BSTreeInt::getMoment(BSTNodeInt* root)
{
	if (root == nullptr)
		return 0;

	// ako je list
	if (root->left == nullptr && root->right == nullptr)
		return 1;

	// inace uracunaj njega plus pozovi racunanje za levo i desno podstablo
	return 1 + getMoment(root->left) + getMoment(root->right);
}

int BSTreeInt::getDeepest(BSTNodeInt** deepest)
{
	return getDeepest(root, deepest, 0);
}

int BSTreeInt::getDeepest(BSTNodeInt* node, BSTNodeInt** deepest, int level)
{
	if (node == nullptr)
		return -1;

	// ako je list vrati njegov level i zapamti ga u deepest
	if (node->left == nullptr && node->right == nullptr) {
		*deepest = node;
		return level;
	}

	// inace nadji levo najdublji i desno najdublji
	BSTNodeInt* leftDeepest, * rightDeepest;
	int leftLevel = getDeepest(node->left, &leftDeepest, level + 1);
	int rightLevel = getDeepest(node->right, &rightDeepest, level + 1);

	// i uporedi dobijene rezultate
	if (leftLevel > rightLevel) {
		*deepest = leftDeepest;
		return leftLevel;
	}
	else {
		*deepest = rightDeepest;
		return rightLevel;
	}
}

int BSTreeInt::deleteRightLeaves()
{
	return deleteRightLeaves(root);
}

int BSTreeInt::deleteRightLeaves(BSTNodeInt* p)
{
	if (p == nullptr)
		return 0;

	// ako je desni list
	if (p->right != nullptr && p->right->left == nullptr && p->right->right == nullptr) {
		BSTNodeInt* tmp = p->right;
		p->right = nullptr;
		delete tmp;
		return 1 + deleteRightLeaves(p->left);
	}

	// inace izracunaj za levo i desno podstablo
	return deleteRightLeaves(p->right) + deleteRightLeaves(p->left);

	return 0;
}

int BSTreeInt::levelWithMostNodes()
{
	// koristi se BFS tj pretraga po sirinu
	// u red se stave svi cvorovi trenutnog nivoa i tako dok ima cvorova
	// svaki put se poredi da bi se zapamtila max vrednost
	int maxLevel = 0;
	int maxBrCvorova = 0;

	int level = 0;

	BSTNodeInt* tmp = root;
	QueueAsArrayBSTNodeInt red(numOfElements);

	if (tmp != nullptr) {

		red.enqueue(tmp);
		while (!red.isEmpty()) {

			// broj elemenata u redu je u stvari broj cvorova na trenutnom levelu
			int brCvorova = red.numberOfElements();
			if (brCvorova > maxBrCvorova) {
				maxBrCvorova = brCvorova;
				maxLevel = level;
			}

			// dodaj sve iz sledeceg nivoa
			for (int i = 0; i < brCvorova; ++i) {
				// izbaci jedan pa dodaj njegovu decu
				tmp = red.dequeue();

				// cout << tmp->getKey() << " "; // stampanje po nivoima

				if (tmp->left != nullptr)
					red.enqueue(tmp->left);
				if (tmp->right != nullptr)
					red.enqueue(tmp->right);
			}
			// cout << endl;

			// posle ove for petlje u redu su sada cvorovi sledeceg nivoa
			level++;
		}
	}

	return maxLevel;
}

BSTreeInt* BSTreeInt::mirrorCopy()
{
	BSTreeInt* mirrorTree = new BSTreeInt();
	mirrorTree->root = mirror(root);
	return mirrorTree;
}

BSTNodeInt* BSTreeInt::mirror(BSTNodeInt* node)
{
	if (node == nullptr)
		return nullptr;

	// pravi se novi cvor sa istim kljucem ali obrnutim podstablom
	BSTNodeInt* newNode = new BSTNodeInt(node->getKey());
	newNode->left = mirror(node->right);
	newNode->right = mirror(node->left);

	return newNode;
}

int BSTreeInt::countSingleLeavesNodes()
{
	return countSingleLeavesNodes(root);
}

int BSTreeInt::countSingleLeavesNodes(BSTNodeInt* p)
{
	if (p == nullptr)
		return 0;

	if ((p->left == nullptr && p->right != nullptr && jeList(p->right)) ||
		(p->right == nullptr && p->left != nullptr && jeList(p->left)))
		return 1;

	return countSingleLeavesNodes(p->left) + countSingleLeavesNodes(p->right);
}

bool BSTreeInt::jeList(BSTNodeInt* node)
{
	return (node->right == nullptr && node->left == nullptr);
}

BSTNodeInt* BSTreeInt::getMaxDifferenceNode()
{
	// vraca cvor kod koga je najveca razlika izmedju sume parnih i neparnih cvorova u njegovim podstablima

	BSTNodeInt* maxNode = nullptr;
	int maxDiff = 0, sumParni = 0, sumNeparni = 0;
	getMaxDifferenceNode(root, &maxNode, maxDiff, sumParni, sumNeparni);
	return maxNode;
}

void BSTreeInt::getMaxDifferenceNode(BSTNodeInt* root, BSTNodeInt** maxNode, int& maxDiff, int& sumParni, int& sumNeparni)
{
	if (root == nullptr) {
		return;
	}

	// ako je list
	if (root->left == nullptr && root->right == nullptr) {
		if (root->getKey() % 2 == 0)
			sumParni += root->getKey();
		else
			sumNeparni += root->getKey();
		return;
	}

	// inace izracunaj za levo i desno podstablo
	int sumParniLeft = 0, sumNeparniLeft = 0;
	int sumParniRight = 0, sumNeparniRight = 0;

	getMaxDifferenceNode(root->left, maxNode, maxDiff, sumParniLeft, sumNeparniLeft);
	getMaxDifferenceNode(root->right, maxNode, maxDiff, sumParniRight, sumNeparniRight);

	sumParni = sumParniLeft + sumParniRight;
	sumNeparni = sumNeparniLeft + sumNeparniRight;
	int razlika = abs(sumParni - sumNeparni);
	// ako je razlika veca od trenutne max razlike
	if (razlika > maxDiff) {
		maxDiff = razlika;
		*maxNode = root;
	}

	// cout << root->getKey() << ", diff: " << razlika << endl;

	// dodaj trenutni cvor na sumu
	if (root->getKey() % 2 == 0)
		sumParni += root->getKey();
	else
		sumNeparni += root->getKey();
}


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
