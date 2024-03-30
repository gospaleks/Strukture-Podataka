#include "ElemCache.h"

ElemCache::ElemCache(int _maxCnt)
{
	maxCnt = _maxCnt;
	top = 0;
	head = nullptr;
	tail = nullptr;
}

ElemCache::~ElemCache()
{
	while (!isEmpty()) {
		int x = deleteFromTail();
	}
}

bool ElemCache::isEmpty() const
{
	return (top == 0);
}

void ElemCache::add(Elem* elem)
{
	// ako nema mesta obrisi sa tail-a
	if (top == maxCnt) {
		deleteFromTail();
	}

	if (isEmpty()) {
		head = elem;
		tail = head;
	}
	else {
		elem->next = head;
		head->prev = elem;
		head = elem;
	}

	++top;
}

Elem* ElemCache::get(int key)
{
	// mozda moze da se krene s obe strane i da bude malo brze
	Elem* tmp = head;
	while (tmp != nullptr && tmp->key != key)
		tmp = tmp->next;

	// ako nije nadjen
	if (tmp == nullptr)
		return nullptr;

	// spec slucaj ako je tail taj sto se trazi
	if (tmp->next == nullptr) {
		tail = tmp->prev;	// update tail-a
		tmp->prev->next = nullptr;
		tmp->prev = nullptr;
		tmp->next = head;
		head->prev = tmp;
		head = tmp;
	}
	// inace ako nije head prelancaj na pocetak
	else if (tmp != head) {
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		head->prev = tmp;
		tmp->next = head;
		tmp->prev = nullptr;
		head = tmp;
	}

	return head;
}

int ElemCache::deleteFromTail()
{
	if (isEmpty())
		throw std::exception("Lista je prazna.");

	int el;

	// 1 element u listi
	if (head == tail) {
		el = head->key;
		delete head;
		head = tail = nullptr;
	}
	// vise elemenata u listi
	else {
		Elem* tmp = tail;
		tail->prev->next = nullptr;
		tail = tail->prev;
		el = tmp->key;
		delete tmp;
	}

	--top;
	return el;
}

void ElemCache::printAll()
{
	if (isEmpty())
		return;

	Elem* tmp = head;
	while (tmp != nullptr) {
		std::cout << tmp->key << " ";
		tmp = tmp->next;
	}
	std::cout << '\n';
}
