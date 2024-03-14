#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = nullptr;
}

LinkedList::~LinkedList()
{
	while (!isEmpty())
		int el = deleteFromHead();
}

inline bool LinkedList::isEmpty()
{
	return (head == nullptr);
}

int LinkedList::deleteFromHead()
{
	if (isEmpty())
		throw std::exception("Lista je prazna.");

	Node* tmp = head;
	int el = tmp->info;
	head = head->next;
	delete tmp;
	return el;
}

void LinkedList::addToHead(int el)
{
	head = new Node(el, head);
}

void LinkedList::printAll()
{
	Node* tmp = head;
	while (tmp != nullptr) {
		tmp->print();
		tmp = tmp->next;
	}

	std::cout << std::endl;
}

bool LinkedList::deleteSublist(LinkedList* sublist)
{
	int brElSublist = 0;
	Node* tmp = sublist->head;
	while (tmp != nullptr) {
		++brElSublist;
		tmp = tmp->next;
	}

	Node* tmpPrev = nullptr;
	tmp = head;
	while (tmp != nullptr) {

		Node* tmpSublist = sublist->head;
		Node* tmpMainList = tmp;

		// Ova petlja pronalazi sublist i ako ima ok ostaje na true
		bool ok = true;
		while (tmpMainList != nullptr && tmpSublist != nullptr && ok) {

			if (tmpMainList->info != tmpSublist->info)
				ok = false;

			tmpMainList = tmpMainList->next;
			tmpSublist = tmpSublist->next;
		}

		// ako je naso onda je tmpSublist izaso iz subliste tj ukazuje na nullptr
		// onda obrisi podlistu
		if (ok && tmpSublist == nullptr) {
			deleteFrom(tmpPrev, brElSublist);
			if (tmpPrev == nullptr)
				tmp = head;
			else
				tmp = tmpPrev->next;
		}
		// inace predji na sledeci element od koga pocinje da se trazi podlista
		else  {
			tmpPrev = tmp;
			tmp = tmp->next;
		}
	}

	return true;
}

void LinkedList::deleteFrom(Node* prev, int brEl)
{
	int br = 0;
	Node* curr;
	Node* next;

	if (prev == nullptr)
		curr = head;
	else
		curr = prev->next;


	while (br < brEl) {
		next = curr->next;
		delete curr;
		curr = next;
		++br;
	}

	if (prev == nullptr)
		head = curr;
	else
		prev->next = curr;
}
