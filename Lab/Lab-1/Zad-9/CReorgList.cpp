#include "CReorgList.h"

CReorgList::CReorgList()
{
	head = tail = nullptr;
}

CReorgList::~CReorgList()
{
	while (!IsEmpty()) {

		Node* tmp = head;
		head = head->next;
		delete tmp;

	}
}

bool CReorgList::IsEmpty() const
{
	return head == nullptr;
}

void CReorgList::AddToTail(int key)
{
	if (tail == nullptr)
		tail = head = new Node(key);
	else {
		tail->next = new Node(key);
		tail = tail->next;
	}
}

Node* CReorgList::GetToStart(int key)
{
	if (IsEmpty())
		return nullptr;

	// potreban i prev zbog prelancavanja
	Node* tmpPrev = nullptr;
	Node* tmp = head;
	while (tmp != nullptr && tmp->key != key) {
		tmpPrev = tmp;
		tmp = tmp->next;
	}

	// Ako je tmp nullptr znaci da element sa kljucem key ne postoji u listi
	if (tmp == nullptr)
		return tmp;
	
	// Ako je trazeni element bas prvi samo ga vrati
	if (tmpPrev == nullptr)
		return tmp;
	else  {
		// inace ga stavi na prvo mesto
		tmpPrev->next = tmp->next;
		tmp->next = head;
		head = tmp;
		return head;
	}
}

Node* CReorgList::GetTransp(int key)
{
	if (IsEmpty())
		return nullptr;

	// Ako je to bas prvi element
	if (head->key == key)
		return head;

	// Jedan element u listi
	if (head->next == nullptr)
		return nullptr;

	// Dva elementa u listi
	if (head->next->next == nullptr) {
		// Provera dal je drugi bas taj
		if (head->next->key == key) {
			Node* tmp = head;
			head = head->next;
			head->next = tmp;
			tmp->next = nullptr;
			return head;
		}
		else
			return nullptr;
	}

	// Tri ili vise elementa u listi
	Node* tmpPrev = nullptr;
	Node* tmp = head;
	while (tmp->next != nullptr && tmp->next->key != key) {
		tmpPrev = tmp;
		tmp = tmp->next;
	}

	// Ne postoji element u listi
	if (tmp->next == nullptr)
		return nullptr;

	// Ako prva dva treba da menjaju mesta (spec slucaj)
	// (ovo realno moze da se odradi i na pocetku pitas direktno dal je drugi i zameni ako treba)
	if (tmpPrev == nullptr) {
		head = tmp->next;
		Node* pom = tmp->next->next;
		tmp->next->next = tmp;
		tmp->next = pom;
		return head;
	}
	// opsti slucaj - menjaju mesto tmp i tmp->next
	else {
		tmpPrev->next = tmp->next;
		Node* pom = tmp->next->next;
		tmp->next->next = tmp;
		tmp->next = pom;
		return tmpPrev->next;
	}
}

void CReorgList::Print()
{
	Node* tmp = head;
	while (tmp != nullptr) {
		std::cout << tmp->key << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl;
}
