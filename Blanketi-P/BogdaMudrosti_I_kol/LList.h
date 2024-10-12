#pragma once
#include "LListNode.h"
class LList
{
protected:
	LListNode* head, * tail;
public:
	LList();
	~LList();
	bool isEmpty();
	void addToHead(int el);
	void addToTail(int el);
	int deleteFromHead();
	int deleteFromTail();
	LListNode* findNodePtr(int el);
	LListNode* getHead();
	LListNode* getNext(LListNode* ptr);
	int getHeadEl();
	int getNextEl(int el);
	void printAll();
	bool isInList(int el);
	void deleteEl(int el);
	LListNode* removeNodeFromHead();

	void umetanjeNaPocetak(int vrednost);
	void umetanjePosleZadatog(int vrednost, int posleKog);
	void umetanjeUSortiranuListu(int vrednost);
	void brisanjeSaPocetka();
	void brisanjeElemnta(int vrednost);
	void zameniElementISledeci(int vrednost);
	void staviNaPocetak(int vrednost);
	void staviSegmentNaPocetak(int vrednost1, int vrednost2);
	void inverSublist(int data1, int data2);
	void exchange(int data1, int data2);
	bool moveSectionToHead(int start, int end);
};

