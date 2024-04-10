#include "LList.h"

LList::LList()
{
	head = tail = nullptr;
}

LList::~LList()
{
	while (!isEmpty())
		int el = deleteFromHead();
}

bool LList::isEmpty()
{
	return (head == nullptr);
}

int LList::deleteFromHead()
{
	if (isEmpty())
		throw std::exception("Lista je prazna.");

	LLNode* tmp = head;
	int el = tmp->info;

	if (head == tail)
		head = tail = nullptr;
	else
		head = head->next;
	
	delete tmp;

	return el;
}

int LList::deleteFromTail()
{
	if (isEmpty())
		throw std::exception("Lista je prazna.");

	int el = tail->info;
	LLNode* forDel = tail;
	
	if (head == tail)
		head = tail = nullptr;
	else {
		LLNode* pred = head;
		while (pred->next != tail)
			pred = pred->next;

		tail = pred;
		tail->next = nullptr;
	}

	delete forDel;
	return el;
}

void LList::addToHead(int el)
{
	head = new LLNode(el, head);
	if (tail == nullptr)
		tail = head;
}

void LList::addToTail(int el)
{
	if (isEmpty())
		head = tail = new LLNode(el);
	else
	{
		tail->next = new LLNode(el);
		tail = tail->next;
	}
}

void LList::printAll()
{
	LLNode* tmp = head;
	while (tmp != nullptr) {
		std::cout << tmp->info << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl;
}

void LList::swap(LLNode* ptr, LLNode* prev)
{
	// ne treba
}

void LList::invertSublist(int data1, int data2)
{
	/*
		ulaz:	 1 2 3 4 5 6 7 8 9 0	data1 = 4, data2 = 8
		izlaz:	 1 2 3 8 7 6 5 4 9 0
	*/

	// Ako je prazna lista ili ima samo jedan element 
	// ili je podlista od jednog elementa obustavi obradu
	if (isEmpty() || head == tail || data1 == data2)
		return;

	// Nadji data1
	LLNode* prev1 = nullptr;
	LLNode* ptr1 = head;
	while (ptr1 != nullptr && ptr1->info != data1)
	{
		prev1 = ptr1;
		ptr1 = ptr1->next;
	}

	// Nadji data2
	LLNode* prev2 = prev1;
	LLNode* ptr2 = ptr1;
	while (ptr2 != nullptr && ptr2->info != data2)
	{
		prev2 = ptr2;
		ptr2 = ptr2->next;
	}

	// Ako jedan nije nadjen obustavi
	if (ptr1 == nullptr || ptr2 == nullptr)
		return;

	LLNode* current = ptr1->next;

	// Prelancavanje prvog i zadnjeg u podlisti
	
	// Spec slucaj ako podlista pocinje od glave
	if (prev1 == nullptr)
		head = ptr2;
	else
		prev1->next = ptr2;

	ptr1->next = ptr2->next;
	ptr2->next = prev2;
	
	// Prelancaj unazad sve izmedju prvog i zadnjeg
	LLNode* next = current;
	LLNode* prev = ptr1;
	while (next != ptr2) {
		next = current->next;
		current->next = prev;
		
		prev = current;
		current = next;
	}

	/* Davidovicev nacin */

	/*
	 	if (isEmpty() || head == tail || data1 == data2)
			return;
	
		LLNode* insert;
		if (head->info != data1)
		{
			insert = head;
			while (insert->next != nullptr && insert->next->info != data1)
				insert = insert->next;
	
			if (insert->next == nullptr) return;	// ako ga prvi nema
		}
		else {
			insert = head;
		}
	
		LLNode* ptr2 = insert->next;
		while (ptr2 != nullptr && ptr2->info != data2)
			ptr2 = ptr2->next;
	
		if (ptr2 == nullptr) return;	// ako ga drugi nema
		
		if (insert == head) insert = nullptr;
	
		LLNode* tmpPrev;
		LLNode* tmp;
		if (insert == nullptr) {
			tmpPrev = head;
			tmp = head->next;
		}
		else {
			tmpPrev = insert->next;
			tmp = insert->next->next;
		}
	
		while (tmp != ptr2) {
	
			tmpPrev->next = tmp->next;
	
			if (insert == nullptr) {
				tmp->next = head;
				head = tmp;
			}
			else  {
				tmp->next = insert->next;
				insert->next = tmp;
			}
	
			tmp = tmpPrev->next;
		}
		
		tmpPrev->next = tmp->next;
		if (insert == nullptr) {
			tmp->next = head;
			head = tmp;
		}
		else {
			tmp->next = insert->next;
			insert->next = tmp;
		}
 	*/
	
}
