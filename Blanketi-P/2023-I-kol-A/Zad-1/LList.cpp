#include "LList.h"


// TODO: SwapPairs(int, int);
int LList::SwapPairs(int data1, int data2)
{
	if (isEmpty())
		return 0;

	LListNode* prev1 = nullptr;
	LListNode* ptr1 = head;

	// za pronalazak ne korisitim findNodePtr() jer ona uvek ide od pocetak
	// a za to nema potrebe jer je ptr1 levo od ptr2
	// i plus mi treba previos od ptr1
	while (ptr1 != nullptr && !ptr1->isEqual(data1)) {
		prev1 = ptr1;
		ptr1 = ptr1->next;
	}

	LListNode* ptr2 = ptr1;
	while (ptr2 != nullptr && !ptr2->isEqual(data2)) {
		ptr2 = ptr2->next;
	}

	// ako je neki od ova dva nullptr znaci da lista ne postoji
	if (ptr1 == nullptr && ptr2 == nullptr)
		return 0;

	int num = 0;
	while (ptr1 != ptr2 && ptr1->next != nullptr) {

		// spec slucaj kad podlista pocinje od prvog elementa
		if (prev1 == nullptr) {
			head = head->next;
			ptr1->next = ptr1->next->next;
			head->next = ptr1;
		}
		// inace zamena unutrasnja dva
		else {
			prev1->next = ptr1->next;
			LListNode* pom = ptr1->next;
			ptr1->next = ptr1->next->next;
			pom->next = ptr1;
		}

		// predji na sledeci par
		prev1 = ptr1;
		ptr1 = ptr1->next;

		++num;
	}

	return num;
}



LList::LList()
{
	head = NULL;
	tail = NULL;
}


LList::~LList()
{
	while(!isEmpty())
	{
		int tmp = deleteFromHead();
	}
}


bool LList::isEmpty()
{
	return head==NULL;
}

void LList::addToHead(int el)
{
	head = new LListNode(el, head);
}

void LList::addToTail(int el)
{
	if(!isEmpty())
	{
		LListNode* tmp = head;
		while(tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new LListNode(el);
	}
	else
		addToHead(el);
}

int LList::deleteFromHead()
{
	if(isEmpty())
		throw new exception("List is empty");
	int el = head->info;
	LListNode *tmp = head;
	head = head->next;
	delete tmp;
	return el;
}

int LList::deleteFromTail()
{
	if(isEmpty())
		throw new exception("List is empty");
	int el;
	if (head->next == NULL)
	{
		el = head->info;
		delete head;
		head = NULL;
	}
	else
	{
		LListNode* prev = head;
		LListNode *tmp = head;
		while (tmp->next != NULL)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		el = tmp->info;
		delete tmp;
		prev->next = NULL;
	}
	return el;
}

LListNode* LList::findNodePtr(int el)
{
	if(isEmpty())
		throw new exception("List is empty");
	LListNode *ret = head;
	while(ret!=NULL && ret->info!=el)
	{
		ret = ret->next;
	}
	return ret;
}

LListNode* LList::getHead()
{
	return head;
}

LListNode* LList::getNext(LListNode* ptr)
{
	if(isEmpty())
		throw new exception("List is empty");
	return ptr->next;
}

int LList::getHeadEl()
{
	if(isEmpty())
		throw new exception("List is empty");
	return head->info;
}

int LList::getNextEl(int el)
{
	if(isEmpty())
		throw new exception("List is empty");
	LListNode* tmp = findNodePtr(el);
	if(tmp==NULL)
		throw new exception("Node doesn't exist");
	if(tmp->next == NULL)
		throw new exception("Element doesn't have next node");
	return tmp->next->info;
}

void LList::printAll()
{
	LListNode *tmp = head;
	while(tmp!=NULL)
	{
		cout<<tmp->print() << " ";
		tmp=tmp->next;
	}
	cout << endl;
}

bool LList::isInList(int el)
{
	if(isEmpty())
		return false;
	LListNode* tmp = findNodePtr(el);
	if(tmp==NULL)
		return false;
	else
		return true;
}

void LList::deleteEl(int el)
{
	if (!isEmpty())
	if (head->isEqual(el)) 
	{
		LListNode *tmp = head;
		head = head->next;
		delete tmp;
	}
	else 
	{
		LListNode *pred, *tmp; 
		for (pred = head, tmp = head->next; tmp != NULL && !(tmp->isEqual(el));
			  pred = pred->next, tmp = tmp->next);
		if (tmp != NULL) 
		{
			pred->next = tmp->next;
			delete tmp;
		}
    }
}

LListNode* LList::removeNodeFromHead()
{
	if(isEmpty())
		return NULL;
	LListNode *tmp = head;
	head = head->next;
	return tmp;
}
