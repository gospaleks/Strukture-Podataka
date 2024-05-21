#include "GraphInt.h"

#include <iostream>
using namespace std;

#include "QueueAsArrayInt.h"
#include "StackAsArrayInt.h"

GraphAsListsInt::GraphAsListsInt() : start(nullptr), nodeNum()
{
}

GraphAsListsInt::~GraphAsListsInt()
{
	// cout << "Not implemented!" << endl;

	LinkedNodeInt* ptr = start;
	while (ptr != nullptr) {

		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {
			LinkedEdgeInt* pEdgeTmp = pEdge->link;
			delete pEdge;
			pEdge = pEdgeTmp;
		}

		LinkedNodeInt* ptrTmp = ptr;
		ptr = ptr->next;
		delete ptrTmp;
	}

	start = nullptr;
}

LinkedNodeInt* GraphAsListsInt::findNode(const int& data) const
{
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr && ptr->node != data)
		ptr = ptr->next;
	return ptr;
}

LinkedEdgeInt* GraphAsListsInt::findEdge(const int& dataSrc, const int& dataDest) const
{
	LinkedNodeInt* ptr = findNode(dataSrc);
	if (ptr == nullptr)
		return nullptr;
	LinkedEdgeInt* pEdge = ptr->adj;
	while (pEdge != nullptr && pEdge->dest->node != dataDest)
		pEdge = pEdge->link;
	return pEdge;
}

void GraphAsListsInt::insertNode(const int& data)
{
	start = new LinkedNodeInt(data, nullptr, start);
	nodeNum++;
}

bool GraphAsListsInt::insertEdge(const int& dataSrc, const int& dataDest, const double& weight /*= 0*/)
{
	LinkedNodeInt* pSrc = nullptr;
	LinkedNodeInt* pDest = nullptr;
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr && (pSrc == nullptr || pDest == nullptr)) {
		if (ptr->node == dataSrc) {
			pSrc = ptr;
		}
		else if (ptr->node == dataDest) {
			pDest = ptr;
		}
		ptr = ptr->next;
	}
	if (pSrc == nullptr || pDest == nullptr)
		return false;
	pSrc->adj = new LinkedEdgeInt(pDest, pSrc->adj);
	return true;
}

bool GraphAsListsInt::deleteEdge(const int& dataSrc, const int& dataDest)
{
	LinkedNodeInt* pSrc = findNode(dataSrc);
	if (pSrc == nullptr)
		return false;

	LinkedEdgeInt* pEdgePrev = nullptr;
	LinkedEdgeInt* pEdge = pSrc->adj;
	while (pEdge != nullptr && pEdge->dest->node != dataDest) {
		pEdgePrev = pEdge;
		pEdge = pEdge->link;
	}
	if (pEdge == nullptr)
		return false;

	if (pEdgePrev == nullptr)
		pSrc->adj = pEdge->link;
	else
		pEdgePrev->link = pEdge->link;

	delete pEdge;

	return true;
}

void GraphAsListsInt::deleteEdgeToNode(const LinkedNodeInt* pDest)
{
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr)
	{
		LinkedEdgeInt* pEdgePrev = nullptr;
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr && pEdge->dest != pDest) {
			pEdgePrev = pEdge;
			pEdge = pEdge->link;
		}
		if (pEdge != nullptr)
		{
			if (pEdgePrev == nullptr)
				ptr->adj = pEdge->link;
			else
				pEdgePrev->link = pEdge->link;
		}
		ptr = ptr->next;
	}
}

bool GraphAsListsInt::deleteNode(const int& data)
{
	LinkedNodeInt* prev = nullptr;
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr && ptr->node != data) {
		prev = ptr;
		ptr = ptr->next;
	}
	if (ptr == nullptr)
		return false;

	LinkedEdgeInt* pEdge = ptr->adj;
	while (pEdge != nullptr) {
		LinkedEdgeInt* pEdgeTmp = pEdge->link;
		delete pEdge;
		pEdge = pEdgeTmp;
	}
	ptr->adj = nullptr;

	deleteEdgeToNode(ptr);

	if (prev == nullptr)
		start = start->next;
	else
		prev->next = ptr->next;

	delete ptr;
	nodeNum--;

	return true;
}

void GraphAsListsInt::print() const
{
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr)
	{
		cout << ptr->node << " -> ";
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {
			cout << pEdge->dest->node << " | ";
			pEdge = pEdge->link;
		}
		cout << endl;
		ptr = ptr->next;
	}
}

void GraphAsListsInt::setStatusForAllNodes(int status) const
{
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr) {
		ptr->status = status;
		ptr = ptr->next;
	}
}

long GraphAsListsInt::breadthFirstTraversal(const int& data) const
{
	long retVal = 0;

	LinkedNodeInt* ptr = findNode(data);
	if (ptr == nullptr)
		return 0;

	setStatusForAllNodes(1);

	QueueAsArrayLinkedNodeInt queue(nodeNum);
	queue.enqueue(ptr);
	ptr->status = 2;
	while (!queue.isEmpty()) {
		ptr = queue.dequeue();
		ptr->status = 3;
		ptr->visit();
		retVal += 1;
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {
			if (pEdge->dest->status == 1) {
				queue.enqueue(pEdge->dest);
				pEdge->dest->status = 2;
			}
			pEdge = pEdge->link;
		}
	}
	cout << endl;
	return retVal;
}

long GraphAsListsInt::depthFirstTraversalIterative(const int& data) const
{
	long retVal = 0;

	LinkedNodeInt* ptr = findNode(data);
	if (ptr == nullptr)
		return 0;

	setStatusForAllNodes(1);

	StackAsArrayLinkedNodeInt stack(nodeNum);
	stack.push(ptr);
	ptr->status = 2;
	while (!stack.isEmpty()) {
		ptr = stack.pop();
		ptr->status = 3;
		ptr->visit();
		retVal += 1;
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {
			if (pEdge->dest->status == 1) {
				stack.push(pEdge->dest);
				pEdge->dest->status = 2;
			}
			pEdge = pEdge->link;
		}
	}
	cout << endl;
	return retVal;
}

long GraphAsListsInt::depthFirstTraversalRecursive(LinkedNodeInt* ptr) const
{
	int retVal = 0;
	if (ptr->status != 1) {
		ptr->visit();
		ptr->status = 1;
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {
			retVal += depthFirstTraversalRecursive(pEdge->dest);
			pEdge = pEdge->link;
		}
		retVal++;
	}
	return retVal;
}

long GraphAsListsInt::depthFirstTraversalRecursive(const int& data) const
{
	LinkedNodeInt* pNode = nullptr;
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr) {
		ptr->status = 0;
		if (ptr->node == data) {
			pNode = ptr;
		}
		ptr = ptr->next;
	}

	if (pNode == nullptr)
		return 0;

	return depthFirstTraversalRecursive(pNode);
}

long GraphAsListsInt::topologicalOrderTravrsal() const
{
	int retVal = 0;

	setStatusForAllNodes(0);

	LinkedNodeInt* ptr = start;
	while (ptr != nullptr) {
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {
			pEdge->dest->status += 1;
			pEdge = pEdge->link;
		}
		ptr = ptr->next;
	}

	QueueAsArrayLinkedNodeInt queue(nodeNum);
	ptr = start;
	while (ptr != nullptr) {
		if (ptr->status == 0)
			queue.enqueue(ptr);
		ptr = ptr->next;
	}

	while (!queue.isEmpty()) {
		ptr = queue.dequeue();
		ptr->visit();
		retVal += 1;
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {
			pEdge->dest->status--;
			if (pEdge->dest->status == 0)
				queue.enqueue(pEdge->dest);
			pEdge = pEdge->link;
		}
	}
	cout << endl;
	return retVal;
}

// Primeri sa lab vezbi

bool GraphAsListsInt::findCycleWithNode(const int& data)
{
	/*
		Odredjuje da li postoji (i koji je) ciklus koji sadrzi cvor data.
	*/

	// Postavi status svim cvorovima na 0
	setStatusForAllNodes(0);

	// Postavi prev na null svim cvorovima
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr) {
		ptr->prev = nullptr;
		ptr = ptr->next;
	}

	// Pronadji cvor data od koga krece trazenje ciklusa
	ptr = findNode(data);

	if (ptr == nullptr)
		return false;

	StackAsArrayLinkedNodeInt stek(nodeNum);
	ptr->status = 1;
	stek.push(ptr);
	while (!stek.isEmpty()) {
		ptr = stek.pop();
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {

			if (pEdge->dest->status == 1) {
				// Ako je pronadjen ciklus
				// Ispisi putanju
				cout << "Ciklus: ";
				LinkedNodeInt* ptrTmp = ptr;
				while (ptrTmp != nullptr) {
					cout << ptrTmp->node << " ";
					ptrTmp = ptrTmp->prev;
				}
				return true;
			}

			if (pEdge->dest->status == 0) {
				pEdge->dest->status = 1;
				pEdge->dest->prev = ptr;
				stek.push(pEdge->dest);
			}

			pEdge = pEdge->link;
		}
	}

	cout << "Nema ciklusa!" << endl;
	return false;
}

void GraphAsListsInt::findCycleThroughNode(int dataStart, int dataEnd, int dataOnPath)
{
	/*
		Realizovati metod koji odredjuje i prikazuje jedan (bilo koji) put
		u grafu izmedju zadatog pocetnog i krajnjeg cvora koji prolazi 
		kroz treci zadati cvor i ne mora biti prost
	*/

	setStatusForAllNodes(0);

	// Postavi prev na null svim cvorovima
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr) {
		ptr->prev = nullptr;
		ptr = ptr->next;
	}

	ptr = findNode(dataStart);

	// Nije pronadjen pocetni ili krajnji cvor
	if (ptr == nullptr)
		return;

	bool foundDataOnPath = false;

	StackAsArrayLinkedNodeInt stek(nodeNum);
	ptr->status = 1;
	stek.push(ptr);
	while (!stek.isEmpty()) {

		ptr = stek.pop();
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {

			if (pEdge->dest->status == 0) {
				pEdge->dest->status = 1;
				pEdge->dest->prev = ptr;
				stek.push(pEdge->dest);
			}

			// ako je naso granu ga cvoru dataOnPath
			// ne dozvoli dfs-u da prolazi ostale grane jer put mora da prodje kroz tu granu
			// zato ide break
			if (pEdge->dest->node == dataOnPath) {
				foundDataOnPath = true;
				break;
			}

			// ako je doso do krajnjeg cvora
			if (pEdge->dest->node == dataEnd) {
				// ako je proso onaj treci cvor usput ispisi put
				if (foundDataOnPath) {
					cout << "Put: ";
					cout << dataEnd << " ";
					LinkedNodeInt* ptrTmp = ptr;
					while (ptrTmp != nullptr) {
						cout << ptrTmp->node << " ";
						ptrTmp = ptrTmp->prev;
					}
					cout << endl;
				}
				return;
			}

			pEdge = pEdge->link;
		}

	}

}

// TODO: Realizovati metod koji vraca da li postoji i odredjuje jedan (bilo koji)
// put u grafu od zadatog pocetnog (dataFirst) do zadatog krajnjeg cvora (dataLast)
// koji ne prolazi kroz zadati poteg.
bool GraphAsListsInt::pathWithoutEdge(int dataFirst, int dataLast, int dataEgdeSource, int dataEdgeDest)
{
	LinkedNodeInt* ptr = start;

	// postavi status na 0 i prev na NULL
	while (ptr != nullptr) {
		ptr->status = 0;
		ptr->prev = nullptr;
		ptr = ptr->next;
	}

	ptr = findNode(dataFirst);
	
	if (ptr == nullptr)
		return false;

	StackAsArrayLinkedNodeInt stek(nodeNum);
	ptr->status = 1;
	stek.push(ptr);

	while (!stek.isEmpty()) {
		ptr = stek.pop();
		LinkedEdgeInt* pEdge = ptr->adj;

		while (pEdge != nullptr) {

			// ako je to taj poteg ne dodaj ga na stek (KLJUCNI DEO)
			if (ptr->node == dataEgdeSource && pEdge->dest->node == dataEdgeDest) {
				pEdge = pEdge->link;
				continue;
			}

			// Oznaci cvor kao posecen
			if (pEdge->dest->status == 0) {
				pEdge->dest->status = 1;
				pEdge->dest->prev = ptr;
				stek.push(pEdge->dest);
			}

			// Nadjen put
			if (pEdge->dest->node == dataLast) {
				cout << "Put: ";
				cout << dataLast << " ";
				LinkedNodeInt* ptrTmp = ptr;
				while (ptrTmp != nullptr) {
					cout << ptrTmp->node << " ";
					ptrTmp = ptrTmp->prev;
				}
				cout << endl;
				return true;
			}


			pEdge = pEdge->link;
		}
	}

	cout << "Nije nadjen takav put." << endl;
	return false;
}