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
	// Menja mesta na ptr i ptr->next
	// prev nam treba zbog prelancavanja

	if (prev == nullptr) {
		head = ptr->next;
		ptr->next = ptr->next->next;
		head->next = ptr;
	}
	else {
		prev->next = ptr->next;
		ptr->next = ptr->next->next;
		prev->next->next = ptr;
	}
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


/*
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

	// Nadji data2 (krece od ptr1 jer kaze sig je desno od njega)
	LLNode* ptr2 = ptr1;
	while (ptr2 != nullptr && ptr2->info != data2)
		ptr2 = ptr2->next;

	// Ako ne nadje jedan od ova dva elementa obustavi
	if (ptr1 == nullptr || ptr2 == nullptr)
		return;

	while (ptr1 != ptr2)
	{
		// Unutrasnja while petlja istiskuje prvi na zadnje mesto
		// Znaci kao u bubble sort menjaju se mesta na svaka dva
		// Kad se to ponovi n puta (tj kad dodjemo do ptr2) podlista je okrenuta

		// Posle jedne iteracija unutrasnje while petlje lista je: 1 2 3 5 6 7 8 4 9 0
		// Pa se onda 5 istisne do 4 i tako u svaki prolaz sve manje i manje	

		// Odkomentarisi printAll() i vidi se ponasanje kroz svaku iteraciju

		LLNode* tmp = ptr1;
		LLNode* tmpPrev = prev1;

		while (tmpPrev != ptr2)
		{

			swap(tmp, tmpPrev);

			// printAll();

			// ovo je samo spec slucaj kad podlista pocinje od prvog elementa
			if (tmpPrev == nullptr) tmpPrev = head;
			else tmpPrev = tmpPrev->next;
		}

		// isto spec slucaj kad podlista pocinje od prvog elementa
		if (prev1 == nullptr) ptr1 = head;
		else ptr1 = prev1->next;
	}
*/


}
