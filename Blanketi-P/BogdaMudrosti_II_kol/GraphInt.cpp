#include "GraphInt.h"

#include <iostream>
using namespace std;

#include "QueueAsArrayInt.h"
#include "StackAsArrayInt.h"
using namespace std;

GraphAsListsInt::GraphAsListsInt() : start(nullptr), nodeNum()
{
}

GraphAsListsInt::~GraphAsListsInt()
{
	cout << "Not implemented!" << endl;
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
		ptr->udaljenost = 0;
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

void GraphAsListsInt::uNeusmereni()
{
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr) {

		LinkedEdgeInt* pedge = ptr->adj;
		while (pedge != nullptr) {

			LinkedEdgeInt* temp = pedge->dest->adj;
			while (temp != nullptr && temp->dest->node != ptr->node)
				temp = temp->link;

			if (temp == nullptr)
				pedge->dest->adj = new LinkedEdgeInt(ptr, pedge->dest->adj);

			pedge = pedge->link;
		}
		ptr = ptr->next;
	}
}

bool GraphAsListsInt::arePathPossible(LinkedNodeInt* start, LinkedNodeInt* goal1, LinkedNodeInt* goal2, LinkedNodeInt* mid)
{
														//svi cvorovi nisu obradjeni i izmenjeno je da putanja je svuda 0
	setStatusForAllNodes(1);
	StackAsArrayLinkedNodeInt stek(nodeNum);
	stek.push(start);
	start->status = 2;
	int minDuzina = INT_MAX;							//posto trazimo min duzinu prvo stavimo max
														//ovo je trebalo ipak po sirini da se radi jer cim dodjes do mid to odmah znaci da je to najkraci put
	while (!stek.isEmpty()) {
														//dok nije prazan stek vadimo nesto 
		LinkedNodeInt* temp = stek.pop();
		if (temp != start)								//pitamo da nije start i update-ujemo udaljenost trenutnog cvora
			temp->udaljenost = temp->prev->udaljenost + 1;
		temp->status = 3;
		LinkedEdgeInt* tempedge = temp->adj;
		while (tempedge != nullptr) {					//ulazimo u listu potega tog cvora i idemo dog potezi postoje

			if (tempedge->dest != goal1 && tempedge->dest != goal2 && tempedge->dest->status == 1) {		
														//da li je razlicit od goal1 i goal2 jer trazimo put do mid koji ne prolazi do goal1 ili goal2 i status mora pitamo da l je 1 da ne bi dodavali nesto sto smo vec proverili
				if (tempedge->dest != mid) {			//mozemo da dodamo u stek i pitamo da l je razlicito od mid cvora

					stek.push(tempedge->dest);				//inace prelazimo na novi edge
					tempedge->dest->status = 2;
					tempedge->dest->prev = temp;
					tempedge = tempedge->link;
				}
				else {
					if (temp->udaljenost + 1 < minDuzina) {		//ako smo dosli do mid, pitamo koja je trenutna udaljenost i da l je manja od trenutne min duzine, mid je dest zato ide + 1
						minDuzina = temp->udaljenost + 1;		//update minDuzina 
						mid->prev = temp;						//update prethodnik od mida da ne bi posle isli ponovo preko tog puta
						mid->udaljenost = temp->udaljenost + 1;	//nova udaljenost mida
					}
				}
			}
			tempedge = tempedge->link;					//prelazimo na sledeci poteg
		}
	}

	if (mid->udaljenost == 0)							//proveravamo da l smo uopste mogli da dodjemo do mid-a
		return false;

	LinkedNodeInt* temp = mid;
															
	setStatusForAllNodes(1);							//restartujemo sve statuse

	while (temp != start) {
														//stampamo put unazad da vidimo koji je najkraci do mid i stavljamo statuse na 10 u tom putu
		cout << temp->node << "-";
		temp->status = 3;								//stavljamo najkracem putu status na 3 da se ne bi vracali preko njega
		temp = temp->prev;								//printamo put ali to i ne mora bitno je ovo iznad
	}
	temp->status = 3;
	cout << temp->node;

	bool prvi = false;
	bool drugi = false;

	temp = mid;
	stek.push(temp);									//stek je sigurno prazan kad smo izasli iz gornje while petlje
	return true;
														
	while (!stek.isEmpty()) {							//trazim sad put do dest1 i do dest2 ali ne preko najkraceg puta ovde treba bas po dubini

		temp = stek.pop();
		temp->status = 3;								//popujemo i idemo na sledeci
		LinkedEdgeInt* tempedge = temp->adj;

		while (tempedge != nullptr) {
			if (tempedge->dest->status == 1) {

				if (tempedge->dest == goal1)
					prvi = true;
				if (tempedge->dest == goal2)
					drugi = true;						//ovo je intuitivno
				if (prvi && drugi)
					return true;
				stek.push(tempedge->dest);				//nnastavljamo dalje
				tempedge->dest->status = 2;
			}
			tempedge = tempedge->link;
		}
	}
	return false;										//ako izadjemo iz svega vracamo false
}

bool GraphAsListsInt::v2(LinkedNodeInt* pocetak, LinkedNodeInt* goal1, LinkedNodeInt* goal2, LinkedNodeInt* mid)
{
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr) {
		ptr->status = 1;
		ptr->prev = nullptr;
	}

	if (!v2pom(pocetak, mid))
		return false;

	setStatusForAllNodes(1);

	ptr = mid;
	while (ptr != nullptr) {
		ptr->status = 3;
		ptr = ptr->prev;
	}

	if (!v2pom(mid, goal1))
		return false;

	setStatusForAllNodes(1);

	ptr = mid;
	while (ptr != nullptr) {
		ptr->status = 3;
		ptr = ptr->prev;
	}

	if (!v2pom(mid, goal2))
		return false;

	return true;
}

bool GraphAsListsInt::v2pom(LinkedNodeInt* pocetak, LinkedNodeInt* end)
{
	LinkedNodeInt* ptr = pocetak;
	QueueAsArrayLinkedNodeInt red(nodeNum);
	red.enqueue(ptr);
	ptr->status = 2;

	while (!red.isEmpty()) {

		ptr = red.dequeue();
		ptr->status = 3;

		LinkedEdgeInt* pedge = ptr->adj;
		while (pedge != nullptr) {

			if (pedge->dest = end) {
				pedge->dest->prev = ptr;
				return true;
			}
			else if (pedge->dest->status == 1) {
				pedge->dest->status = 2;
				red.enqueue(pedge->dest);
				pedge->dest->prev = ptr;
			}
			pedge = pedge->link;
		}
	}
}

int GraphAsListsInt::subgrapfCnt(int p)
{
	setStatusForAllNodes(1);
	uNeusmereni();

	int br = 0;

	LinkedNodeInt* ptr = start;
	while (ptr != nullptr) {

		if(ptr->status == 1)
			if (bfsHelperVrdnost(ptr, p))
				br++;
		ptr = ptr->next;
	}
	return br;
}

bool GraphAsListsInt::bfsHelperVrdnost(LinkedNodeInt* ptr, int p)
{
	LinkedNodeInt* temp = ptr;
	QueueAsArrayLinkedNodeInt red(nodeNum);
	temp->status = 2;
	red.enqueue(temp);

	bool imaGa = false;

	while (!red.isEmpty()) {

		temp = red.dequeue();
		temp->status = 3;
		
		LinkedEdgeInt* grana = temp->adj;
		while (grana != nullptr) {

			if (grana->dest->status == 1) {

				if (grana->dest->node > p) {
					imaGa = true;
				}
				grana->dest->status = 2;
				red.enqueue(grana->dest);
			}
			grana = grana->link;
		}
	}
	return imaGa;
}

int GraphAsListsInt::doesConnentedComponentExists(int k)
{
	uNeusmereni();
	setStatusForAllNodes(1);
	int br = 0;
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr) {

		if (ptr->status == 1)
			if (bfsHelperZaK(ptr, k))
				br++;
		ptr = ptr->next;
	}
	return br;
}

bool GraphAsListsInt::bfsHelperZaK(LinkedNodeInt* ptr, int k)
{
	bool ima = false;
	int br = 0;
	LinkedNodeInt* temp = ptr;
	QueueAsArrayLinkedNodeInt red(nodeNum);
	red.enqueue(temp);
	temp->status = 2;

	while (!red.isEmpty()) {

		temp = red.dequeue();
		temp->status = 3;
		br++;
		
		LinkedEdgeInt* etemp = temp->adj;
		while (etemp != nullptr) {

			if (etemp->dest->status == 1) {
				etemp->dest->status = 2;
				red.enqueue(etemp->dest);
			}
			etemp = etemp->link;
		}
	}
	if (br > k)
		ima = true;
	return ima;
}

int GraphAsListsInt::LongestSimpleCycle()
{
	LinkedNodeInt* ptr = start;
	
	while (ptr != nullptr) {
		ptr->status = 1;
		ptr = ptr->next;
	}
	int najveci = 0;

	ptr = start;
	while (ptr != nullptr) {

		setStatusForAllNodes(1);
		int trenutna = pretragaZaCikl(ptr);
		if (trenutna > najveci)
			najveci = trenutna;
		ptr = ptr->next;
	}
	return najveci - 1;
}

int GraphAsListsInt::pretragaZaCikl(LinkedNodeInt* ptr)
{
	int duzina = -1;
	int tempDuzina = -1;
	StackAsArrayLinkedNodeInt stek(nodeNum);
	LinkedNodeInt* temp = ptr;
	stek.push(temp);
	temp->status = 2;

	while (!stek.isEmpty()) {

		temp = stek.pop();
		temp->status = 3;
		tempDuzina++;
		
		LinkedEdgeInt* grana = temp->adj;
		while (grana != nullptr) {

			if (grana->dest == ptr) {
				duzina = tempDuzina;
				return duzina;
			}
			else if (grana->dest->status == 1) {
				grana->dest->status = 2;
				stek.push(grana->dest);
			}
			grana = grana->link;
		}
	}
	return duzina;
}

bool GraphAsListsInt::canReach(int A, int B, int noNodes)
{
	setStatusForAllNodes(1);

	LinkedNodeInt* a = findNode(A);
	if (a == nullptr)
		return false;

	LinkedNodeInt* b = findNode(B);
	if (b == nullptr)
		return false;

	LinkedNodeInt* temp;
	StackAsArrayLinkedNodeInt stek(nodeNum);

	stek.push(a);
	while (!stek.isEmpty()) {

		temp = stek.pop();

		LinkedEdgeInt* grana = temp->adj;
		while (grana != nullptr) {

			if (grana->dest->status == 1) {
				grana->dest->status = temp->status + 1;
				stek.push(grana->dest);
			}
			if (grana->dest == b) {
				if (grana->dest->status <= noNodes)
					return true;
			}
			grana = grana->link;
		}
	}
	return false;
}

bool GraphAsListsInt::isCyclic()
{
	LinkedNodeInt* ptr = start;

	while (ptr != nullptr) {
		ptr->status = 1;
		ptr = ptr->next;
	}
	ptr = start;

	int statustren = 10;

	while (ptr != nullptr) {
		
		if (ptr->status == 1)
			if (pretraga(ptr, statustren++))
				return true;
		ptr = ptr->next;
	}
	return false;
}

bool GraphAsListsInt::pretraga(LinkedNodeInt* ptr, int trenstatus)
{
	StackAsArrayLinkedNodeInt stek(nodeNum);
	ptr->status = 2;
	stek.push(ptr);

	while (!stek.isEmpty()) {
		ptr = stek.pop();
		ptr->status = trenstatus;

		LinkedEdgeInt* pedge = ptr->adj;
		while (pedge != nullptr) {
			if (pedge->dest->status == trenstatus)
				return true;
			else if (pedge->dest->status == 1) {
				pedge->dest->status = 2;
				stek.push(pedge->dest);
			}
			pedge = pedge->link;
		}
	}

}

bool GraphAsListsInt::daLiJeJakoPovezan()
{
	LinkedNodeInt* ptr = start;
	
	while (ptr != nullptr) {

		setStatusForAllNodes(1);
		if (nodeNum != dfsPretrage(ptr))
			return false;
		ptr = ptr->next;

	}
	return true;
}

bool GraphAsListsInt::dfsPretrage(LinkedNodeInt* ptr)
{
	int vrednost = 0;
	ptr->status = 2;
	StackAsArrayLinkedNodeInt stek(nodeNum);
	stek.push(ptr);

	while(!stek.isEmpty()) {

		ptr = stek.pop();
		ptr->status = 3;
		++vrednost;

		LinkedEdgeInt* pedge = ptr->adj;
		while (pedge != nullptr) {
			if (pedge->dest->status == 1) {

				pedge->dest->status = 2;
				stek.push(pedge->dest);
			}
			pedge = pedge->link;
		}
	}
	return vrednost;
}

bool GraphAsListsInt::pathExists(LinkedNodeInt* a, LinkedNodeInt* b, LinkedNodeInt* c, LinkedNodeInt* d)
{
	return dfsHelperObicanPut(a, b) && dfsHelperObicanPut(c, d);
}

bool GraphAsListsInt::dfsHelperObicanPut(LinkedNodeInt* a, LinkedNodeInt* b)
{
	setStatusForAllNodes(1);
	LinkedNodeInt* ptr = a;
	StackAsArrayLinkedNodeInt stek(nodeNum);
	stek.push(ptr);
	ptr->status = 2;

	while (!stek.isEmpty()) {

		ptr = stek.pop();
		ptr->status = 3;

		LinkedEdgeInt* pedge = ptr->adj;
		while (pedge != nullptr) {

			if (pedge->dest == b)
				return true;

			if (pedge->dest->status == 1) {
				pedge->dest->status = 2;
				stek.push(pedge->dest);
			}
			pedge = pedge->link;
		}
	}
	return false;
}

void GraphAsListsInt::conectGraph()
{
	LinkedNodeInt* ptr = start;
	LinkedNodeInt* ptr2 = start;

	while (!isConnected()) {			// izgleda ovo jebe

		ptr2 = ptr2->next;

		if (ptr2 == nullptr) {
			ptr = ptr->next;
			ptr2 = start;
		}

		if(ptr != ptr2)
			if (!egdeExists(ptr, ptr2))
				ptr->adj = new LinkedEdgeInt(ptr2, ptr->adj);
	}
}

bool GraphAsListsInt::egdeExists(LinkedNodeInt* a, LinkedNodeInt* b)
{
	LinkedEdgeInt* pedge = a->adj;
	while (pedge != nullptr) {

		if (pedge->dest == b)
			return true;
		pedge = pedge->link;
	}
	return false;
}

bool GraphAsListsInt::isConnected()
{
	return daLiJeJakoPovezan();			//ima vec napisano gore napisana funkcija;
}

int GraphAsListsInt::getMaxConnectionsDisjointSubgraph()
{
	uNeusmereni();
	setStatusForAllNodes(1);
	
	int maks = 0;
	LinkedNodeInt* ptr = start;
	
	while (ptr != nullptr) {
		
		if (ptr->status == 1)
			maks = max(maks, bfsHelperGrane(ptr));
		ptr = ptr->next;
	}
	return maks;

}

int GraphAsListsInt::bfsHelperGrane(LinkedNodeInt* ptr)
{
	int brojGrana = 0;
	QueueAsArrayLinkedNodeInt red(nodeNum);
	red.enqueue(ptr);
	ptr->status = 2;
	while (!red.isEmpty()) {
		ptr = red.dequeue();
		ptr->status = 3;
		
		LinkedEdgeInt* pedge = ptr->adj;
		while (pedge != nullptr) {

			if (pedge->dest->status == 1) {
				pedge->dest->status = 2;
				red.enqueue(pedge->dest);
			}
			brojGrana++;
			pedge = pedge->link;
		}
	}
	return brojGrana / 2;
}

int GraphAsListsInt::numOfSameFlights(LinkedNodeInt* airport1, LinkedNodeInt* airport2, LinkedNodeInt* airportEnd)
{
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr) {
		ptr->status = 0;
		ptr->prev = nullptr;
		ptr = ptr->next;
	}

	bfsHelper(airport1, airportEnd);

	// resetuj sve statuse
	setStatusForAllNodes(0);

	// vrati se po putanji prvog i stavi status na 10 (npr)
	ptr = airportEnd;
	while (ptr != nullptr) {
		ptr->status = 10;
		ptr = ptr->prev;
	}

	// resetuj prev pointer-e
	ptr = start;
	while (ptr != nullptr) {
		ptr->prev = nullptr;
		ptr = ptr->next;
	}

	bfsHelper(airport2, airportEnd);

	// prebroj koliko 11-ki ima po putanji airport2 -> airportEnd
	ptr = airportEnd;
	int brZajGrana = 0;
	while (ptr != nullptr) {
		if (ptr->status == 11)
			++brZajGrana;
		ptr = ptr->prev;
	}

	--brZajGrana; // -1 zato sto smo izbrojali cvorove a trebaju nam grane

	return brZajGrana;
}

void GraphAsListsInt::bfsHelper(LinkedNodeInt* ptr, LinkedNodeInt* ptrEnd)
{
	QueueAsArrayLinkedNodeInt red(nodeNum);

	// spec slucaj ako se putevi preklapaju
	if (ptr->status == 10)
		ptr->status = 11;

	red.enqueue(ptr);

	while (!red.isEmpty()) {

		ptr = red.dequeue();

		if (ptr->status != 11)
			ptr->status = 1;

		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {

			if (pEdge->dest->status == 0 || pEdge->dest->status == 10) {
				pEdge->dest->prev = ptr;

				if (pEdge->dest->status == 10)
					pEdge->dest->status = 11; // 11 znaci da je zajednicki cvor (posle samo izbrojimo klk ima 11-ke)

				red.enqueue(pEdge->dest);
			}

			if (pEdge->dest == ptrEnd) {
				pEdge->dest->prev = ptr;
				return;
			}

			pEdge = pEdge->link;
		}
	}
}

int GraphAsListsInt::reachalInNHoops(LinkedNodeInt* a, int n)
{
	LinkedNodeInt* ptr = a;

	QueueAsArrayLinkedNodeInt red(nodeNum);
	red.enqueue(ptr);
	int brDodatih = 1;
	int brNivoa = 0;

	while (!red.isEmpty()) {

		if (brDodatih == red.numberOfElements()) {
			if (brNivoa == n) {

				/*			ili ovako moze mnogo lakse jer je to prednost c++
				std::set<int> skup;
                while (!red.isEmpty())
                    skup.insert(red.dequeue()->node);

                return skup.size();
				*/

				int rez = 0;
				int brCvorova = red.numberOfElements();
				int* cvorovi = new int[red.numberOfElements()];

				for (int i = 0; i < brCvorova; i++)
					cvorovi[i] = red.dequeue()->node;

				for (int i = 0; i < brCvorova; i++) {
					bool imaGa = false;
					for (int j = i - 1; j >= 0; j--) 
						if (cvorovi[j] == cvorovi[i]) 
							imaGa = true;
					if (!imaGa)
						rez++;
				}
				delete[] cvorovi;
				return rez;
			}
			brNivoa++;
			brDodatih = 0;
		}

		ptr = red.dequeue();

		LinkedEdgeInt* pedge = ptr->adj;

		while (pedge != nullptr) {
			red.enqueue(pedge->dest);
			pedge = pedge->link;
		}
	}
}

int GraphAsListsInt::raachalInHoopsV2(LinkedNodeInt* a, int n)
{
	setStatusForAllNodes(0);

	LinkedNodeInt* ptr = a;

	QueueAsArrayLinkedNodeInt red(nodeNum);
	ptr->status = 10;
	red.enqueue(ptr);

	while (!red.isEmpty()) {

		ptr = red.dequeue();
		LinkedEdgeInt* pedge = ptr->adj;

		if (ptr->status == 10 + n) 
			break;

		while (pedge != nullptr) {
			pedge->dest->status = ptr->status + 1;
			red.enqueue(pedge->dest);
			pedge = pedge->link;
		}
	}

	int broj = 0;
	ptr = start;
	while (ptr != nullptr) {
		if (ptr->status == 10 + n)
			broj++;
		ptr = ptr->next;
	}
	return broj;
}
